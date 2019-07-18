/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chain.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <abdechahid.ihya@hotmail.c>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:19:42 by aihya             #+#    #+#             */
/*   Updated: 2019/05/03 20:38:03 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_chain(char ***a_chain, char *del)
{
	char	**chain;
	size_t	i;

	if (a_chain == NULL)
		return ;
	chain = *a_chain;
	i = 0;
	while (chain[i])
	{
		ft_putstr(chain[i]);
		ft_putstr(del);
		i++;
	}
}
