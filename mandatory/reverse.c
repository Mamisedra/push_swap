/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:30:57 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/29 14:05:43 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ra(t_stack **stack_a)
{
	if (stack_a && (*stack_a))
	{
		(*stack_a) = (*stack_a)->next;
		ft_printf("ra\n");
	}
}

void	ft_rb(t_stack **stack_b)
{
	if (stack_b && (*stack_b))
	{
		(*stack_b) = (*stack_b)->next;
		ft_printf("rb\n");
	}
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 0;
	if (stack_a && (*stack_a))
	{
		(*stack_a) = (*stack_a)->next;
		i++;
	}
	if (stack_b && (*stack_b))
	{
		(*stack_b) = (*stack_b)->next;
		i++;
	}
	if (i != 0)
		ft_printf("rr\n");
}
