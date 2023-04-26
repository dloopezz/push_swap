/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:15:12 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/04/26 12:16:49 by dlopez-s         ###   ########.fr       */
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

t_node	*lstlast_ps(t_node *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	lstadd_back_ps(t_node **lst, t_node *new)
{
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	lstlast_ps(*lst)->next = new;
}

void	lstadd_front_ps(t_node **lst, t_node *new)
{
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}
