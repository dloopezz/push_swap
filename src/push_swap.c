/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:57:30 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/04/14 16:01:08 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	// atexit(ft_leaks);
	stack_a = ft_calloc(1, sizeof(t_node));
	stack_b = ft_calloc(1, sizeof(t_node));
	if (argc > 1)
	{
		//8 leaks en parsing, otros leaks por avanzar stack_a al principio
		ft_parsing(argv, stack_a);
		check_doubles(stack_a);

		stack_a = stack_a->next; //para que no salga primer 0
		stack_b = stack_b->next; //para que no salga primer 0
	
		if (!check_ordered(stack_a))
			choose_algorythm(&stack_a, &stack_b);
		else
			printf("Ordered\n"); //este else se puede quitar luego
		
		// read_list(stack_a);
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