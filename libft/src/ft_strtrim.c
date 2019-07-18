/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 10:15:09 by aihya             #+#    #+#             */
/*   Updated: 2018/10/28 15:23:22 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*trimmed;
	int		size;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || (s[i] > 7 && s[i] < 14))
		i++;
	j = (int)ft_strlen(s);
	while (i != j && (s[j - 1] == ' ' || (s[j - 1] > 7 && s[j - 1] < 14)))
		j--;
	j = (int)ft_strlen(s) - j;
	j = (int)ft_strlen(s) - j;
	size = (j - i);
	if (!(trimmed = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	j = 0;
	while (++j <= size && ++i)
		trimmed[j - 1] = s[i - 1];
	trimmed[j - 1] = '\0';
	return (trimmed);
}
