/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:50:38 by mranaivo          #+#    #+#             */
/*   Updated: 2024/08/03 13:42:24 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sa(t_stack **stack_a)
{
	int	tmp;

	tmp = 0;
	if (*stack_a != NULL && ((*stack_a)->next != (*stack_a)))
	{
		tmp = (*stack_a)->data;
		(*stack_a)->data = (*stack_a)->next->data;
		(*stack_a)->next->data = tmp;
	}
	ft_printf("sa\n");
}

void	ft_sb(t_stack **stack_b)
{
	int	tmp;

	tmp = 0;
	if (*stack_b != NULL && ((*stack_b)->next != (*stack_b)))
	{
		tmp = (*stack_b)->data;
		(*stack_b)->data = (*stack_b)->next->data;
		(*stack_b)->next->data = tmp;
	}
	ft_printf("sb\n");
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	int	tmp_sa;
	int	tmp_sb;

	tmp_sa = 0;
	tmp_sb = 0;
	if (*stack_a != NULL && ((*stack_a)->next != (*stack_a)))
	{
		tmp_sa = (*stack_a)->data;
		(*stack_a)->data = (*stack_a)->next->data;
		(*stack_a)->next->data = tmp_sa;
	}
	if (*stack_b != NULL && ((*stack_b)->next != (*stack_b)))
	{
		tmp_sb = (*stack_b)->data;
		(*stack_b)->data = (*stack_b)->next->data;
		(*stack_b)->next->data = tmp_sb;
	}
	ft_printf("ss\n");
}
