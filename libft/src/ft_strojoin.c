/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strojoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:46:55 by aihya             #+#    #+#             */
/*   Updated: 2019/06/30 15:50:27 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strojoin(char **s1, char *s2, int overwrite)
{
	char	*tmp;

	if (overwrite)
	{
		tmp = ft_strjoin((const char *)(*s1), (const char *)s2);
		free(*s1);
		(*s1) = tmp;
		return (NULL);
	}
	return (ft_strjoin((const char *)(*s1), (const char *)s2));
}
