/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:16:33 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/21 11:06:04 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*new_list(int data)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->data = data;
	stack->next = stack;
	stack->prev = stack;
	return (stack);
}

void	lst_add_back(t_stack **stack_a, t_stack *new_stack)
{
	t_stack *last;

	last = NULL;
	if (!*stack_a)
	{
		*stack_a = new_stack;
		return ;
	}
	last = (*stack_a)->prev;
	new_stack->next = *stack_a;
	new_stack->prev = last;
	last->next = new_stack;
	(*stack_a)->prev = new_stack;
}

void	lst_add_front(t_stack **stack_a, t_stack *new_stack)
{
	t_stack *next_stack;

	next_stack = NULL;
	if (!*stack_a)
	{
		*stack_a = new_stack;
		return ;
	}
	next_stack = (*stack_a)->prev;
	new_stack->next = *stack_a;
	new_stack->prev = next_stack;
	next_stack->next = new_stack;
	(*stack_a)->prev =new_stack;
	*stack_a = new_stack;
}

void	lst_clear(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*begin;

	if (!stack || !(*stack))
		return ;
	begin = *stack;
	begin->prev->next = NULL;
	while (begin)
	{
		temp = begin->next;
		free(begin);
		begin = temp;
	}
	*stack = NULL;
	free(begin);
	free(temp);
}

void lst_delone(t_stack **stack)
{
    t_stack *delone;
    t_stack *first;
    t_stack *next;

    if (*stack == NULL)
        return;
	delone = *stack;
	first = (*stack)->prev;
	next = (*stack)->next;
    if (first == *stack && next == *stack)
        *stack = NULL;
    else
    {
        first->next = next;
        next->prev = first;
        if (*stack == delone)
            *stack = next;
    }
    free(delone);
}

