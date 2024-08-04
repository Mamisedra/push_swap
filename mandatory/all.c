/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 11:42:38 by mranaivo          #+#    #+#             */
/*   Updated: 2024/08/04 11:49:28 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_get_index(t_stack *stack_a, int min)
{
	t_stack	*current;
	int		i;

	i = 1;
	current = stack_a;
	while (current->data != min)
	{
		i++;
		current = current->next;
	}
	return (i);
}

static void	ft_sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	i;

	min = return_min(*stack_a);
	i = ft_get_index(*stack_a, min);
	if (i <= 2)
	{
		while ((*stack_a)->data != min)
			ft_ra(stack_a);
	}
	else
	{
		while ((*stack_a)->data != min)
			ft_rra(stack_a);
	}
	if ((*stack_a)->data == min)
		ft_pb(stack_a, stack_b);
	ft_sort_three(stack_a, 3);
	if (lst_sort(*stack_a))
		ft_pa(stack_a, stack_b);
}

static void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	i;

	if (lst_size(*stack_a) == 5)
	{
		min = return_min(*stack_a);
		i = ft_get_index(*stack_a, min);
		if (i <= 3)
		{
			while ((*stack_a)->data != min)
				ft_ra(stack_a);
		}
		else
		{
			while ((*stack_a)->data != min)
				ft_rra(stack_a);
		}
		if ((*stack_a)->data == min)
			ft_pb(stack_a, stack_b);
		ft_sort_four(stack_a, stack_b);
		if (lst_sort(*stack_a))
			ft_pa(stack_a, stack_b);
	}
	else
		ft_sort_four(stack_a, stack_b);
}

int	look_error(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size <= 3)
	{
		ft_sort_three(stack_a, 3);
		return (1);
	}
	if (size <= 5)
	{
		ft_sort_five(stack_a, stack_b);
		return (1);
	}
	return (0);
}
