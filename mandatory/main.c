/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:58:39 by mranaivo          #+#    #+#             */
/*   Updated: 2024/08/03 11:15:40 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	if (!argv_is_not_vide(argc, argv))
		return (0);
	if (!push_list(argc, argv, &stack_a))
	{
		lst_clear(&stack_a);
		return (0);
	}
	if (!lst_all_error(stack_a))
	{
		lst_clear(&stack_a);
		return (0);
	}
	push_swap(&stack_a, &stack_b);
	lst_clear(&stack_a);
	lst_clear(&stack_b);
	return (0);
}
