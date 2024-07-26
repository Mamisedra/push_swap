/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:58:39 by mranaivo          #+#    #+#             */
/*   Updated: 2024/07/26 17:51:44 by mranaivo         ###   ########.fr       */
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
void print_params_sol(t_params *params)
{
	if (params == NULL)
	{
		ft_printf("(NULL)\n");
		return ;
	}
	ft_printf("Paramètres:\n\n");
    ft_printf(" - Content: %d\n", params->content);
    ft_printf(" - Pos_b: %d\n", params->pos_b);
    ft_printf(" - Target: %d\n", params->target);
    ft_printf(" - Cost_b: %d\n", params->cost_b);
    ft_printf(" - Cost_a: %d\n", params->cost_a);
    ft_printf(" - Cost_f: %d\n", params->cost_f);
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
	ft_printf("size A = %d\n", lst_size(stack_a));
	printList(stack_a);
	ft_printf("size B = %d\n", lst_size(stack_b));
	printList(stack_b);
	push_to_stack_b(&stack_a, &stack_b);
	ft_printf("size A = %d\n", lst_size(stack_a));
	printList(stack_a);
	ft_printf("size B = %d\n", lst_size(stack_b));
	printList(stack_b);
	t_params	*params = NULL;
	t_params	*min = NULL;
	while (stack_b)
	{
		add_params_elem_stack(stack_a, stack_b, &params);
		print_params(params);
		ft_printf("Le parametre minimum : \n");
		print_params_sol(min);
		min = ft_getcout_min(params);
		push_and_rotate(&stack_a, &stack_b, min);
		ft_printf("stack A\n");
		printList(stack_a);
		ft_printf("stack B\n");
		printList(stack_b);
		ft_free_params(&params);
	}	
	lst_clear(&stack_a);
	lst_clear(&stack_b);
    return (0);
}

// int main(int argc, char *argv[])
// {
//     t_stack	*stack_a;
// 	t_stack	*stack_b;

// 	stack_a = NULL;
// 	stack_b = NULL;
// 	if (!argv_is_not_vide(argc, argv))
// 		return (0);
// 	if (!push_list(argc, argv, &stack_a))
// 		return (lst_clear(&stack_a), 0);
// 	if (!lst_all_error(stack_a))
// 		return (lst_clear(&stack_a), 0);
// 	push_to_stack_b(&stack_a, &stack_b);
// 	t_params	*params = NULL;
// 	t_params	*min = NULL;
// 	while (stack_b)
// 	{
// 		add_params_elem_stack(stack_a, stack_b, &params);
// 		min = ft_getcout_min(params);
// 		push_and_rotate(&stack_a, &stack_b, min);
// 		ft_free_params(&params);
// 	}	
// 	lst_clear(&stack_a);
// 	lst_clear(&stack_b);
//     return (0);
// }
