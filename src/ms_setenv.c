/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 17:41:25 by aihya             #+#    #+#             */
/*   Updated: 2019/07/09 11:28:07 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ms_change_env(char **args, size_t size, t_env **node, t_env **prev)
{
	if (*node != NULL)
	{
		free((*node)->value);
		(*node)->value = size > 2 ? ft_strdup(args[2]) : NULL;
	}
	else
	{
		if (*prev == NULL)
		{
			(*node) = ms_node(NULL, NULL);
			(*node)->name = size > 1 ? ft_strdup(args[1]) : NULL;
			(*node)->value = size > 2 ? ft_strdup(args[2]) : NULL;
			return ;
		}
		(*prev)->next = ms_node(NULL, NULL);
		(*prev)->next->name = size > 1 ? ft_strdup(args[1]) : NULL;
		(*prev)->next->value = size > 2 ? ft_strdup(args[2]) : NULL;
	}
}

int			ms_check_name(char *name)
{
	int		i;

	i = 0;
	while (name[i])
	{
		if (!ft_strchr(ALNUM, name[i]))
		{
			if (i == 0)
				ms_error("setenv", BEGIN_LETTER_ERR, TRUE);
			else
				ms_error("setenv", ALNUM_ERR, TRUE);
			return (NOK);
		}
		i++;
	}
	return (OK);
}

int			ms_check_args(size_t size, char **args)
{
	if (size > 3)
	{
		ms_error("setenv", "too many arguments", TRUE);
		return (NOK);
	}
	else if (size > 1 && ms_check_name(args[1]) == NOK)
		return (NOK);
	return (OK);
}

int			ms_setenv(char **args, t_env **env)
{
	size_t	size;
	t_env	*node;
	t_env	*prev;

	size = ft_chain_size(args);
	if (ms_check_args(size, args) == NOK)
		return (NOK);
	if (size > 1)
	{
		prev = NULL;
		node = *env;
		while (node != NULL)
		{
			prev = node;
			if (ft_strequ(node->name, args[1]))
				break ;
			node = node->next;
		}
		ms_change_env(args, size, (*env == NULL) ? env : &node, &prev);
	}
	else
		return (ms_env(*env));
	return (OK);
}
