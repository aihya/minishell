/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_del.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <abdechahid.ihya@hotmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:03:03 by aihya             #+#    #+#             */
/*   Updated: 2019/05/12 13:56:33 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit_del(char *str, char *del)
{
	char	**splited;
	size_t	counted_words;
	size_t	i;
	int		reset;

	if (!str || !del)
		return (NULL);
	counted_words = ft_count_words(str, del);
	if (!(splited = (char **)malloc(sizeof(char *) * (counted_words + 1))))
		return (NULL);
	i = 0;
	reset = 0;
	while ((splited[i] = ft_next_word(str, del, reset)) && ++i)
		reset = reset == BEGINING ? LAST_POS : reset;
	return (splited);
}
