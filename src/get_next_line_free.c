/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 14:55:59 by aihya             #+#    #+#             */
/*   Updated: 2019/06/28 16:31:31 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

void	free_gnl_nodes(t_lst **nodes)
{
	t_lst	*curr;
	t_lst	*next;

	curr = *nodes;
	while (curr)
	{
		free(curr->content);
		next = curr->next;
		free(curr);
		curr = next;
	}
}

void	lstadd(t_lst **alst, t_lst *new)
{
	(*new).next = *alst;
	*alst = new;
}
