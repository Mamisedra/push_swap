/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:57:47 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/17 12:41:29 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "ft_libft/libft.h"
# include "ft_printf/ft_printf.h"
# define ERR_MSG "\033[1;31m ==>ERROR:"

typedef struct s_stack
{
	struct s_stack	*prev;
	int				data;
	struct s_stack	*next;
}					t_stack;
/*==============MAKE_LIST-C================*/

t_stack	*init_lst(void);
t_stack	*init_new_lst(int index);
void	lst_add_front(t_stack **stack, t_stack *new_stack);
void	lst_add_back(t_stack **stack, t_stack *new_stack);
int		lst_size(t_stack *stack);

/*==============PUSH_LIST===================*/

int		ft_check_digit(char **split);
int		ft_check_error_split(char **split);
int		push_list(int argc, char *argv[], t_stack *stack_a);
int 	ft_is_trie(t_stack *stack_a);
int		check_error_list(t_stack *stack_a);

/*=============ARGC_TO_LIST-C==============*/

void	lst_clear(t_stack **stack);
void	lst_delone(t_stack **stack, t_stack *to_delete);
void	ft_free_str(char **str);
int		lst_double(t_stack *stack);
int		cmp(int nb1, int nb2);

/*=================PUSH_SWAP-C==============*/

void	push_swap(t_stack **stack_a, t_stack **stack_b);

#endif