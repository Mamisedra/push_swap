/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:39:47 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/31 23:10:55 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	how_to_ra_rra(int i, int median, int min, t_stack **stack_a)
{
	if (i <= median)
	{
		while ((*stack_a)->data != min)
			ft_ra(stack_a);
	}
	else
	{
		while ((*stack_a)->data != min)
			ft_rra(stack_a);
	}
}

void	add_params_stack(t_stack *stack_a, t_stack *stack_b, t_params **params)
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
		ft_params_add_back(params, \
						new_params(stack_a, tmp, pos));
		tmp = tmp->next;
		i++;
		pos++;
	}
}

void	ft_add_p_s(t_stack *stack_a, t_stack *stack_b, t_params **params)
{
	t_stack		*tmp;
	int			i;

	tmp = stack_b;
	i = 1;
	while (i)
	{
		ft_params_add_back(params, new_params(stack_a, tmp, i));
		tmp = tmp->next;
		if (tmp == stack_b)
			break ;
		i++;
	}
}
