/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:57:15 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/21 15:02:57 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	(void)stack_b;
	while (!lst_sort(*stack_a))
	{
		if (cmp((*stack_a)->data, (*stack_a)->next->data) > 0)
		{
			if (cmp((*stack_a)->data, (*stack_a)->next->next->data) > 0)
				ft_rra(stack_a);
			else
			 	ft_sa(stack_a);
		}
		if (lst_sort(*stack_a))
			break ;
		else
			ft_ra(stack_a);
		if (lst_sort(*stack_a))
			return ;
	}
	if (lst_sort(*stack_a))
		return ;
}