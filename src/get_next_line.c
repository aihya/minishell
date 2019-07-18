/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 10:16:38 by aihya             #+#    #+#             */
/*   Updated: 2019/06/28 16:30:44 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include <stdio.h>

static t_lst	*fd_exist(t_lst **alst, int fd)
{
	t_lst	*current;

	current = *alst;
	while (current && (current->fd != fd))
		current = current->next;
	if (current && current->fd == fd)
		return (current);
	return (NULL);
}

static t_lst	*new_node(int fd)
{
	t_lst	*node;

	if ((node = (t_lst *)malloc(sizeof(t_lst))))
	{
		node->content = ft_strnew(0);
		node->fd = fd;
		node->next = NULL;
		return (node);
	}
	return (NULL);
}

static int		read_content(t_lst *node, int fd)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;
	char	*tmp;

	if ((ret = read(fd, buff, 0)) < 0)
		return (-1);
	if ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		tmp = ft_strjoin(node->content, buff);
		free(node->content);
		node->content = tmp;
	}
	return (ret);
}

static int		fill_line(char **line, t_lst *node, int fd)
{
	int		ret;
	char	*tmp;

	ret = read_content(node, fd);
	if (ret < 0)
		return (-1);
	if (ft_strchr(node->content, '\n'))
	{
		*line = ft_next_word(node->content, "\n", BEGINING);
		tmp = ft_strdup(ft_strchr(node->content, '\n') + 1);
		free(node->content);
		node->content = tmp;
		return (1);
	}
	ret = read_content(node, fd);
	if (ret != 0)
		return (fill_line(line, node, fd));
	if (ft_strlen(node->content))
	{
		*line = ft_strsub(node->content, 0, ft_strlen(node->content));
		ft_strclr(node->content);
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line, t_lst **nodes)
{
	static t_lst	*lst;
	t_lst			*node;

	lst = (!lst) ? new_node(fd) : lst;
	if (!(node = fd_exist(&lst, fd)))
		lstadd(&lst, (node = new_node(fd)));
	*nodes = lst;
	return (fill_line(line, node, fd));
}
