/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 16:16:19 by aihya             #+#    #+#             */
/*   Updated: 2019/06/30 21:13:12 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(const char *str, const char *del)
{
	size_t	c;
	int		i;

	c = 0;
	i = 0;
	while (str[i])
	{
		if (ft_strchr(del, str[i]) == NULL)
		{
			c++;
			while (ft_strchr(del, str[i]) == NULL && str[i] != '\0')
				i++;
			if (str[i] == '\0')
				break ;
		}
		i++;
	}
	return (c);
}
