/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_feed_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 12:58:22 by aihya             #+#    #+#             */
/*   Updated: 2019/06/30 22:09:14 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ms_check_quote(char *str, int pos)
{
	int		c;

	if (pos == 0)
		return (OK);
	c = 0;
	while (pos >= 0 && str[pos - 1] == '\\')
	{
		c++;
		pos--;
	}
	if (c % 2 == 0)
		return (OK);
	return (NOK);
}

void	ms_quote_unmatched_err(char quote)
{
	char	*tmp;

	tmp = ft_strdup("Unmatched ");
	ft_strappend(&tmp, quote, TRUE);
	ms_error("ms", tmp, TRUE);
	ft_strclr(tmp);
	free(tmp);
}

int		ms_check_quotes(char *str)
{
	int		i;
	char	target;

	i = 0;
	while (str[i])
	{
		if ((str[i] == DQUOTE || str[i] == SQUOTE)
			&& ms_check_quote(str, i) && (target = str[i])
			&& (++i))
		{
			while (str[i])
			{
				if (str[i] == target && ms_check_quote(str, i))
					break ;
				i++;
			}
			if (str[i] == target && ++i)
				continue;
			ms_quote_unmatched_err(target);
			return (NOK);
		}
		i++;
	}
	return (OK);
}

int		ms_check_last_bslash(char *str)
{
	int		i;
	int		c;
	size_t	str_size;

	str_size = ft_strlen(str);
	if (str_size == 0)
		return (OK);
	i = str_size - 1;
	if (str[i] == '\\')
	{
		c = 0;
		while ((i >= 0 && str[i] == '\\'))
		{
			i--;
			c++;
		}
		if (c % 2 == 0)
			return (OK);
		return (INCOMPLETE);
	}
	return (OK);
}

int		ms_check_input(char *line, int prev_status)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t')
			break ;
		i++;
	}
	if (line[i] == '\0')
		return (prev_status);
	return (ms_check_quotes(line));
}
