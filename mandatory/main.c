/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:17:17 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/17 15:15:04 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int main(int argc, char *argv[])
{
	t_stack *stack_a;
	t_stack	*stack_b;

	stack_a = init_lst();
	if (!push_list(argc, argv, stack_a))
	{
		lst_clear(&stack_a);
		return (0);
	}
	if (check_error_list(stack_a))
	{
		lst_clear(&stack_a);
		return (0);
	}
	stack_b = init_lst();
	push_swap(&stack_a, &stack_b);
	lst_clear(&stack_b);
	lst_clear(&stack_a);
	return(0);
}
