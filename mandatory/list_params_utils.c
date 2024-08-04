/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_params_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:50:25 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/31 23:03:20 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_params(t_params **params)
{
	t_params	*tmp;

	tmp = *params;
	while (*params)
	{
		tmp = *params;
		*params = (*params)->next;
		free(tmp);
	}
	*params = NULL;
}

void	copy_params_min(t_params	*params, int *tab)
{
	tab[0] = params->content;
	tab[1] = params->pos_b;
	tab[2] = params->target;
	tab[3] = params->cost_b;
	tab[4] = params->cost_a;
	tab[5] = params->cost_f;
}

int	*ft_getparams_min(t_params *params)
{
	int			*tab;
	t_params	*params_min;
	t_params	*begin;

	tab = malloc(sizeof(int) * 6);
	if (!tab)
		return (NULL);
	params_min = params;
	begin = params;
	while (params != NULL)
	{
		if (params->cost_f < params_min->cost_f)
			params_min = params;
		params = params->next;
	}
	params = begin;
	copy_params_min(params_min, tab);
	return (tab);
}
