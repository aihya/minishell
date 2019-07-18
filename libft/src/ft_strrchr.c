/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 23:56:01 by aihya             #+#    #+#             */
/*   Updated: 2018/10/28 15:34:57 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		pos;
	char	conv_c;

	i = 0;
	pos = -1;
	conv_c = (char)c;
	if (conv_c == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[i] != '\0')
	{
		if (s[i] == conv_c)
			pos = i;
		i++;
	}
	if (pos == -1)
		return (NULL);
	return ((char *)s + (pos));
}
