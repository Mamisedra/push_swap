/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:50:38 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/19 18:13:27 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sa(t_stack **stack_a)
{
	int	temp;

	temp = 0;
	if (*stack_a != NULL && ((*stack_a)->next != (*stack_a)))
	{
		temp = (*stack_a)->data;
		(*stack_a)->data = (*stack_a)->next->data;
		(*stack_a)->next->data = temp;
	}
	ft_printf("sa\n");
}

void	ft_sb(t_stack **stack_b)
{
	int	temp;

	temp = 0;
	if (*stack_b != NULL && ((*stack_b)->next != (*stack_b)))
	{
		temp = (*stack_b)->data;
		(*stack_b)->data = (*stack_b)->next->data;
		(*stack_b)->next->data = temp;
	}
	ft_printf("sb\n");
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	int	temp_sa;
	int	temp_sb;

	temp_sa = 0;
	temp_sb = 0;
	if (*stack_a != NULL && ((*stack_a)->next != (*stack_a)))
	{
		temp_sa = (*stack_a)->data;
		(*stack_a)->data = (*stack_a)->next->data;
		(*stack_a)->next->data = temp_sa;
	}
	if (*stack_b != NULL && ((*stack_b)->next != (*stack_b)))
	{
		temp_sb = (*stack_b)->data;
		(*stack_b)->data = (*stack_b)->next->data;
		(*stack_b)->next->data = temp_sb;
	}
	ft_printf("ss\n");
}