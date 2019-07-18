/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 14:36:53 by aihya             #+#    #+#             */
/*   Updated: 2019/06/30 22:09:36 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ms_cd(char **args, t_env **env)
{
	char	*path;
	size_t	size;

	if ((size = ft_chain_size(args)) == 1)
		return (ms_go_home(env));
	else if (size > 2)
	{
		ms_error("cd", TOO_MANY_ARGS, TRUE);
		return (NOK);
	}
	else
	{
		path = args[1];
		if (ft_strlen(path) == 1)
		{
			if (*path == '~')
				return (ms_go_home(env));
			if (*path == '-')
				return (ms_go_back(env));
		}
		if (ms_check_path(path) == NOK)
			return (NOK);
		ms_move_to(path, env);
	}
	return (OK);
}
