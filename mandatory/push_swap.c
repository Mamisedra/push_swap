/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:57:15 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/25 16:15:03 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void print_params(t_params *params)
{
	if (params == NULL)
	{
		printf("fail\n");
		return;
	}
    while (params != NULL)
    {
        printf("Paramètres:\n");
        printf(" - Content: %d\n", params->content);
        printf(" - Pos_b: %d\n", params->pos_b);
        printf(" - Target: %d\n", params->target);
        printf(" - Cost_a: %d\n", params->cost_a);
        printf(" - Cost_b: %d\n", params->cost_b);
        printf(" - Cost_f: %d\n", params->cost_f);
        params = params->next;
    }
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	if (lst_size(*stack_a) < 6)
		ft_sort_min(stack_a, stack_b);
	else
	{
		push_to_stack_b(stack_a, stack_b);
		ft_sort_max(stack_a, stack_b);
	}
}

void	add_params_stack_b(t_stack *stack_a, t_stack *stack_b, t_params **params)
{
	int	pos_b;
	int	size;
	int	i;

	pos_b = 1;
	i = 0;
	size = lst_size(stack_b);
	while (i < size)
	{
		ft_params_add_back(params, new_params(stack_a, stack_b, pos_b));
		stack_b = stack_b->next;
		pos_b++;
		i++;
	}
}

t_params	it_s_min_cost(t_params *params)
{
	t_params	ret;

	printf("********\n");
	// if (params == NULL)
	// 	return (ret);
	ret = *params;
	while (params->next != NULL)
	{
		if (ret.cost_f > params->cost_f)
			ret = *params;
		params = params->next;
	}
	ft_printf("Fonction 2\n");
	return (ret);
}

void	push_and_rotate(t_stack **stack_a, t_stack **stack_b, t_params min)
{
	if (min.pos_b <= ((lst_size(*stack_b) + 1 ) / 2))
	{
		while (min.cost_b--)
			ft_rb(stack_b);
	}
	else
	{
		while (min.cost_b--)
			ft_rrb(stack_b);
	}
	if (min.target <= ((lst_size(*stack_a) + 1 ) / 2))
	{
		while (min.cost_a--)
			ft_ra(stack_b);
	}
	else
	{
		while (min.cost_a--)
			ft_rra(stack_b);
	}
	ft_pa(stack_a, stack_b);
	ft_printf("Fonction 3\n");
}

void	ft_sort_max(t_stack **stack_a, t_stack **stack_b)
{
	t_params	*params;
	params = NULL;

	while (*stack_b)
	{
		add_params_stack_b(*stack_a, *stack_b, &params);
		push_and_rotate(stack_a, stack_b, it_s_min_cost(params));
		ft_free_params(&params);
	}
}

void	ft_sort_min(t_stack **stack_a, t_stack **stack_b)
{
	if (lst_size(*stack_a) == 3)
	{
		if ((*stack_a)->data > (*stack_a)->prev->data && (*stack_a)->data > (*stack_a)->next->data)
		{
			ft_ra(stack_a);
			if ((*stack_a)->data > (*stack_a)->next->data)
				ft_sa(stack_a);
		}
		else if ((*stack_a)->data > (*stack_a)->next->data)
		{
			ft_sa(stack_a);
			if ((*stack_a)->prev->data < (*stack_a)->data)
				ft_rra(stack_a);
		}
		else if ((*stack_a)->prev->data < (*stack_a)->data)
		{
			ft_rra(stack_a);
			if ((*stack_a)->data > (*stack_a)->next->data)
				ft_sa(stack_a);
		}
	}
}