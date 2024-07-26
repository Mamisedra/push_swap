/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:15:38 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/26 16:03:14 by mranaivo         ###   ########.fr       */
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

typedef struct s_params
{
	int	content;
	int	pos_b;
	int	target;
	int	cost_a;
	int	cost_b;
	int	cost_f;
	struct s_params	*next;
}				t_params;

void printList(t_stack *stack);
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

/*=======================PUSH_CLEAR-c======================*/

int		argv_is_not_vide(int argc, char *argv[]);
int		ft_check_digit(char **split);
int		ft_check_error_split(char **split);
void	ft_free_split(char **str);
int		lst_size(t_stack *stack);

/*=========================PUSH-c==========================*/

void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_pa(t_stack **stack_a, t_stack **stack_b);

/*==========================SWAP-C=========================*/

void	ft_ss(t_stack **stack_a, t_stack **stack_b);
void	ft_sb(t_stack **stack_b);
void	ft_sa(t_stack **stack_a);

/*=========================REVERSE=========================*/

void	ft_ra(t_stack **stack_a);
void	ft_rb(t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);

/*=====================REVERSE_REVERSE-C==================*/

void	ft_rra(t_stack **stack_a);
void	ft_rrb(t_stack **stack_b);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);

/*=====================PUSH_SWAP-C========================*/

void	add_params_elem_stack(t_stack *stack_a, t_stack *stack_b, t_params **params);
t_params	*ft_getcout_min(t_params *params);
void	push_and_rotate(t_stack **stack_a, t_stack **stack_b, t_params *params);

/*======================ALGORITHM-C======================*/

int		lst_nbr_parasite(t_stack *stack_a);
int		*lst_remove_parasit(t_stack *stack_a);
void	push_to_stack_b(t_stack **stack_a, t_stack **stack_b);
void	remove_action(t_stack **stack_a);

/*=====================GET_COUNT-C========================*/

int		search_position(t_stack *stack_a, int nb, int max, int min);
int 	get_count(t_stack *stack, int size,int pos);

/*=====================SHOW_TARGET=======================*/

int		return_max(t_stack *stack_a);
int		return_min(t_stack *stack_a);
int		target_max(t_stack *stack_a, int l_max);
int		target_min(t_stack *stack_a, int min);
int		ft_show_target(t_stack *stack_a, int nb);

/*====================LIST_PARAMS-C=====================*/

t_params	*ft_paramslast(t_params *params);
void		ft_params_add_back(t_params **params, t_params *new_p);
void		ft_free_params(t_params **params);
t_params	*new_params(t_stack *stack_a, t_stack *stack_b, int pos_b);


void print_params(t_params *params);
void printList(t_stack *stack);

#endif