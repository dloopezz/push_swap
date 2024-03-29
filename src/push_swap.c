/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:57:30 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/05/23 14:45:47 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void read_list(t_node *stack)
// {
// 	while (stack)
// 	{
// 		printf("Node content: %li\n", stack->data);
// 		stack = stack->next;
// 	}
// }

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*aux1;
	t_node	*aux2;

	stack_a = ft_calloc(1, sizeof(t_node));
	stack_b = ft_calloc(1, sizeof(t_node));
	aux1 = stack_a;
	aux2 = stack_b;
	if (argc > 1)
	{
		ft_parsing(argv, stack_a);
		check_doubles(stack_a);
		stack_a = stack_a->next;
		stack_b = stack_b->next;
		if (!check_ordered(stack_a))
			choose_algorythm(&stack_a, &stack_b);
		// read_list(stack_a);
		free_all(stack_a, stack_b, aux1, aux2);
		return (0);
	}
	else
		return (1);
}
