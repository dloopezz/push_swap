/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:00:00 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/04/03 18:30:56 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_node *lst)
{
	t_node	*aux;
	long	swap;

	aux = lst; //guardar primer nodo
	lst = lst->next; //avanzar uno para saltar el 0 del principio
	swap = lst->data;
	lst->data = lst->next->data;
	lst->next->data = swap;
	lst = aux; //reasignar a primer nodo
}

void	ft_rotate(t_node *lst)
{
	t_node	*aux;
	t_node	*first;
	long	swap;

	aux = lst;
	first = lst;
	lst = lst->next;
	
	ft_lstdelone(lst);
	while (lst->next)
		lst = lst->next;
	ft_lstadd_back(lst, first);
	
	lst = aux;
}

/* void	ft_rev_rotate(t_node *lst)
{
	
} */
