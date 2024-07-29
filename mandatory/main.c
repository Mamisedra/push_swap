/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:58:39 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/29 15:54:46 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void printList(t_stack *stack)
{
    t_stack* current;

	if (stack == NULL)
	{
        ft_printf("\t La liste est vide.\n\n");
        return ;
    }
	current = stack;
    while (1)
	{
        ft_printf("-> %d\n", current->data);
        current = current->next;
		if (current == stack)
			break ;
	}
    ft_printf("\n");
}
void print_params_sol(int *tab)
{
	if (tab == NULL)
	{
		ft_printf("tab = (NULL)\n");
		return ;
	}
	ft_printf("\t===========Paramètres-Minimum===========\n\n");
    ft_printf(" - Content: %d |", tab[0]);
    ft_printf(" - Pos_b: %d |", tab[1]);
    ft_printf(" - Target: %d |", tab[2]);
    ft_printf(" - Cost_b: %d |", tab[3]);
    ft_printf(" - Cost_a: %d |", tab[4]);
    ft_printf(" - Cost_f: %d |\n", tab[5]);
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
	push_to_stack_b(&stack_a, &stack_b);
	ft_push_to_stack_a(&stack_a, &stack_b);
	ft_remise_sort(&stack_a);
	lst_clear(&stack_a);
	lst_clear(&stack_b);
    return (0);
}