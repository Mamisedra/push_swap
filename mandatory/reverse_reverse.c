/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:22:49 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/31 21:32:39 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rra(t_stack **stack_a)
{
	if (lst_size(*stack_a) == 1)
		return ;
	if (stack_a && (*stack_a))
	{
		(*stack_a) = (*stack_a)->prev;
		ft_printf("rra\n");
	}
}

void	ft_rrb(t_stack **stack_b)
{
	if (lst_size(*stack_b) == 1)
		return ;
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
