/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_begins_with.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:18:40 by aihya             #+#    #+#             */
/*   Updated: 2018/10/28 16:20:51 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_begins_with(const char *haystack, const char *needle)
{
	size_t	i;

	if (ft_strlen(haystack) >= ft_strlen(needle))
	{
		i = 0;
		while ((haystack[i] == needle[i]))
			i++;
		if (i == ft_strlen(needle))
			return (1);
		return (0);
	}
	return (-1);
}
