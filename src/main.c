/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 10:18:31 by aihya             #+#    #+#             */
/*   Updated: 2019/07/09 14:07:49 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ms_basename(char *str)
{
	char	**buffer;
	char	*basename;

	buffer = ft_strsplit_del(str, "/");
	if (ft_chain_size(buffer) > 0)
		basename = ft_strdup(buffer[ft_chain_size(buffer) - 1]);
	else
		basename = ft_strdup(str);
	ft_chain_free(&buffer);
	return (basename);
}

void	ms_prompt(int status)
{
	char *path;
	char *basename;

	if (g_var == 0)
	{
		ft_putstr("\033[1;30m");
		path = getcwd(NULL, MAXPATHLEN);
		basename = ms_basename(path);
		ft_putstr(basename);
		status ? ft_putstr(" \033[1;36m") : ft_putstr(" \033[1;31m");
		ft_putstr("\u279C  \033[1;37m");
		free(path);
		free(basename);
	}
	g_var = 0;
}

int		ms_execute(char **args, t_env **env)
{
	int function;

	if ((function = ms_is_builtin(args[0])))
		return (ms_exec_builtin(function, args, env));
	return (ms_exec_non_builtin(args, env));
}

void	ms_loop(t_env **env, int status, char *line)
{
	char	**args;
	t_lst	*list;

	list = NULL;
	while (TRUE)
	{
		if (ms_get_input(&line, status, &list) == 0)
			continue ;
		g_var = 0;
		if (line && (status = ms_check_input(line, status)) == OK)
		{
			if ((args = ms_parse(line, *env)) != NULL)
			{
				if (ft_chain_size(args) >= 1)
					if ((status = ms_execute(args, env)) == EXIT)
						break ;
				ft_chain_free(&args);
			}
		}
		free(line);
	}
	ft_chain_free(&args);
	free_gnl_nodes(&list);
	free(line);
}

int		main(int ac, char **av, char **ev)
{
	t_env	*env;
	int		status;
	char	*line;

	status = OK;
	line = NULL;
	signal(SIGINT, signal_handler);
	g_var = 0;
	(void)ac;
	(void)av;
	env = ms_init_env(ev);
	ms_loop(&env, status, line);
	ms_free_env(&env);
	return (0);
}
