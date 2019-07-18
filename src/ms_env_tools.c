/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:51:59 by aihya             #+#    #+#             */
/*   Updated: 2019/07/03 18:48:10 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ms_free_node(t_env **node)
{
	free((*node)->name);
	free((*node)->value);
	free((*node));
}

t_env	*ms_node(char *name, char *value)
{
	t_env	*node;

	node = (t_env *)malloc(sizeof(t_env));
	node->name = ft_strdup(name);
	if (value)
		node->value = ft_strdup(value);
	else
		node->value = ft_strnew(0);
	node->next = NULL;
	return (node);
}

t_env	*ms_init_env(char **ev)
{
	t_env	*head;
	t_env	*curr;
	char	**buffer;
	char	*value;

	head = NULL;
	if (ft_chain_size(ev))
	{
		buffer = ft_strsplit_del(*ev, "=");
		value = buffer[1] ? buffer[1] : NULL;
		head = ms_node(buffer[0], value);
		ft_chain_free(&buffer);
		curr = head;
		while (*(++ev))
		{
			buffer = ft_strsplit_del(*ev, "=");
			value = buffer[1] ? buffer[1] : NULL;
			curr->next = ms_node(buffer[0], value);
			ft_chain_free(&buffer);
			curr = curr->next;
		}
		return (head);
	}
	return (head);
}

void	ms_free_env(t_env **env)
{
	t_env	*curr;
	t_env	*next;

	curr = *env;
	while (curr)
	{
		next = curr->next;
		ms_free_node(&curr);
		curr = next;
	}
}

char	**ms_env_to_array(t_env *env)
{
	char	**array;
	char	*var;
	t_env	*curr;

	array = NULL;
	curr = env;
	while (curr)
	{
		if (curr->value == NULL)
			var = ft_strjoin(curr->name, "=");
		else
			var = ft_strsjoin(curr->name, curr->value, "=");
		ft_chain_push(&array, var);
		free(var);
		curr = curr->next;
	}
	return (array);
}
