/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:57:47 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/11 16:43:58 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "ft_libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_stack
{
	struct s_stack	*prev;
	int					data;
	struct s_stack	*next;
}					t_stack;

/*=============CHECK_ARG-C===============*/

void	ft_free_str(char **str);
char	*ft_atoi_str(char *str);
int		signe_error(char **str);
int		no_double(char **str);
char	**argc_split(char *str);

/*==============MAKE_LIST-C================*/

t_stack	*init_lst(void);
t_stack	*init_new_lst(int index);
void	lst_add_front(t_stack **stack, t_stack *new_stack);
void	lst_add_back(t_stack **stack, t_stack *new_stack);
int		lst_size(t_stack *stack);

/*=============ARGC_TO_LIST-C==============*/

t_list	*argc_to_list(int argc, char **argv);
void	lst_clear(t_stack **stack);
void	lst_delone(t_stack **stack, t_stack *to_delete);

#endif