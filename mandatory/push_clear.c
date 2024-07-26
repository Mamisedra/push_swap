/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:40:06 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/26 17:28:04 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int lst_size(t_stack *stack)
{
    int len;
    t_stack *current;

    if (stack == NULL)
        return 0;
    current = stack;
    len = 0;
    while (current)
    {
        len++;
        current = current->next;
        if (current == stack) // Condition pour liste circulaire
            break;
        if (current == NULL) // Condition pour liste simplement chaînée
            break;
    }
    return len;
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