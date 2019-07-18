/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 19:11:28 by aihya             #+#    #+#             */
/*   Updated: 2018/11/04 00:43:20 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new_str;

	if (!(new_str = (char *)malloc(size + 1)))
		return (NULL);
	ft_bzero((void *)new_str, size + 1);
	return ((char *)new_str);
}
