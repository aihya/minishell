/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 22:34:10 by aihya             #+#    #+#             */
/*   Updated: 2019/06/30 22:08:48 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env	*ms_get_var(char *name, t_env *env)
{
	t_env	*curr;

	curr = env;
	while (curr)
	{
		if (ft_strcmp(curr->name, name) == 0)
			return (ms_node(curr->name, curr->value));
		curr = curr->next;
	}
	return (NULL);
}

int		ms_match_found(char *name, t_env *env)
{
	t_env	*match;

	if ((match = ms_get_var(name, env)) == NULL)
		return (FALSE);
	free(match);
	return (TRUE);
}

int		ms_check_args_size(char **args)
{
	if (ft_chain_size(args) == 1)
	{
		ms_error("unsetenv", TOO_FEW_ARGS, TRUE);
		return (NOK);
	}
	return (OK);
}

int		ms_unsetenv(char **args, t_env **env)
{
	t_env	*prev;
	t_env	*curr;
	int		i;

	if (ms_check_args_size(args) == NOK)
		return (NOK);
	i = 1;
	while (args[i++])
	{
		prev = NULL;
		curr = *env;
		while (curr && ft_strequ(curr->name, args[i - 1]) == 0)
		{
			prev = curr;
			curr = curr->next;
		}
		if (curr == NULL)
			return (NOK);
		else if (prev != NULL && curr != NULL)
			prev->next = curr->next;
		else if (prev == NULL && curr != NULL)
			(*env) = (*env)->next;
		ms_free_node(&curr);
	}
	return (OK);
}
