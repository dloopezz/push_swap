/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:00:00 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/04/26 12:26:13 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	aux->next = NULL;
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
		aux->next = NULL;
	}
	else
		lstadd_front_ps(stack_b, aux);
}
