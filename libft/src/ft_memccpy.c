/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 19:50:05 by aihya             #+#    #+#             */
/*   Updated: 2018/10/28 15:25:57 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	c_c;
	unsigned char	*dst_c;
	unsigned char	*src_c;

	if (n)
	{
		c_c = (unsigned char)c;
		dst_c = (unsigned char *)dst;
		src_c = (unsigned char *)src;
		while (n--)
		{
			if ((*dst_c++ = *src_c++) == c_c)
				return (dst_c);
		}
	}
	return (NULL);
}
