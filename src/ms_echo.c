/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 14:55:45 by aihya             #+#    #+#             */
/*   Updated: 2019/06/28 16:33:22 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ms_echo(char **args)
{
	int		i;
	size_t	size;
	int		newline;

	size = ft_chain_size(args + 1);
	newline = 1;
	i = 1;
	if (size > 1 && ft_strequ("-n", args[i]))
	{
		newline = 0;
		i++;
	}
	while (args[i])
	{
		ft_putstr(args[i]);
		if ((size_t)i < size)
			ft_putchar(' ');
		i++;
	}
	if (newline == 1)
		ft_putchar('\n');
	return (OK);
}
