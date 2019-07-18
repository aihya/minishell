/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 20:07:32 by aihya             #+#    #+#             */
/*   Updated: 2018/10/28 15:23:40 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char const *s)
{
	char	*s_rev;
	int		i;

	if (!s || !(s_rev = (char *)malloc(sizeof(char) * ((int)ft_strlen(s) + 1))))
		return (NULL);
	i = (int)ft_strlen(s);
	while (i)
	{
		s_rev[(int)ft_strlen(s) - i] = s[i - 1];
		i--;
	}
	s_rev[ft_strlen(s)] = '\0';
	return (s_rev);
}
