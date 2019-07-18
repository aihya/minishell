/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 21:08:32 by aihya             #+#    #+#             */
/*   Updated: 2019/06/30 22:11:17 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10000

# include "../libft/includes/libft.h"
# include "unistd.h"

typedef struct	s_lst
{
	char			*content;
	int				fd;
	struct s_lst	*next;
}				t_lst;

int				get_next_line(const int fd, char **line, t_lst **nodes);
void			free_gnl_nodes(t_lst **nodes);
void			lstadd(t_lst **alst, t_lst *new);

#endif
