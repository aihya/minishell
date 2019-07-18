/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_non_builtins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:50:00 by aihya             #+#    #+#             */
/*   Updated: 2019/06/30 22:09:10 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ms_command_not_found(char *command)
{
	ms_error("ms", COMMAND_NF, FALSE);
	ft_putstr(": ");
	ft_putendl(command);
	return (NOK);
}

int	ms_get_bin_path(char **buffer, char **path_items, char *binary)
{
	int		i;
	char	*tmp;

	i = 0;
	while (path_items[i])
	{
		tmp = ft_strsjoin(path_items[i], binary, "/");
		if (access(tmp, F_OK) == 0 && ms_path_accessible(tmp) == NOK)
		{
			free(tmp);
			return (NOK);
		}
		else if (access(tmp, F_OK) == 0)
			break ;
		free(tmp);
		i++;
	}
	if ((size_t)i == ft_chain_size(path_items))
		return (ms_command_not_found(binary));
	*buffer = tmp;
	return (OK);
}

int	ms_fork(char *bin_path, char **args, char **envp)
{
	int		stat_loc;
	pid_t	pid;

	stat_loc = 0;
	pid = fork();
	if (pid == 0)
	{
		execve(bin_path, args, envp);
		exit(1);
	}
	else if (pid > 0)
	{
		wait(&stat_loc);
		if (stat_loc != 0)
			return (NOK);
		return (OK);
	}
	else
	{
		ms_error("ms", FORK_UNABLE, TRUE);
		return (NOK);
	}
	return (OK);
}

int	ms_exam_path(char **args, char ***path_items, char **bin_path, t_env *env)
{
	t_env	*node;

	if (ft_strchr(args[0], '/') == NULL)
	{
		if ((node = ms_get_var("PATH", env)))
		{
			*path_items = ft_strsplit_del(node->value, ":");
			ms_free_node(&node);
		}
		if (*path_items == NULL)
			return (ms_command_not_found(args[0]));
		else if (ms_get_bin_path(bin_path, *path_items, args[0]) == NOK)
		{
			free(*bin_path);
			ft_chain_free(path_items);
			return (NOK);
		}
	}
	else if (ms_path_exist(args[0]) == NOK || ms_is_executable(args[0]) == NOK)
		return (NOK);
	else
		*bin_path = ft_strdup(args[0]);
	return (OK);
}

int	ms_exec_non_builtin(char **args, t_env **env)
{
	char	**path_items;
	char	*bin_path;
	char	**envp;
	int		fork_responce;

	bin_path = NULL;
	path_items = NULL;
	if (ms_exam_path(args, &path_items, &bin_path, *env) == NOK)
		return (NOK);
	envp = ms_env_to_array(*env);
	fork_responce = ms_fork(bin_path, args, envp);
	ft_chain_free(&envp);
	ft_chain_free(&path_items);
	free(bin_path);
	return (fork_responce);
}
