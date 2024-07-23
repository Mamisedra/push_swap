/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:57:38 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/23 17:40:16 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_give_min_or_max(t_stack *stack, int cnd)
{
	int	min;
	int	max;
	t_stack	*stop;

	min = 0;
	max = 0;
	if (stack == NULL)
		return (0);
	stop = stack;
	while (stack != stop)
	{
		if (min < stack->data)
			min = stack->data;
		if (max > stack->data)
			max = stack->data; 
		stack = stack->next;
	}
	if (cnd == 1)
		return (max);
	else
		return (min);
}
