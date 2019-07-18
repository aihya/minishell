/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 00:29:17 by aihya             #+#    #+#             */
/*   Updated: 2018/10/28 16:13:27 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	const char	*srccpy;
	char		*dstcpy;

	srccpy = src;
	dstcpy = dst;
	while ((*dstcpy++ = *srccpy++))
		;
	return (dst);
}
