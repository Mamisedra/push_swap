/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:57:15 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/29 14:35:42 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void print_params(t_params *params)
{
	if (params == NULL)
	{
		printf("Paramas = (NULL)\n");
		return;
	}
	ft_printf("\t===========Paramètres===========\n\n");
    while (params != NULL)
    {
		ft_printf(" - Content: %d |", params->content);
		ft_printf(" - Pos_b: %d |", params->pos_b);
		ft_printf(" - Target: %d |", params->target);
		ft_printf(" - Cost_b: %d |", params->cost_b);
		ft_printf(" - Cost_a: %d |", params->cost_a);
		ft_printf(" - Cost_f: %d |\n", params->cost_f);
        params = params->next;
    }
}

void	add_params_elem_stack(t_stack *stack_a, t_stack *stack_b, t_params **params)
{
	t_stack	*tmp;
	int		i;
	int		size;
	int		pos;

	if (stack_b == NULL)
		return ;
	tmp = stack_b;
	pos = 1;
	i = 0;
	size = lst_size(stack_b);
	while (i != size)
	{
		ft_params_add_back(params, new_params(stack_a, tmp, pos));
		tmp = tmp->next;
		i++;
		pos++;
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
			ret  = params;
		params = params->next;
	}
	return (ret);
}
