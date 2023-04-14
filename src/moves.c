/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:00:00 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/04/14 16:03:45 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//FALLOS CUANDO STACK B NO EXISTE
void	ft_swap(t_node *stack)
{
	long	swap;

	swap = stack->data;
	stack->data = stack->next->data;
	stack->next->data = swap;
}

void	ft_rotate(t_node **stack)
{
	t_node	*head;

	head = *stack;
	*stack = (*stack)->next;
	lstadd_back_ps(stack, head);
	head->next = NULL;
}

void	ft_rev_rotate(t_node **stack)
{
	t_node	*tail;
	t_node	*aux;

	tail = lstlast_ps(*stack);
	aux = *stack;
	while (aux->next->next)
		aux = aux->next;
	aux->next = NULL; //recorremos la lista hasta el penúltimo (que ahora es el último) y le decimos que después se acaba para que no se haga circular
	lstadd_front_ps(stack, tail);	
}

void	ft_push(t_node **stack_a, t_node **stack_b)
{
	t_node	*aux;

	aux = *stack_a;
	*stack_a = (*stack_a)->next;
	if (!(*stack_b))
	{
		lstadd_front_ps(stack_b, aux);
		aux->next = NULL; //solo seteamos a NULL el siguiente cuando el que añadimos es el último, es decir, el del primer push
	}
	else
		lstadd_front_ps(stack_b, aux);
}
