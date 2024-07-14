/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:00:14 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/14 16:58:38 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

t_stack	*init_lst(void)
{
	t_stack    *new_stack;

    new_stack = (t_stack *)malloc(sizeof(t_stack));
    if (!new_stack)
        return (NULL);
    new_stack->data = 0;
    new_stack->prev = new_stack;
    new_stack->next = new_stack;
    return (new_stack);
}

t_stack	*init_new_lst(int index)
{
	t_stack    *new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->data = index;
	new_stack->prev = NULL;
	new_stack->next = NULL; 
	return (new_stack);
}

void	lst_add_front(t_stack **stack, t_stack *new_stack)
{
	if (stack != NULL && new_stack != NULL)
	{
		new_stack->next = (*stack)->next;
		new_stack->prev = *stack;
		(*stack)->next->prev = new_stack;
		(*stack)->next = new_stack;
	}
}

void	lst_add_back(t_stack **stack, t_stack *new_stack)
{
	if(stack != NULL && new_stack != NULL)
	{
		if (*stack == NULL)
			*stack = new_stack;
		else
		{
			new_stack->prev = (*stack)->prev;
			new_stack->next = *stack;
			(*stack)->prev->next = new_stack;
			(*stack)->prev = new_stack;
		}
	}
}

int		lst_size(t_stack *stack)
{
	t_stack    *current;
    int        size;

    if (stack == NULL)
        return (0);
    current = stack->next;
    size = 0;
    while (current != stack)
    {
        current = current->next;
        size++;
    }
    return (size);
}
