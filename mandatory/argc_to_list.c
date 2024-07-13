/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argc_to_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:41:13 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/11 16:34:30 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	lst_clear(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*tete;

	if (!stack || !(*stack))
		return ;
	tete = *stack;
	tete->prev->next = NULL;
	while (tete)
	{
		temp = tete->next;
		free(tete);
		tete = temp;
	}
	*stack = NULL;
}

void	lst_delone(t_stack **stack, t_stack *to_delete)
{
	if (!stack || !(*stack) || !to_delete)
		return ;
	if (to_delete->prev == to_delete && to_delete->next == to_delete)
	{
		free(to_delete);
		*stack = NULL;
		return ;
	}
	to_delete->prev->next = to_delete->next;
	to_delete->next->prev = to_delete->prev;
	if (*stack == to_delete)
		*stack = to_delete->next;
	free(to_delete);
}

t_list	*argc_to_list(int argc, char **argv)
{	
}