/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 17:03:02 by aihya             #+#    #+#             */
/*   Updated: 2019/06/28 17:13:07 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ms_move_to(char *path, t_env **env)
{
	char	**args;
	char	*full_path;

	full_path = getcwd(NULL, MAXPATHLEN);
	args = (char **)malloc(sizeof(char *) * 4);
	args[0] = ft_strdup("Glitch, YeS ThAt's mE");
	args[1] = ft_strdup("OLDPWD");
	args[2] = ft_strdup(full_path);
	args[3] = NULL;
	ms_setenv(args, env);
	free(full_path);
	ft_chain_free(&args);
	chdir(path);
	full_path = getcwd(NULL, MAXPATHLEN);
	args = (char **)malloc(sizeof(char *) * 4);
	args[0] = ft_strdup("Glitch, YeS ThAt's mE");
	args[1] = ft_strdup("PWD");
	args[2] = ft_strdup(full_path);
	args[3] = NULL;
	ms_setenv(args, env);
	free(full_path);
	ft_chain_free(&args);
}

int		ms_go_back(t_env **env)
{
	t_env	*node;

	if ((node = ms_get_var("OLDPWD", *env)))
	{
		ms_move_to(node->value, env);
		ms_free_node(&node);
		return (OK);
	}
	return (NOK);
}

int		ms_go_home(t_env **env)
{
	t_env	*node;

	if ((node = ms_get_var("HOME", *env)))
	{
		ms_move_to(node->value, env);
		ms_free_node(&node);
		return (OK);
	}
	return (NOK);
}
