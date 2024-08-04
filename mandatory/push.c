/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:31:36 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/30 17:53:37 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push_utils(t_stack **stack, t_stack *first_a)
{
	t_stack	*last_b;

	if (*stack == NULL)
	{
		first_a->next = first_a;
		first_a->prev = first_a;
		*stack = first_a;
	}
	else
	{
		last_b = (*stack)->prev;
		first_a->next = *stack;
		first_a->prev = last_b;
		last_b->next = first_a;
		(*stack)->prev = first_a;
		*stack = first_a;
	}
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first_a;
	t_stack	*prev_a;
	t_stack	*next_a;

	if (*stack_a == NULL)
		return ;
	first_a = *stack_a;
	if (first_a->next == first_a)
		*stack_a = NULL;
	else
	{
		prev_a = first_a->prev;
		next_a = first_a->next;
		prev_a->next = next_a;
		next_a->prev = prev_a;
		*stack_a = next_a;
	}
	ft_push_utils(stack_b, first_a);
	ft_printf("pb\n");
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first_a;
	t_stack	*prev_a;
	t_stack	*next_a;

	if (*stack_b == NULL)
		return ;
	first_a = *stack_b;
	if (first_a->next == first_a)
		*stack_b = NULL;
	else
	{
		prev_a = first_a->prev;
		next_a = first_a->next;
		prev_a->next = next_a;
		next_a->prev = prev_a;
		*stack_b = next_a;
	}
	ft_push_utils(stack_a, first_a);
	ft_printf("pa\n");
}
