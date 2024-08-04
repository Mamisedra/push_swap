/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:31:31 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/31 21:33:43 by mranaivo         ###   ########.fr       */
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

void	ft_params_add_back(t_params **params, t_params *new_p)
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

t_params	*new_params(t_stack *stack_a, t_stack *stack_b, int pos_b)
{
	t_params	*to_ret;
	int			size_a;
	int			size_b;
	int			min_a;
	int			max_a;

	to_ret = malloc(sizeof(t_params));
	if (!to_ret)
		return (NULL);
	size_a = lst_size(stack_a);
	size_b = lst_size(stack_b);
	min_a = return_min(stack_a);
	max_a = return_max(stack_a);
	to_ret->content = stack_b->data;
	to_ret->pos_b = pos_b;
	to_ret->target = get_target(stack_a, stack_b->data, min_a, max_a);
	to_ret->cost_a = get_cout(size_a, to_ret->target);
	to_ret->cost_b = get_cout(size_b, pos_b);
	to_ret->cost_f = to_ret->cost_a + to_ret->cost_b + 1;
	to_ret->next = NULL;
	return (to_ret);
}
