/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:57:30 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/04/05 17:52:33 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = ft_calloc(1, sizeof(t_node));
	stack_b = ft_calloc(1, sizeof(t_node));
	if (argc > 1)
	{
		ft_parsing(argv, stack_a);
		check_doubles(stack_a);
		
		stack_a = stack_a->next; //para que no salga primer 0
		stack_b = stack_b->next; //para que no salga primer 0
		
		
		ft_putstr_fd("BEFORE MOVE:\n", 1);
		ft_putstr_fd("STACK A:\n", 1);
		read_list(stack_a);
		ft_putstr_fd("STACK B:\n", 1);
		read_list(stack_b);
		
		write_push(&stack_a, &stack_b, PB);
		
		ft_putstr_fd("\nAFTER MOVE:\n", 1);
		ft_putstr_fd("STACK A:\n", 1);
		read_list(stack_a);
		ft_putstr_fd("STACK B:\n", 1);
		read_list(stack_b);

		return (0);
	}
	else
	{
		ft_putstr_fd("Invalid number of arguments\n", 2);
		return (1);
	}
}


/* 		
		ft_putstr_fd("BEFORE PUSH:\n", 1);
		ft_putstr_fd("STACK A:\n", 1);
		read_list(stack_a);
		ft_putstr_fd("STACK B:\n", 1);
		read_list(stack_b);
		
		ft_push(&stack_a, &stack_b);
		ft_putstr_fd("\nAFTER PUSH:\n", 1);
		ft_putstr_fd("STACK A:\n", 1);
		read_list(stack_a);
		ft_putstr_fd("STACK B:\n", 1);
		read_list(stack_b);
*/

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