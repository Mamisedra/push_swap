/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:03:27 by mranaivo          #+#    #+#             */
/*   Updated: 2024/08/02 11:52:50 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_cout(int size, int pos)
{
	int	median;
	int	cout;

	median = 0;
	if (size % 2 == 0)
		median = size / 2;
	else
		median = (size + 1) / 2;
	cout = 0;
	if (pos <= median)
		cout = pos - 1;
	else
		cout = size - pos + 1;
	return (cout);
}

int	ft_get_median(int size)
{
	int	median;

	median = 0;
	median = (size + 1) / 2;
	return (median);
}

void	ft_place_top_a(t_stack **stack_a, int *tab, int median_a)
{
	if (tab[2] <= median_a)
	{
		while (tab[4] != 0)
		{
			ft_ra(stack_a);
			tab[4]--;
		}
	}
	else if (tab[2] > median_a)
	{
		while (tab[4] != 0)
		{
			ft_rra(stack_a);
			tab[4]--;
		}
	}
}

void	ft_place_top_b(t_stack **stack_b, int *tab, int median_b)
{
	if (tab[1] <= median_b)
	{
		while (tab[3] != 0)
		{
			ft_rb(stack_b);
			tab[3]--;
		}
	}
	else if (tab[1] > median_b)
	{
		while (tab[3] != 0)
		{
			ft_rrb(stack_b);
			tab[3]--;
		}
	}
}

t_params	*ft_getcout_min(t_params *params)
{
	t_params	*ret;

	if (params == NULL)
		return (NULL);
	ret = params;
	while (params != NULL)
	{
		if (ret->cost_f > params->cost_f)
			ret = params;
		params = params->next;
	}
	return (ret);
}
