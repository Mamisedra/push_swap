/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:56:28 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/16 23:42:39 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		ft_check_digit(char **split)
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
	if (!ft_check_digit(split))
	{
		ft_printf("%s %s", ERR_MSG, "Presence des autre caracteres\n");
		return (1);
	}
	if (!split)
	{
		ft_printf("%s %s", ERR_MSG, "Character different!!\n");
		return (1);
	}
	return (0);
}

void	push_list(int argc, char *argv[], t_stack *stack_a)
{
	char	**split;
	int	i = 1;
	int	j = 0;

	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (ft_check_error_split(split))
		{
			ft_free_str(split);
			return ;
		}
		j = 0;
		while (split[j] != NULL)
		{
			lst_add_back(&stack_a, init_new_lst(ft_atoi(split[j])));
			j++;
		}
		ft_free_str(split);
		i++;
	}
}

int main(int argc, char *argv[])
{
	t_stack *stack_a;

	stack_a = init_lst();
	push_list(argc, argv, stack_a);
	lst_clear(&stack_a);
	return(0);
}