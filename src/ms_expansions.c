/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expansions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 19:23:58 by aihya             #+#    #+#             */
/*   Updated: 2019/06/30 22:09:18 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ms_expand_arg(char *arg, t_env *env)
{
	char	*result;
	char	*tmp;

	result = ms_expand_tilde(arg, env);
	tmp = ft_strdup(result);
	free(result);
	result = ms_expand_dollars(tmp, env);
	free(tmp);
	tmp = ft_strdup(result);
	free(result);
	result = ms_expand_quotes(tmp);
	free(tmp);
	return (result);
}

char	**ms_expand_args(char **args, t_env *env)
{
	char	**buffer;
	char	*tmp;
	int		i;

	tmp = NULL;
	buffer = NULL;
	i = 0;
	while (args[i])
	{
		tmp = ms_expand_arg(args[i], env);
		ft_chain_push(&buffer, tmp);
		free(tmp);
		i++;
	}
	return (buffer);
}
