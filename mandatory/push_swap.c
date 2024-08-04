/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:57:15 by mranaivo          #+#    #+#             */
/*   Updated: 2024/08/04 11:46:55 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	size_a;

	size_a = lst_size(*stack_a);
	if (size_a == 2 && (*stack_a)->data > (*stack_a)->next->data)
	{
		ft_ra(stack_a);
		return ;
	}
	if (look_error(stack_a, stack_b, size_a))
		return ;
	push_to_stack_b(stack_a, stack_b);
	ft_push_to_stack_a(stack_a, stack_b);
	ft_remise_sort(stack_a);
}

void	ft_sort_three(t_stack **stack_a, int size)
{
	int	a_2;
	int	a_3;

	if (lst_sort(*stack_a))
		return ;
	a_2 = (*stack_a)->next->data;
	a_3 = (*stack_a)->prev->data;
	if (size <= 2 && (*stack_a)->data > a_2)
		ft_sa(stack_a);
	if ((*stack_a)->data < a_2 && a_2 > a_3 && (*stack_a)->data < a_3)
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
	else if ((*stack_a)->data > a_2 && a_2 < a_3 && a_3 > (*stack_a)->data)
		ft_sa(stack_a);
	else if (a_3 < (*stack_a)->data && (*stack_a)->data < a_2 && a_2 > a_3)
		ft_rra(stack_a);
	else if ((*stack_a)->data > a_2 && (*stack_a)->data > a_3 && a_2 < a_3)
		ft_ra(stack_a);
	else
	{
		ft_ra(stack_a);
		ft_sa(stack_a);
	}
}

void	ft_remise_sort(t_stack **stack_a)
{
	int		size;
	int		median;
	int		min;
	int		i;
	t_stack	*stack;

	size = lst_size(*stack_a);
	median = ft_get_median(size);
	min = return_min(*stack_a);
	stack = *stack_a;
	i = 1;
	while (1)
	{
		if (stack->data > stack->next->data || (stack == *stack_a && i != 1))
			break ;
		i++;
		stack = stack->next;
	}
	if (i != size)
	{
		how_to_ra_rra(i, median, min, stack_a);
	}
}

void	return_s_b_to_s_a(t_stack **stack_a, t_stack **stack_b, int *tab)
{
	ft_place_top(stack_a, stack_b, tab);
	if (tab[0] == (*stack_b)->data)
		ft_pa(stack_a, stack_b);
}

void	ft_push_to_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	t_params	*params;
	int			*tab;

	params = NULL;
	while (*stack_b)
	{
		ft_add_p_s(*stack_a, *stack_b, &params);
		tab = ft_getparams_min(params);
		if (!tab)
			return ;
		return_s_b_to_s_a(stack_a, stack_b, tab);
		ft_free_params(&params);
		free(tab);
	}
}
