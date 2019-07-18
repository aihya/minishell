/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 21:50:41 by aihya             #+#    #+#             */
/*   Updated: 2018/10/28 16:18:28 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*new;
	unsigned int	index;

	if (!s || !(new = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	index = 0;
	while (s[index])
	{
		new[index] = f(s[index]);
		index++;
	}
	new[index] = 0;
	return (new);
}
