/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 23:08:03 by aihya             #+#    #+#             */
/*   Updated: 2019/06/28 16:32:48 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ms_is_builtin(char *name)
{
	if (ft_strequ(name, "exit"))
		return (EXIT);
	else if (ft_strequ(name, "echo"))
		return (ECHO);
	else if (ft_strequ(name, "env"))
		return (ENV);
	else if (ft_strequ(name, "setenv"))
		return (SETENV);
	else if (ft_strequ(name, "unsetenv"))
		return (UNSETENV);
	else if (ft_strequ(name, "cd"))
		return (CD);
	return (FALSE);
}

int	ms_exec_builtin(int function, char **args, t_env **env)
{
	if (function == EXIT)
		return (EXIT);
	else if (function == ENV)
		return (ms_env(*env));
	else if (function == UNSETENV)
		return (ms_unsetenv(args, env));
	else if (function == SETENV)
		return (ms_setenv(args, env));
	else if (function == ECHO)
		return (ms_echo(args));
	else if (function == CD)
		return (ms_cd(args, env));
	return (NOK);
}
