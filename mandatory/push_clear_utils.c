/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_clear_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:16:44 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/31 23:02:57 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	another_utils(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == '-' || str[i] == '+') && (!ft_isdigit(str[i + 1])))
			return (1);
		i++;
	}
	return (0);
}

int	another_error(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (another_utils(split[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_empty(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

int	lst_sort(t_stack *stack_a)
{
	t_stack	*stop;
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
