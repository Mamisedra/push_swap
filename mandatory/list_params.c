/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:31:31 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/28 14:38:14 by mranaivo         ###   ########.fr       */
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

void	copy_params_min(t_params	*params, int *tab)
{
	tab[0] = params->content;
	tab[1] = params->pos_b;
	tab[2] = params->target;
	tab[3] = params->cost_b;
	tab[4] = params->cost_a;
	tab[5] = params->cost_f;
}

int	*ft_getparams_min(t_params *params)
{
	int			*tab;
	t_params	*params_min;
	t_params	*begin;

	tab = malloc(sizeof(int) * 6);
	if (!tab)
		return (NULL);
	params_min = params;
	begin = params;
	while (params != NULL)
	{
		if (params->cost_f < params_min->cost_f)
			params_min = params;
		params = params->next;
	}
	params = begin;
	copy_params_min(params_min, tab);
	return (tab);
}