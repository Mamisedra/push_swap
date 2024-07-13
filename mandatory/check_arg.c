/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:56:59 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/11 14:11:24 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_str(char **str)
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

char	*ft_atoi_str(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = 1;
		i ++;
	}
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return NULL;
		i++;
	}
	return (str);
}

int	signe_error(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		if (ft_atoi_str(str[i]) == NULL)
		{
			ft_free_str(str);
			return (1);
		}
		i++;
	}
	return (0);
}

int	no_double(char **str)
{
	int	i;
	int j;

	i = 0;
	while (str[i] != NULL)
	{
		j = i + 1;
		while (str[j] != NULL)
		{
			if (ft_strncmp(str[i],str[j], ft_strlen(str[i])) == 0)
			{
				ft_free_str(str);
				return (1);	
			}
			j ++;
		}
		i ++;
	}
	return (0);
}

char	**argc_split(char *str)
{
	char	**new_str;

	new_str = ft_split(str, ' ');
	if (!new_str)
	{
		ft_printf("\033[1;31mERROR: \033[0;37mSplit\033[0m\n");
		return (NULL);
	}
	if (signe_error(new_str))
	{
		ft_printf("\033[1;31mERROR: \033[0;37mSign\033[0m\n");
		return (NULL);
	}
	if (no_double(new_str))
	{
		ft_printf("\033[1;31mERROR: \033[0;37mDouble\033[0m\n");
		return (NULL);
	}
	return (new_str);
}