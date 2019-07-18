/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 20:12:26 by aihya             #+#    #+#             */
/*   Updated: 2018/10/28 15:20:09 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		n;
	int		len;
	int		sign;
	char	*s;

	s = ft_strtrim(str);
	sign = 1;
	if (*s == '-' && (sign = -1))
		s++;
	else if (s[0] == '+')
		s++;
	while (*s == '0')
		s++;
	len = 0;
	while (ft_isdigit(s[len]))
		len++;
	if (len > 10 && sign == 1)
		return (-1);
	if (len > 10 && sign == -1)
		return (0);
	n = 0;
	while (ft_isdigit(*s++))
		n = (n * 10) + (*(s - 1) - 48);
	return (n * sign);
}
