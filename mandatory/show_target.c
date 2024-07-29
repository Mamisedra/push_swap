/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 12:05:44 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/29 14:54:15 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	return_min(t_stack *stack)
{
	int		min;
	t_stack	*tmp;

	min = stack->data;
	tmp = stack->next;
	while (tmp != stack)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min);
}

int	return_max(t_stack *stack)
{
	int		max;
	t_stack	*tmp;

	max = stack->data;
	tmp = stack->next;
	while (tmp != stack)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->next;
	}
	return (max);
}

int		get_number_place(t_stack *stack, int nb, int min)
{
	t_stack	*tmp;
	int		its;

	tmp = stack;
	if (nb < min)
		return (min);
	while (tmp->data != min)
		tmp = tmp->next;
	if (tmp->data == min)
	{
		its = tmp->data;
		tmp = tmp->next;
	}
	while (tmp->data != min)
	{
		if (tmp->data > nb && its <= nb)
		{
			its = tmp->data;
			break ;
		}
		its = tmp->data;
		tmp = tmp->next;
	}
	return (its);
}

int	target_min_max(t_stack *stack, int min)
{
	int	target;
	t_stack	*tmp;

	target = 1;
	tmp = stack;
	if (tmp->data == min)
		return (target);
	while (tmp->data != min)
	{
		target++;
		tmp = tmp->next;
	}
	return (target);
}

int	get_target(t_stack *stack_a, int nb, int min, int max)
{
	t_stack	*tmp;
	int		ref;
	int		target;

	target = 1;
	if (nb < min || nb > max)
		return (target_min_max(stack_a, min));
	tmp = stack_a;
	ref = get_number_place(tmp, nb, min);
	tmp = stack_a;
	while (1)
	{
		if (tmp->data == ref)
			break ;
		tmp = tmp->next;
		target++;
	}
	return (target);
}

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
	if (pos < median)
		cout = pos - 1;
	else
	 	cout = size - pos + 1;
	return (cout);
}

void	ft_add_params_stack(t_stack *stack_a, t_stack *stack_b, t_params **params)
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

int		ft_get_median(int size)
{
	int	median;

	median = 0;
	if (size % 2 == 0)
		median = size / 2;
	else
	 	median = (size + 1) / 2;
	return (median);
}

void	ft_place_top_a(t_stack **stack_a, int *tab, int size_a, int median_a)
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

void	ft_place_top_b(t_stack **stack_b, int *tab, int size_b, int median_b)
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

void	return_stack_b_to_stack_a(t_stack **stack_a, t_stack **stack_b, int *tab)
{
	int	size_a;
	int	size_b;
	int	median_a;
	int	median_b;

	size_a = lst_size(*stack_a);
	size_b = lst_size(*stack_b);
	median_a = ft_get_median(size_a);
	median_b = ft_get_median(size_b);
	ft_place_top_b(stack_b, tab, size_b, median_b);
	ft_place_top_a(stack_a, tab, size_a, median_a);
	if (tab[0] == (*stack_b)->data)
		ft_pa(stack_a, stack_b);
}

void	ft_push_to_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	t_params	*params;
	int			*tab;

	params = NULL;
	while (*stack_b)
	{
		ft_add_params_stack(*stack_a, *stack_b, &params);
		tab = ft_getparams_min(params);
		if (!tab)
			return ;
		return_stack_b_to_stack_a(stack_a, stack_b, tab);
		ft_free_params(&params);
		free(tab);
	}
}

void	ft_remise_sort(t_stack **stack_a)
{
	int	size;
	int	median;
	int	min;
	int	i;
	t_stack	*stack;

	size = lst_size(*stack_a);
	median = ft_get_median(size);
	min = return_min(*stack_a);
	stack = *stack_a;
	i = 1;
	while (1)
	{
		if (stack->data > stack->next->data || (stack == *stack_a && i != 1))
			break ;
		i++;
		stack = stack->next;
	}
	if (i != size)
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
}
