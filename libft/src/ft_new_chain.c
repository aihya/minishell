/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_chain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 01:14:54 by aihya             #+#    #+#             */
/*   Updated: 2019/01/30 09:23:39 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_new_chain(char **base)
{
	int		i;
	char	**new_chain;

	i = 0;
	if (base)
	{
		new_chain = (char **)malloc(sizeof(char *) * (ft_chain_size(base) + 1));
		while (base[i])
		{
			new_chain[i] = ft_strdup(base[i]);
			i++;
		}
	}
	else
		new_chain = (char **)malloc(sizeof(char *));
	new_chain[i] = ft_strdup("\0");
	return (new_chain);
}
