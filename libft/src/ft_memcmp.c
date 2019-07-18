/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 20:29:49 by aihya             #+#    #+#             */
/*   Updated: 2018/10/28 15:26:06 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_cpy;
	unsigned char	*s2_cpy;
	unsigned int	pos;

	s1_cpy = (unsigned char *)s1;
	s2_cpy = (unsigned char *)s2;
	pos = 0;
	while (pos < (unsigned int)n)
	{
		if (*s1_cpy++ != *s2_cpy++)
			return (*(s1_cpy - 1) - *(s2_cpy - 1));
		pos++;
	}
	return (0);
}
