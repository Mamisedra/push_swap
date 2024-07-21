/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:15:38 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/21 14:37:41 by mranaivo         ###   ########.fr       */
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

/*=======================MAKE_LIST==========================*/
t_stack	*new_list(int data);
void	lst_add_back(t_stack **stack_a, t_stack *new_stack);
void	lst_add_front(t_stack **stack_a, t_stack *new_stack);
void	lst_clear(t_stack **stack);
void 	lst_delone(t_stack **stack);

/*======================PUSH_LIST==========================*/

int		push_list(int argc, char *argv[], t_stack **stack_a);
int		lst_double(t_stack *stack_a);
int		lst_sort(t_stack *stack_a);
int		lst_all_error(t_stack *stack_a);

/*=======================PUSH_CLEAR-c=======================*/

int		argv_is_not_vide(int argc, char *argv[]);
int		ft_check_digit(char **split);
int		ft_check_error_split(char **split);
void	ft_free_split(char **str);

/*========================PUSH-c=======================*/

void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_pa(t_stack **stack_a, t_stack **stack_b);

/*========================SWAP-C=======================*/
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
void	ft_sb(t_stack **stack_b);
void	ft_sa(t_stack **stack_a);

/*=======================REVERSE========================*/

void	ft_ra(t_stack **stack_a);
void	ft_rb(t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);

/*=====================REVERSE_REVERSE-C====================*/

void	ft_rra(t_stack **stack_a);
void	ft_rrb(t_stack **stack_b);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);

/*=====================PUSH_SWAP-C====================*/

void	push_swap(t_stack **stack_a, t_stack **stack_b);

/*======================ALGORITHM-C======================*/

int		cmp(int a, int b);

#endif