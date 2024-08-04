/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_top.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:02:12 by mranaivo          #+#    #+#             */
/*   Updated: 2024/08/02 11:51:26 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_place_top(t_stack **stack_a, t_stack **stack_b, int *tab)
{
	int	median_a;
	int	median_b;

	median_a = ft_get_median(lst_size(*stack_a));
	median_b = ft_get_median(lst_size(*stack_b));
	if ((tab[2] <= median_a && tab[1] <= median_b) || \
		(tab[2] > median_a && tab[1] > median_b))
	{
		ft_place_top_all(stack_a, stack_b, tab);
	}
	else
	{
		ft_place_top_a(stack_a, tab, median_a);
		ft_place_top_b(stack_b, tab, median_b);
	}
}

void	ft_rra_or_rrb(t_stack **stack_a, t_stack **stack_b, int m_a, int m_b)
{
	while (m_a > 0 && m_b > 0)
	{
		ft_rrr(stack_a, stack_b);
		m_a--;
		m_b--;
	}
	while (m_a > 0)
	{
		ft_rra(stack_a);
		m_a--;
	}
	while (m_b > 0)
	{
		ft_rrb(stack_b);
		m_b--;
	}
}

void	ft_ra_or_rb(t_stack **stack_a, t_stack **stack_b, int m_a, int m_b)
{
	while (m_a > 0 && m_b > 0)
	{
		ft_rr(stack_a, stack_b);
		m_a--;
		m_b--;
	}
	while (m_a > 0)
	{
		ft_ra(stack_a);
		m_a--;
	}
	while (m_b > 0)
	{
		ft_rb(stack_b);
		m_b--;
	}
}

void	ft_place_top_all(t_stack **stack_a, t_stack **stack_b, int *tab)
{
	int	moves_a;
	int	moves_b;
	int	median_a;
	int	median_b;

	moves_a = tab[4];
	moves_b = tab[3];
	median_a = ft_get_median(lst_size(*stack_a));
	median_b = ft_get_median(lst_size(*stack_b));
	if (tab[2] <= median_a && tab[1] <= median_b)
		ft_ra_or_rb(stack_a, stack_b, moves_a, moves_b);
	else if (tab[2] > median_a && tab[1] > median_b)
		ft_rra_or_rrb(stack_a, stack_b, moves_a, moves_b);
}
