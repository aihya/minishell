/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 18:22:32 by aihya             #+#    #+#             */
/*   Updated: 2019/06/30 22:09:04 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ms_quote_content(char *str)
{
	int		i;
	char	quote;
	char	*content;

	i = 0;
	quote = str[0];
	content = ft_strnew(0);
	while (str[i])
	{
		if (str[i] == quote && i != 0)
			break ;
		ft_strappend(&content, str[i], TRUE);
		i++;
	}
	return (content);
}

char	*ms_get_arg(char *line)
{
	int		i;
	char	*arg;
	char	*quote_content;

	i = 0;
	arg = ft_strnew(0);
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t')
			break ;
		if (line[i] == DQUOTE || line[i] == SQUOTE)
		{
			quote_content = ms_quote_content(line + i);
			ft_strojoin(&arg, quote_content, TRUE);
			i = i + ft_strlen(quote_content);
			free(quote_content);
			ft_strappend(&arg, line[i], TRUE);
		}
		else
			ft_strappend(&arg, line[i], TRUE);
		i++;
	}
	return (arg);
}

char	**ms_parse(char *line, t_env *env)
{
	int		i;
	char	**buffer;
	char	**args;
	char	*arg;

	i = 0;
	while (line[i] != '\0' && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (!(buffer = NULL) && line[i] && (i--) != -1)
	{
		while (line[++i])
		{
			if (line[i] != ' ' && line[i] != '\t')
			{
				arg = ms_get_arg(line + i);
				ft_chain_push(&buffer, arg);
				i = i + ft_strlen(arg) - 1;
				free(arg);
			}
		}
		args = ms_expand_args(buffer, env);
		ft_chain_free(&buffer);
		return (args);
	}
	return (NULL);
}
