/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 00:41:48 by mranaivo          #+#    #+#             */
/*   Updated: 2024/08/03 13:38:27 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_get_index_min(t_stack *stack_a, int min)
{
	t_stack	*index;

	index = stack_a;
	while (index->data != min)
		index = index->next;
	return (index->next);
}

int	lst_sort_cir(t_stack *stack_a)
{
	t_stack	*bot;
	int		min;
	int		prec;

	min = return_min(stack_a);
	prec = min;
	bot = ft_get_index_min(stack_a, min);
	while (bot->data != min)
	{
		if (bot->data < prec)
			return (0);
		prec = bot->data;
		bot = bot->next;
	}
	return (1);
}

int	*make_lis_tab(int size, int ch)
{
	int	*tab;
	int	i;

	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < size)
	{
		tab[i] = ch;
		i++;
	}
	return (tab);
}

int	*copy_list_at_tab(t_stack *stack_a, int size)
{
	t_stack	*lst;
	int		*tab;
	int		i;

	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	i = 0;
	lst = stack_a;
	while (i < size)
	{
		tab[i] = lst->data;
		lst = lst->next;
		i++;
	}
	return (tab);
}

int	*ft_lis_show(t_stack *stack_a, int size, int *size_ret)
{
	t_lis_params	lis_params;
	int				*tab_lis;

	init_lis_params(stack_a, size, &lis_params);
	tab_lis = construct_lis(&lis_params, size, size_ret);
	free(lis_params.tab_way);
	free(lis_params.tab_int);
	free(lis_params.tab_params);
	return (tab_lis);
}
