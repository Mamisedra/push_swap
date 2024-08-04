/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:31:37 by mranaivo          #+#    #+#             */
/*   Updated: 2024/08/03 14:35:51 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*get_tab_way(int size)
{
	int	*tab;
	int	i;

	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < size)
	{
		tab[i] = i;
		i++;
	}
	return (tab);
}

int	*params_lis(int size, int **tab_way, int *tab_int)
{
	int	*tab_params;
	int	i;
	int	j;

	tab_params = make_lis_tab(size, 1);
	i = 1;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (tab_int[j] < tab_int[i])
			{
				if (tab_params[j] + 1 > tab_params[i])
				{
					tab_params[i] = tab_params[j] + 1;
					tab_way[0][i] = j;
				}
			}
			j++;
		}
		i++;
	}
	return (tab_params);
}

int	get_index_max(int *tab_params, int size)
{
	int	max;
	int	i;

	max = 0;
	i = 0;
	while (i < size)
	{
		if (tab_params[i] > tab_params[max])
			max = i;
		i++;
	}
	return (max);
}

void	init_lis_params(t_stack *stack_a, int size, t_lis_params *lis_params)
{
	lis_params->tab_int = copy_list_at_tab(stack_a, size);
	lis_params->tab_way = get_tab_way(size);
	lis_params->tab_params = params_lis(size, \
				&lis_params->tab_way, lis_params->tab_int);
	lis_params->max_index = get_index_max(lis_params->tab_params, size);
}

int	*construct_lis(t_lis_params *lis_params, int size, int *size_ret)
{
	int	*tab_lis;
	int	i;
	int	j;
	int	v;

	(void)size;
	i = lis_params->max_index;
	j = lis_params->max_index;
	size_ret[0] = lis_params->tab_params[lis_params->max_index];
	tab_lis = (int *)malloc(sizeof(int) * size_ret[0]);
	if (!tab_lis)
		return (NULL);
	v = size_ret[0] - 1;
	while (v >= 0)
	{
		i = j;
		tab_lis[v] = lis_params->tab_int[i];
		j = lis_params->tab_way[i];
		v--;
	}
	return (tab_lis);
}
