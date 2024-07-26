/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:57:38 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/26 13:07:02 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	lst_nbr_parasite(t_stack *stack_a)
{
	t_stack	*bot;
	int		nbr;
	int		l_max;
	int		prev;

	bot = stack_a->next;
	nbr = 0;
	if (stack_a->data > stack_a->next->data)
	{
		nbr++;
		l_max = stack_a->next->data;
		bot = bot->next;
	}
	else
		l_max = stack_a->data;
	while (bot != stack_a)
	{
		if (bot->data < l_max)
			nbr++;
		else
			l_max = bot->data;
		bot = bot->next;
	}
	return (nbr);
}

int	*lst_remove_parasit(t_stack *stack_a)
{
	t_stack	*bot;
	int		*tab_int;
	int		size;
	int		i;
	int		l_max;

	size = lst_nbr_parasite(stack_a);
	tab_int = (int *)malloc(sizeof(int) * size);
	if (!tab_int)
		return (NULL);
	i = 0;
	bot = stack_a->next;
	if (stack_a->data > stack_a->next->data)
	{
		tab_int[i++] = stack_a->data;
		l_max = stack_a->next->data;
		bot = bot->next;
	}
	else
		l_max = stack_a->data;
	while (bot != stack_a && i < size)
	{
		if (bot->data < l_max)
			tab_int[i++] = bot->data;
		else
			l_max = bot->data;
		bot = bot->next;
	}
	return (tab_int);
}

void	remove_action(t_stack **stack_a)
{
	int	i;
	int	size;

	if (lst_sort(*stack_a))
		return ;
	i = 1;
	while(1)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			break ;
		i++;
	}
	size = lst_size(*stack_a);
	if (i < (size + 1 ) / 2)
	{
		while (i--)
			ft_ra(stack_a);
	}
	else
	{
		while (i++ != size)
			ft_rra(stack_a);
	}
}

void	push_to_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	int	*remove;
	int	i;
	int	ret;
	int	size;

	remove = lst_remove_parasit(*stack_a);
	size = lst_nbr_parasite(*stack_a);
	i = 0;
	ret = 0;
	while (i < size)
	{
		if ((*stack_a)->data == remove[i])
		{
			ft_pb(stack_a, stack_b); 
			i++;
		}
		else
			ft_ra(stack_a);
	}
	free(remove);
//	remove_action(stack_a);
}
