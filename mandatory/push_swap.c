/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:57:15 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/24 18:22:49 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	ft_sort_max(t_stack **stack_a, t_stack **stack_b)
{}

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