/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 22:55:49 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/26 14:11:05 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	search_position(t_stack *stack_a, int nb, int max, int min)
{
	while (min != stack_a->data)
		stack_a = stack_a->next;
	while (stack_a->data != max)
	{
		if (stack_a->next->data > nb)
			break ;
		stack_a = stack_a->next;
	}
	return (stack_a->data);
}

int get_count(t_stack *stack, int size, int pos)
{
    int	median;
    int	count;

    if (size % 2 == 0)
        median = size / 2;
    else if (size % 2 != 0)
        median = (size + 1) / 2;
    if (pos <= median)
        count = pos - 1;
    else
        count = size - pos + 1;
    return (count);
}