/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 22:39:24 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/26 17:35:53 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	return_max(t_stack *stack_a)
{
	t_stack *begin;
	int		l_max;

	begin = stack_a;
	l_max = stack_a->data;
	while (begin->next != stack_a)
	{
		if (l_max <= begin->data)
			l_max = begin->data;
		begin = begin->next;
	}
	if (l_max <= begin->data)
		l_max = begin->data;
	return (l_max);
}

int	return_min(t_stack *stack_a)
{
	t_stack *begin;
	int		min;

	begin = stack_a;
	min = stack_a->data;
	while (begin->next != stack_a)
	{
		if (min >= begin->data)
			min = begin->data;
		begin = begin->next;
	}
	if (min >= begin->data)
		min = begin->data;
	return (min);
}

int	target_min(t_stack *stack_a, int min)
{
	t_stack *begin;
	int		i;

	begin = stack_a;
	i = 1;
	while (begin->next != stack_a)
	{
		if (min == begin->data)
			return (i);
		begin = begin->next;
		i++;
	}
	if (min == begin->data)
		return (i);
	return (i);
}

int	ft_show_target(t_stack *stack_a, int nb)
{
	int max;
	int min;
	int target;
	int	reference;
	t_stack *begin;

	max = return_max(stack_a);
	min = return_min(stack_a);
	if (min > nb || max < nb)
		return (target_min(stack_a, min));
	reference = search_position(stack_a, nb, max, min);
	target = 1;
	begin = stack_a;
	while (begin->next != stack_a)
	{
		if (reference == begin->data)
			return (target + 1);
		begin = begin->next;
		target++;
	}
	if (reference == begin->data)
		return (target + 1);
	return (target);
}