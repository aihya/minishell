/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_path_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 17:04:31 by aihya             #+#    #+#             */
/*   Updated: 2019/06/30 22:09:01 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <dirent.h>

int		ms_path_of_directory(char *path)
{
	DIR		*dirp;

	dirp = opendir(path);
	if (dirp == NULL)
	{
		ms_error("cd", "not a directory", FALSE);
		ft_putstr(": ");
		ft_putendl(path);
		return (NOK);
	}
	closedir(dirp);
	return (OK);
}

int		ms_path_exist(char *path)
{
	if (access(path, F_OK) == -1)
	{
		ms_error("cd", "no such file or directory", FALSE);
		ft_putstr(": ");
		ft_putendl(path);
		return (NOK);
	}
	return (OK);
}

int		ms_path_accessible(char *path)
{
	if (access(path, X_OK) == -1)
	{
		ms_error("cd", "permission denied", FALSE);
		ft_putstr(": ");
		ft_putendl(path);
		return (NOK);
	}
	return (OK);
}

int		ms_is_executable(char *path)
{
	struct stat	st;

	stat(path, &st);
	if (S_ISDIR(st.st_mode))
	{
		ms_error("ms", "path to a directory", TRUE);
		return (NOK);
	}
	else if ((st.st_mode & S_IXUSR) == 0)
	{
		ms_error("ms", "permission denied", TRUE);
		return (NOK);
	}
	return (OK);
}

int		ms_check_path(char *path)
{
	if (!ms_path_exist(path) || !ms_path_of_directory(path) ||
		!ms_path_accessible(path))
	{
		return (NOK);
	}
	return (OK);
}
