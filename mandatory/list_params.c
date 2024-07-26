/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:31:31 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/26 17:28:06 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_params	*ft_paramslast(t_params *params)
{
	if (params)
	{
		while (params)
		{
			if (params->next == NULL)
				return (params);
			params = params->next;
		}
	}
	return (params);
}

void ft_params_add_back(t_params **params, t_params *new_p)
{
	t_params	*tmp;

	if (params)
	{
		if (*params == NULL)
			*params = new_p;
		else
		{
			tmp = ft_paramslast(*params);
			tmp->next = new_p;
		}
	}
}

void	ft_free_params(t_params **params)
{
	t_params	*tmp;

	tmp = *params;
	while (*params)
	{
		tmp = *params;
		*params = (*params)->next;
		free(tmp);
	}
	*params = NULL;
}

t_params	*new_params(t_stack *stack_a, t_stack *stack_b, int pos_b)
{
	t_params	*to_ret;
	int			size_a;
	int			size_b;

	to_ret = malloc(sizeof(t_params));
	if (!to_ret)
		return (NULL);
	size_a = lst_size(stack_a);
	size_b = lst_size(stack_b);
	to_ret->content = stack_b->data;
	to_ret->pos_b = pos_b;
	to_ret->target = ft_show_target(stack_a, stack_b->data);
	to_ret->cost_a = get_count(stack_a, size_a,to_ret->target);
	to_ret->cost_b = get_count(stack_b, size_b,pos_b);
	to_ret->cost_f = to_ret->cost_a + to_ret->cost_b + 1;
	to_ret->next = NULL;
	return (to_ret);
}