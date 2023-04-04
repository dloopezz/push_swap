/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:57:30 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/04/04 18:35:48 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*add_node(t_node *stack_a, long num)
{
	t_node	*new;
	t_node	*aux;

	new = (t_node *)ft_calloc(1, sizeof(t_node));
	new->data = num;
	new->next = NULL;
	if (!stack_a)
		stack_a = new;
	else
	{
		aux = stack_a;
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
	return (stack_a);
}

void	read_list(t_node *stack_a)
{
	t_node	*aux;


	//aux = stack_a->next; //para que no salga primer 0
	aux = stack_a;
	while (aux)
	{
		printf("Node content: %li\n", aux->data);
		aux = aux->next;
	}
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	// t_node	*aux;

	stack_a = ft_calloc(1, sizeof(t_node));
	stack_b = ft_calloc(1, sizeof(t_node));
	if (argc > 1)
	{
		ft_parsing(argv, stack_a);
		check_doubles(stack_a);
		
		// aux = stack_a;
		stack_a = stack_a->next; //para que no salga primer 0
		ft_putstr_fd("BEFORE ROTATE:\n", 1);
		read_list(stack_a);
		ft_rev_rotate(&stack_a);
		// ft_swap(stack_a);
		ft_putstr_fd("\nAFTER ROTATE:\n", 1);
		read_list(stack_a);
		// ft_putstr_fd("\nAUX:\n", 1);
		// read_list(aux);

		return (0);
	}
	else
	{
		ft_putstr_fd("Invalid number of arguments\n", 2);
		return (1);
	}
}
