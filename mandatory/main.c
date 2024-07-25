/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:58:39 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/25 15:50:14 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void printList(t_stack *stack)
{
    t_stack* current;

	if (stack == NULL)
	{
        ft_printf("La liste est vide.\n");
        return;
    }
	current = stack;
    do {
        ft_printf("-> %d\n", current->data);
        current = current->next;
    } while (current != stack);
    ft_printf("\n");
}

int main(int argc, char *argv[])
{
    t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!argv_is_not_vide(argc, argv))
		return (0);
	if (!push_list(argc, argv, &stack_a))
		return (lst_clear(&stack_a), 0);
	if (!lst_all_error(stack_a))
		return (lst_clear(&stack_a), 0);
	// push_swap(&stack_a, &stack_b);
	push_to_stack_b(&stack_a, &stack_b);
	printList(stack_a);
	ft_printf("BB:\n");
	printList(stack_b);
	ft_sort_max(&stack_a, &stack_b);
	// lst_clear(&stack_a);
	// lst_clear(&stack_b);
    return (0);
}
