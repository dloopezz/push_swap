/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:57:30 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/04/19 18:30:37 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void free_lst(t_node *stack)
{
	t_node	*aux;

	while (stack)
	{
		aux = stack->next;
		stack->data = 0;
		free (stack);
		stack = aux;
	}
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*aux1;
	t_node	*aux2;

	atexit(ft_leaks);
	stack_a = ft_calloc(1, sizeof(t_node));
	stack_b = ft_calloc(1, sizeof(t_node));
	aux1 = stack_a;
	aux2 = stack_b;
	if (argc > 1)
	{
		ft_parsing(argv, stack_a);
		check_doubles(stack_a);
		stack_a = stack_a->next; //para que no salga primer 0
		stack_b = stack_b->next; //para que no salga primer 0


		if (!check_ordered(stack_a))
		{
			choose_algorythm(&stack_a, &stack_b);
		}
		
		// read_list(stack_a);
		stack_a = aux1;
		stack_b = aux2;
		free_lst(stack_a);
		free_lst(stack_b);
	
		return (0);
	}
	else
	{
		ft_putstr_fd("Invalid number of arguments\n", 2);
		return (1);
	}
}


/*		GET MIN		

		aux = stack_a->next;
		min = stack_a;
		while (aux)
		{
			if (aux->data < min->data)
				min = aux;
			aux = aux->next;
		}
		printf("\nMIN: %li\n", min->data);
*/

 /* 	ft_putstr_fd("\nBEFORE MOVE:\n", 1);
		ft_putstr_fd("STACK A:\n", 1);
		read_list(stack_a);
		ft_putstr_fd("STACK B:\n", 1);
		read_list(stack_b);

		ft_putstr_fd("\n------------------", 1);
		ft_putstr_fd("\nMOVES:\n", 1);
		write_swap(stack_a, stack_b, SA);
		ft_putstr_fd("------------------\n", 1);
		
		ft_putstr_fd("\nAFTER MOVE:\n", 1);
		ft_putstr_fd("STACK A:\n", 1);
		read_list(stack_a);
		ft_putstr_fd("STACK B:\n", 1);
		read_list(stack_b);
		ft_putstr_fd("\n", 1); */