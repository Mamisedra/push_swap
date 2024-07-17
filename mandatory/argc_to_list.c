/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argc_to_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:41:13 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/17 14:41:12 by mranaivo         ###   ########.fr       */
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
	free(tete);
	free(temp);
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

void	ft_free_str(char **str)
{
	int    i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i ++;
	}
	free(str);
}

int	lst_double(t_stack *stack)
{
	t_stack	*next;

	if (!stack)
		return (1);
	stack->prev->next = NULL;
	while (stack)
	{
		next = stack->next;
		while (next)
		{
			if (cmp(next->data, stack->data) == 0)
			{
				ft_printf("%s %s", ERR_MSG, "Argument contiet des doubles\n");
				return (1);
			}
			next = next->next;
		}
		stack = stack->next;
	}
	return (0);
}

int	cmp(int nb1, int nb2)
{
	if (nb1 < nb2)
	    return (1);
	else if (nb1 > nb2)
		return (-1);
	return (0);
}