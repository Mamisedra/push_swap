/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:31:31 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/25 16:09:45 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void ft_params_add_back(t_params **params, t_params *new_p)
{
    t_params *current;

    if (*params == NULL)
        *params = new_p;
    else
    {
		current = *params;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_p;
    }
}

int	ft_give_new_pos(t_stack *stack_a, int content)
{
	int		target;
	int		last_content;
	int		pos;
	t_stack	*brk;

	target = 1;
	pos = 1;
	stack_a->prev->next = NULL;
	printf("content : %d\n", content);
	while (NULL != stack_a)
	{
		if (stack_a->data > content && stack_a->data > last_content)
		{
			last_content = stack_a->data;
			target = pos;
		}
		stack_a = stack_a->next;
		pos++;
	}
	ft_printf("%d\n", target);
	return (target);
}

int	ft_give_cost(t_stack *stack_a, int target)
{
	int	dm;
	int	len;
	int	cost_a;

	len = lst_size(stack_a);
	if (len % 2 == 0)
		dm = len / 2;
	else
		dm = (len + 1) / 2;
	cost_a = 0;
	if (target <= dm)
		cost_a = target - 1;
	else
		cost_a = len - target + 1;
	ft_printf("%d\n", cost_a);
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

t_params	*new_params(t_stack *stack_a, t_stack *stack_b, int pos_b)
{
	t_params	*to_ret;
	printf("deux\n");
	to_ret = malloc(sizeof(t_params));
	if (!to_ret)
		return (NULL);
	to_ret->content = stack_b->data;
	to_ret->pos_b = pos_b;
	to_ret->target = ft_give_new_pos(stack_a, stack_b->data);
	to_ret->cost_a = ft_give_cost(stack_a, to_ret->target);
	to_ret->cost_b = ft_give_cost(stack_b, pos_b);
	to_ret->cost_f = to_ret->cost_a + to_ret->cost_b + 1;
	to_ret->next = NULL;
	return (to_ret);
}