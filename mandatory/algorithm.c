/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:57:38 by mranaivo          #+#    #+#             */
/*   Updated: 2024/08/04 11:25:16 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_chr_at_lis(int *tab, int ch, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

int	*give_no_lis(t_stack *stack_a, int *size_n_l, int size_a)
{
	t_stack	*bot;
	int		size_l;
	int		*tab_lis;
	int		*tab_non_lis;
	int		i;

	size_a = lst_size(stack_a);
	tab_lis = ft_lis_show(stack_a, size_a, &size_l);
	*size_n_l = size_a - size_l;
	tab_non_lis = malloc(sizeof(int) * *size_n_l + 1);
	if (!tab_non_lis)
		return (NULL);
	i = 0;
	bot = stack_a;
	while (i < *size_n_l)
	{
		if (!ft_chr_at_lis(tab_lis, bot->data, size_l))
			tab_non_lis[i++] = bot->data;
		bot = bot->next;
	}
	free(tab_lis);
	return (tab_non_lis);
}

int	ft_get_median_b(t_stack *stack_a, int size)
{
	int	size_n_l;
	int	tmp;
	int	*tab;
	int	i;

	tab = give_no_lis(stack_a, &size_n_l, lst_size(stack_a));
	i = 0;
	while (i < (size_n_l - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	tmp = tab[size_n_l / 2];
	if (size % 2 != 0)
		tmp = tab[(size_n_l / 2) - 1];
	free(tab);
	return (tmp);
}

int	stop_if_three(t_stack **stack_a)
{
	if (lst_size(*stack_a) <= 3)
	{
		ft_sort_three(stack_a, 3);
		return (1);
	}
	return (0);
}

void	push_to_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	int	*remove;
	int	median_b;
	int	i;
	int	size;

	remove = give_no_lis(*stack_a, &size, lst_size(*stack_a));
	median_b = ft_get_median_b(*stack_a, size);
	i = 0;
	while (i < size)
	{
		if (lst_sort_cir(*stack_a) || lst_sort(*stack_a))
			break ;
		if ((*stack_a)->data == remove[i])
		{
			ft_pb(stack_a, stack_b);
			else if (remove[i] > median_b)
				ft_rb(stack_b);
			i++;
		}
		else
			ft_ra(stack_a);
	}
	free(remove);
}
