/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:12:39 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/04/26 12:13:19 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_setindex(t_node *stack)
{
	int		nb;
	t_node	*aux;
	t_node	*aux2;

	nb = 0;
	aux = stack;
	while (aux)
	{
		nb = aux->data;
		aux2 = stack;
		while (aux2)
		{
			if (aux2->data >= nb)
				aux2->index++;
			aux2 = aux2->next;
		}
		aux = aux->next;
	}
}

void	free_lst(t_node *stack)
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

void	free_all(t_node *st_a, t_node *st_b, t_node *aux1, t_node *aux2)
{
	free_lst(st_a);
	free_lst(st_b);
	free(aux1);
	free(aux2);
}
