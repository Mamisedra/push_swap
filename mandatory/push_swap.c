/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:57:15 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/26 17:28:07 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void print_params(t_params *params)
{
	static int i = 1;
	if (params == NULL)
	{
		printf("PARAMS_NULL\n");
		return;
	}
    while (params != NULL)
    {
        ft_printf("Paramètres %d:\n\n", i++);
        ft_printf(" - Content: %d\n", params->content);
        ft_printf(" - Pos_b: %d\n", params->pos_b);
        ft_printf(" - Target: %d\n", params->target);
        ft_printf(" - Cost_b: %d\n", params->cost_b);
        ft_printf(" - Cost_a: %d\n", params->cost_a);
        ft_printf(" - Cost_f: %d\n", params->cost_f);
        params = params->next;
    }
}

void	add_params_elem_stack(t_stack *stack_a, t_stack *stack_b, t_params **params)
{
	t_stack	*tmp;
	int		pos;

	if (stack_b == NULL)
		return ;
	tmp = stack_b;
	pos = 1;
	while (1)
	{
		ft_params_add_back(params, new_params(stack_a, tmp, pos));
		tmp = tmp->next;
		if (tmp == stack_b)
			break ;
		pos++;
	}
}

t_params	*ft_getcout_min(t_params *params)
{
	t_params	*ret;

	if (params == NULL)
		return (NULL);
	ret = params;
	while (params != NULL)
	{
		if (ret->cost_f > params->cost_f)
			ret  = params;
		params = params->next;
	}
	return (ret);
}

void	push_and_rotate(t_stack **stack_a, t_stack **stack_b, t_params *params)
{
	int	median_b;
	int	size_a;
	int	size_b;
	int	median_a;

	size_a = lst_size(*stack_a);
	size_b = lst_size(*stack_b);
	if (size_a % 2 != 0)
		size_a += 1;
	median_a = size_a / 2;
	if (size_b % 2 != 0)
		size_b += 1;
	median_b = size_b / 2;
	if (params->target <= median_a)
	{
		while((params->cost_a)--)
			ft_ra(stack_a);
	}
	else
	{
		while((params->cost_a)--)
			ft_rra(stack_a);
	}
	if (params->pos_b <= median_b)
	{
		while((params->cost_b)--)
			ft_rb(stack_b);
	}
	else
	{
		while((params->cost_b)--)
			ft_rrb(stack_b);
	}
	ft_pa(stack_a, stack_b);
}
