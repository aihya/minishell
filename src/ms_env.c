/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 12:35:09 by aihya             #+#    #+#             */
/*   Updated: 2019/06/28 16:52:31 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ms_env(t_env *env)
{
	t_env	*curr;

	curr = env;
	while (curr)
	{
		ft_putstr(curr->name);
		ft_putchar('=');
		ft_putendl(curr->value);
		curr = curr->next;
	}
	return (OK);
}
