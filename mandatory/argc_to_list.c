/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argc_to_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:41:13 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/14 17:26:54 by mranaivo         ###   ########.fr       */
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

void	lst_add_split(char *argv, t_stack **stack)
{
	char	**after_split;
	int		i;

	after_split = argc_split(argv);
	if (!after_split)
	{
		return ;
		exit (EXIT_FAILURE);
	}
	i = 0;
	while (after_split[i] != NULL)
	{
		lst_add_back(stack, init_new_lst(ft_atoi(after_split[i])));
        i++;
	}
	ft_free_str(after_split);
}

t_stack	*argc_to_list(int argc, char **argv)
{	
	t_stack	*stack_a;
	int		i;

	stack_a = init_lst();
	if (!stack_a)
		return (NULL);
	i = 1;
	while (i <= argc)
	{
		lst_add_split(argv[i], &stack_a);
		i++;
	}
	return (stack_a);
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
				return (1);
			next = next->next;
		}
		stack = stack->next;
	}
	return (0);
}