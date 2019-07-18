/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:52:48 by aihya             #+#    #+#             */
/*   Updated: 2018/10/28 15:35:05 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	const char *s1_cpy;
	const char *s2_cpy;

	s1_cpy = s1;
	s2_cpy = s2;
	while ((*s1_cpy || *s2_cpy) && (*s1_cpy++ == *s2_cpy++))
		;
	return ((unsigned char)*(s1_cpy - 1) - (unsigned char)*(s2_cpy - 1));
}
