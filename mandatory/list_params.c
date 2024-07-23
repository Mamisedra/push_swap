/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:31:31 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/23 17:40:04 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_params_add_back(t_params **params, t_params *new_p)
{
	if (*params == NULL)
		*params = new_p;
	while (*params)
	{
		if ((*params)->next == NULL)
			break ;
		*params = (*params)->next;
	}
	(*params)->next = new_p;
}

int	ft_give_new_pos(t_stack *stack_b, int content)
{
	int	pos_b;
	t_stack	*brk;

	pos_b = 1;
	if (stack_b->data < content)
		return (pos_b);
	brk = stack_b;
	while (stack_b != brk)
	{
		if (stack_b->data > content)
		{
			if (stack_b->next->data < content)
				return (pos_b);
		}
		stack_b = stack_b->next;
		pos_b++;
	}
	return (pos_b);
}

int	ft_give_cost(t_stack *stack_a, int pos_a)
{
	int	dm;
	int	len;
	int	cost_a;

	len = lst_size(stack_a);
	dm = (len + 1) / 2;
	cost_a = 0;
	if (pos_a <= dm)
		cost_a = pos_a - 1;
	else
		cost_a = len - pos_a + 1;
	return (cost_a);
}

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

t_params	*new_params(t_stack *stack_a, t_stack *stack_b, int pos_a)
{
	t_params	*to_ret;

	to_ret = malloc(sizeof(t_params));
	if (!to_ret)
		return (NULL);
	to_ret->content = stack_a->data;
	to_ret->pos_a = pos_a;
	to_ret->pos_b = ft_give_new_pos(stack_b, pos_a);
	to_ret->cost_a = ft_give_cost(stack_a, pos_a);
	to_ret->cost_b = ft_give_cost(stack_b, to_ret->pos_b);
	to_ret->cost_f = to_ret->cost_a + to_ret->cost_b + 1;
	return (to_ret);
}