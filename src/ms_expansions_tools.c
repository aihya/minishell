/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expansions_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 20:11:16 by aihya             #+#    #+#             */
/*   Updated: 2019/06/30 22:10:08 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ms_set_quote(int *quoted, char *quote, char c)
{
	if (c == SQUOTE && (*quoted) == FALSE)
	{
		(*quoted) = TRUE;
		(*quote) = c;
	}
	else if (c == SQUOTE && (*quoted) == TRUE && (*quote) == SQUOTE)
	{
		(*quoted) = FALSE;
		(*quote) = 0;
	}
	else if (c == DQUOTE && (*quoted) == FALSE)
	{
		(*quoted) = TRUE;
		(*quote) = c;
	}
	else if (c == DQUOTE && (*quoted) == TRUE && (*quote) == DQUOTE)
	{
		(*quoted) = FALSE;
		(*quote) = 0;
	}
}

char	*ms_expand_quotes(char *arg)
{
	int		i;
	int		quoted;
	char	quote;
	char	*result;

	result = ft_strnew(0);
	quoted = FALSE;
	quote = 0;
	i = 0;
	while (arg[i])
	{
		ms_set_quote(&quoted, &quote, arg[i]);
		if (quoted == FALSE && ft_strchr("\'\"", arg[i]))
			i++;
		else if (arg[i] != quote)
			ft_strappend(&result, arg[i++], TRUE);
		else
			i++;
	}
	return (result);
}

int		ms_expand_dollar(char **buffer, char *arg, t_env *env)
{
	int		i;
	char	*var_name;
	t_env	*node;

	var_name = ft_strnew(0);
	i = 0;
	while (arg[i] && ft_strchr(ALNUM, arg[i]))
	{
		ft_strappend(&var_name, arg[i], TRUE);
		i++;
	}
	if ((node = ms_get_var(var_name, env)))
	{
		ft_strojoin(buffer, node->value, TRUE);
		ms_free_node(&node);
	}
	free(var_name);
	return (i);
}

char	*ms_expand_dollars(char *arg, t_env *env)
{
	int		i;
	int		quoted;
	char	quote;
	char	*result;

	result = ft_strnew(0);
	quoted = FALSE;
	i = 0;
	while (arg[i])
	{
		ms_set_quote(&quoted, &quote, arg[i]);
		if (arg[i] == DOLLAR)
		{
			if ((quoted == TRUE && quote == DQUOTE) || (quoted == FALSE))
			{
				i++;
				i += ms_expand_dollar(&result, arg + i, env);
				continue ;
			}
		}
		ft_strappend(&result, arg[i], TRUE);
		i++;
	}
	return (result);
}

char	*ms_expand_tilde(char *arg, t_env *env)
{
	char	*result;
	char	*value;
	t_env	*node;

	result = ft_strnew(0);
	if (arg[0] == TILDE)
	{
		if ((node = ms_get_var("HOME", env)))
		{
			value = ft_strdup(node->value);
			ft_strojoin(&result, value, TRUE);
			free(value);
		}
		ft_strojoin(&result, arg + 1, TRUE);
		return (result);
	}
	free(result);
	result = ft_strdup(arg);
	return (result);
}
