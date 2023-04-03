/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:00:00 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/04/03 18:48:54 by dlopez-s         ###   ########.fr       */
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

void	ft_rotate(t_node *lst) //funciona pero no es eso lo que tiene que hacer
{
	t_node	*aux;
	t_node	*rec;
	long	swap;

	aux = lst;
	rec = lst;
	lst = lst->next;
	
	swap = lst->data;
	while (rec->next)
		rec = rec->next;
	
	lst->data = rec->data;
	while (lst->next)
		lst = lst->next;
	lst->data = swap;
	
	lst = aux;
}
