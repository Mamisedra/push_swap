/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:40:06 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/22 15:50:27 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	lst_size(t_stack *stack)
{
	int	len;

	len = 0;
	stack->prev->next = NULL;
	while (stack != NULL)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

int	ft_check_digit(char **split)
{
	int	i;
	int	j;

	i = 0;
	while (split[i] != NULL)
	{
		j = 0;
		if (split[i][j] == '+' || split[i][j] == '-')
			j++;
		while (split[i][j] != '\0')
		{
			if (!ft_isdigit(split[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_error_split(char **split)
{
	if (!split)
	{
		ft_printf("%s %s", ERR_MSG, "Character different!!\n");
		return (1);
	}
	if (!ft_check_digit(split))
	{
		ft_printf("%s %s", ERR_MSG, "Presence des autre caracteres\n");
		return (1);
	}
	return (0);
}

void	ft_free_split(char **str)
{
	int    i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i ++;
	}
	free(str);
}

int	argv_is_not_vide(int argc, char *argv[])
{
	int	i;
	int	cpt;

	i = 1;
	cpt = 0;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) != 0)
			cpt += ft_strlen(argv[i]);
		i++;
	}
	if (cpt == 0)
	{
		ft_printf("%s %s", ERR_MSG, "Argument vide\n");
		return (0);
	}
	return (1);
}