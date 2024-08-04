/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 12:05:44 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/31 22:56:47 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	return_min(t_stack *stack)
{
	int		min;
	t_stack	*tmp;

	min = stack->data;
	tmp = stack->next;
	while (tmp != stack)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min);
}

int	return_max(t_stack *stack)
{
	int		max;
	t_stack	*tmp;

	max = stack->data;
	tmp = stack->next;
	while (tmp != stack)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->next;
	}
	return (max);
}

int	get_number_place(t_stack *stack, int nb, int min)
{
	t_stack	*tmp;
	int		its;

	tmp = stack;
	if (nb < min)
		return (min);
	while (tmp->data != min)
		tmp = tmp->next;
	if (tmp->data == min)
	{
		its = tmp->data;
		tmp = tmp->next;
	}
	while (tmp->data != min)
	{
		if (tmp->data > nb && its <= nb)
		{
			its = tmp->data;
			break ;
		}
		its = tmp->data;
		tmp = tmp->next;
	}
	return (its);
}

int	target_min_max(t_stack *stack, int min)
{
	int		target;
	t_stack	*tmp;

	target = 1;
	tmp = stack;
	if (tmp->data == min)
		return (target);
	while (tmp->data != min)
	{
		target++;
		tmp = tmp->next;
	}
	return (target);
}

int	get_target(t_stack *stack_a, int nb, int min, int max)
{
	t_stack	*tmp;
	int		ref;
	int		target;

	target = 1;
	if (nb < min || nb > max)
		return (target_min_max(stack_a, min));
	tmp = stack_a;
	ref = get_number_place(tmp, nb, min);
	tmp = stack_a;
	while (1)
	{
		if (tmp->data == ref)
			break ;
		tmp = tmp->next;
		target++;
	}
	return (target);
}
