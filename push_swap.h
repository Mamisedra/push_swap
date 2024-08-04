/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:15:38 by mranaivo          #+#    #+#             */
/*   Updated: 2024/08/04 11:51:40 by mranaivo         ###   ########.fr       */
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
	int				data;
	struct s_stack	*next;
}					t_stack;

typedef struct s_params
{
	int				content;
	int				pos_b;
	int				target;
	int				cost_a;
	int				cost_b;
	int				cost_f;
	struct s_params	*next;
}				t_params;

typedef struct s_lis_params
{
	int				*tab_int;
	int				*tab_way;
	int				*tab_params;
	int				max_index;
}				t_lis_params;

/*=======================MAKE_LIST==========================*/

t_stack		*new_list(int data);
void		lst_add_back(t_stack **stack_a, t_stack *new_stack);
void		lst_clear(t_stack **stack);

/*======================PUSH_LIST==========================*/

int			push_list(int argc, char *argv[], t_stack **stack_a);
int			lst_double(t_stack *stack_a);
int			lst_all_error(t_stack *stack_a);

/*=======================PUSH_CLEAR-c======================*/

int			lst_size(t_stack *stack);
int			ft_check_digit(char **split);
int			ft_check_error_split(char **split);
void		ft_free_split(char **str);
int			argv_is_not_vide(int argc, char *argv[]);

/*=====================PUSH_CLEAR_UTILS-C=====================*/

int			another_utils(char *str);
int			another_error(char **split);
int			check_empty(char *str);
int			lst_sort(t_stack *stack_a);
/*=========================PUSH-c==========================*/

void		ft_pb(t_stack **stack_a, t_stack **stack_b);
void		ft_pa(t_stack **stack_a, t_stack **stack_b);
void		ft_push_utils(t_stack **stack, t_stack *first_a);

/*==========================SWAP-C=========================*/

void		ft_ss(t_stack **stack_a, t_stack **stack_b);
void		ft_sb(t_stack **stack_b);
void		ft_sa(t_stack **stack_a);

/*=========================REVERSE=========================*/

void		ft_ra(t_stack **stack_a);
void		ft_rb(t_stack **stack_b);
void		ft_rr(t_stack **stack_a, t_stack **stack_b);

/*=========================ALL.C========================*/

int			look_error(t_stack **stack_a, t_stack **stack_b, int size);

/*=====================REVERSE_REVERSE-C==================*/

void		ft_rra(t_stack **stack_a);
void		ft_rrb(t_stack **stack_b);
void		ft_rrr(t_stack **stack_a, t_stack **stack_b);

/*=====================PUSH_SWAP-C========================*/

void		push_swap(t_stack **stack_a, t_stack **stack_b);
void		ft_sort_three(t_stack **stack_a, int size);
void		ft_remise_sort(t_stack **stack_a);
void		ft_push_to_stack_a(t_stack **stack_a, t_stack **stack_b);
void		return_s_b_to_s_a(t_stack **stack_a, t_stack **stack_b, int *tab);

/*=====================PUSH_SWAP_UTILS-C=====================*/

void		how_to_ra_rra(int i, int median, int min, t_stack **stack_a);
void		add_params_stack(t_stack *stack_a, t_stack *stack_b, \
												t_params **params);
void		ft_add_p_s(t_stack *stack_a, t_stack *stack_b, t_params **params);

/*======================ALGORITHM-C======================*/

int			lst_nbr_parasite(t_stack *stack_a);
int			*lst_remove_parasit(t_stack *stack_a, int size);
void		push_to_stack_b(t_stack **stack_a, t_stack **stack_b);

/*=========================FT_LIS-C======================*/

int			lst_sort_cir(t_stack *stack_a);
int			*copy_list_at_tab(t_stack *stack_a, int size);
int			*make_lis_tab(int size, int ch);
int			*params_lis(int size, int **tab_way, int *tab_int);
int			*ft_lis_show(t_stack *stack_a, int size, int	*size_ret);

/*=====================FT_LIS_UTILS-C=====================*/

int			*get_tab_way(int size);
int			*params_lis(int size, int **tab_way, int *tab_int);
void		init_lis_params(t_stack *stack_a, int size, \
							t_lis_params *lis_params);
int			get_index_max(int *tab_params, int size);
int			*construct_lis(t_lis_params *lis_params, int size, int *size_ret);

/*=====================SHOW_TARGET=======================*/

int			return_min(t_stack *stack);
int			return_max(t_stack *stack);
int			get_number_place(t_stack *stack, int nb, int min);
int			target_min_max(t_stack *stack, int min);
int			get_target(t_stack *stack_a, int nb, int min, int max);

/*====================LIST_PARAMS-C=====================*/

t_params	*ft_paramslast(t_params *params);
void		ft_params_add_back(t_params **params, t_params *new_p);
t_params	*new_params(t_stack *stack_a, t_stack *stack_b, int pos_b);

/*=================LIST_PARAMS_UTILS-C=================*/

void		ft_free_params(t_params **params);
void		copy_params_min(t_params	*params, int *tab);
int			*ft_getparams_min(t_params *params);

/*==========================SHOW_COST-C============================*/

int			get_cout(int size, int pos);
int			ft_get_median(int size);
void		ft_place_top_a(t_stack **stack_a, int *tab, int median_a);
void		ft_place_top_b(t_stack **stack_b, int *tab, int median_b);
t_params	*ft_getcout_min(t_params *params);

/*================PLACE_TOP-C=================*/

void		ft_place_top(t_stack **stack_a, t_stack **stack_b, int *tab);
void		ft_place_top_all(t_stack **stack_a, t_stack **stack_b, int *tab);
void		ft_rra_or_rrb(t_stack **stack_a, t_stack **stack_b, \
														int m_a, int m_b);
void		ft_ra_or_rb(t_stack **stack_a, t_stack **stack_b, int m_a, int m_b);
int			ft_get_median_b(t_stack *stack_a, int size);

#endif