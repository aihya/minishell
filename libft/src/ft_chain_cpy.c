/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chain_cpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 03:02:22 by aihya             #+#    #+#             */
/*   Updated: 2019/04/26 16:15:40 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_chain_cpy(char **chain)
{
	char	**new;
	size_t	i;

	if (chain == NULL)
		return (NULL);
	i = 0;
	new = (char **)malloc(sizeof(char *) * (ft_chain_size(chain) + 1));
	while (chain[i])
	{
		new[i] = ft_strdup(chain[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}
