/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:28:20 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/24 17:49:23 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static long long	ft_atoi_long(char *str)
{
	int			i;
	long long	result;
	int			sign;

	sign = 1;
	i = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] >= 9 && str[i] <=13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	result = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			break ;
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

int	push_list(int argc, char *argv[], t_stack **stack_a)
{
	char	**split;
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (ft_check_error_split(split))
			return (ft_free_split(split), 0);
		j = 0;
		while (split[j]  != NULL)
		{
			if ((ft_atoi_long(split[j]) > 2147483647) || (ft_atoi_long(split[j]) < -2147483648))
				return (ft_printf("%s %s\n", ERR_MSG, "Argument hors int"),ft_free_split(split), 0);
			lst_add_back(stack_a, new_list(ft_atoi(split[j])));
			j++;
		}
		ft_free_split(split);
		i++;
	}
	return (1);
}

int	lst_double(t_stack *stack_a)
{
	t_stack *stop;
	t_stack	*bot;
	t_stack	*next_stack;

	stop = stack_a->prev;
	bot = stack_a;
	while (bot != stop)
	{
		next_stack = bot->next;
		while (next_stack != stack_a)
		{
			if (next_stack->data == bot->data)
				return (1);
			next_stack = next_stack->next;
		}
		bot = bot->next;
	}
	return (0);
}

int	lst_sort(t_stack *stack_a)
{
	t_stack *stop;
	t_stack	*bot;

	stop = stack_a->prev;
	bot = stack_a;
	while (bot != stop)
	{
		if (bot->data > bot->next->data)
			return (0);
		bot = bot->next;
	}
	return (1);
}

int	lst_all_error(t_stack *stack_a)
{
	if (lst_double(stack_a))
	{
		ft_printf("%s %s\n", ERR_MSG, "Arguments doubles");
		return (0);
	}
	if (lst_sort(stack_a))
		return (0);
	return (1);
}
