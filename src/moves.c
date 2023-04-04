/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:00:00 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/04/04 19:25:59 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_node *lst)
{
	t_node	*head;
	long	swap;

	head = lst; //guardar primer nodo
	swap = lst->data;
	lst->data = lst->next->data;
	lst->next->data = swap;
	lst = head; //reasignar a primer nodo
}

void	ft_rotate(t_node **lst)
{
	t_node	*head;

	head = *lst;
	*lst = (*lst)->next;
	lstadd_back_ps(lst, head);
	head->next = NULL;
}

void	ft_rev_rotate(t_node **lst)
{
	t_node	*tail;
	t_node	*aux;

	tail = lstlast_ps(*lst);

	aux = *lst;
	while (aux->next->next)
		aux = aux->next;
	aux->next = NULL; //para que no se haga circular

	lstadd_front_ps(lst, tail);	
}
