/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:22:49 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/23 17:40:24 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rra(t_stack **stack_a)
{
	if (stack_a && (*stack_a))
	{
		(*stack_a) = (*stack_a)->prev;
		ft_printf("rra\n");
	}
}

void	ft_rrb(t_stack **stack_b)
{
	if (stack_b && (*stack_b))
	{
		(*stack_b) = (*stack_b)->prev;
		ft_printf("rrb\n");
	}
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 0;
	if (stack_a && (*stack_a))
	{
		(*stack_a) = (*stack_a)->prev;
		i++;
	}
	if (stack_b && (*stack_b))
	{
		(*stack_b) = (*stack_b)->prev;
		i++;
	}
	if (i != 0)
		ft_printf("rrr\n");
}

void	ft_how_rra(t_stack **stack_a)
{}

void	ft_how_rrb(t_stack **stack_b)
{}