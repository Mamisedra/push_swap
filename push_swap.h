/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:57:47 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/16 23:29:14 by mranaivo         ###   ########.fr       */
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

t_stack	*argc_to_list(int argc, char **argv);
void	lst_clear(t_stack **stack);
void	lst_delone(t_stack **stack, t_stack *to_delete);
void	lst_add_split(char *argv, t_stack **stack);
int		lst_double(t_stack *stack);

/*=============PUSH_UTILS-C================*/

int	cmp(int nb1, int nb2);

#endif