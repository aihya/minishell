/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 17:06:33 by aihya             #+#    #+#             */
/*   Updated: 2019/06/30 22:09:47 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ms_error(char *cmd, char *msg, int newline)
{
	if (cmd)
	{
		ft_putstr(cmd);
		ft_putstr(": ");
	}
	if (newline)
		ft_putendl(msg);
	else
		ft_putstr(msg);
}

int		ms_get_input(char **buffer, int last_status, t_lst **list)
{
	int		ret;

	ms_prompt(last_status);
	if ((ret = get_next_line(0, buffer, list)) == 0)
		ft_putendl("\n");
	return (ret);
}
