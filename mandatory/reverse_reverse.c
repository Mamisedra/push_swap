/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:22:49 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/21 12:16:00 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rra(t_stack **stack_a)
{
	if (!stack_a && !(*stack_a))
		(*stack_a) = (*stack_a)->prev;
	ft_printf("rra\n");
}

void	ft_rrb(t_stack **stack_b)
{
	if (!stack_b && !(*stack_b))
		(*stack_b) = (*stack_b)->prev;
	ft_printf("rrb\n");
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a && !(*stack_a))
		(*stack_a) = (*stack_a)->prev;
	if (!stack_b && !(*stack_b))
		(*stack_b) = (*stack_b)->prev;
	ft_printf("rrr\n");
}
