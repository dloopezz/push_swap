/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:15:12 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/04/19 15:18:48 by dlopez-s         ###   ########.fr       */
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

void	read_list(t_node *stack)
{
	t_node	*aux;

	aux = stack;
	while (aux)
	{
		printf("Node content, index: %li, ", aux->data);
		printf("%i\n", aux->index);
		aux = aux->next;
	}
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

int	ft_listsize(t_node *stack)
{
	t_node	*aux;
	int		i;

	i = 0;
	aux = stack;
	while (aux)
	{
		aux = aux->next;
		i++;
	}
	return (i);
}

int	lst_getmin(t_node *stack)
{
	t_node	*aux;
	t_node	*min;

	aux = stack->next;
	min = stack;
	while (aux)
	{
		if (aux->data < min->data)
			min = aux;
		aux = aux->next;
	}
	// printf("\nMIN: %li\n", min->data);
	return (min->data);
}

int	lst_getmax(t_node *stack)
{
	t_node	*aux;
	t_node	*max;

	aux = stack->next;
	max = stack;
	while (aux)
	{
		if (aux->data > max->data)
			max = aux;
		aux = aux->next;
	}
	// printf("\nMAX: %li\n", max->data);
	return (max->data);
}

int	lst_maxindex(t_node *stack)
{
	t_node	*aux;
	t_node	*max;

	aux = stack->next;
	max = stack;
	while (aux)
	{
		if (aux->index > max->index)
			max = aux;
		aux = aux->next;
	}
	// printf("\nMAX: %i\n", max->index);
	return (max->index);
}

int	lst_getindex(long num, t_node *stack)
{
	t_node	*aux;
	int		i;

	i = 0;
	aux = stack;
	while (aux)
	{
		if (aux->data == num)
			return (i);
		aux = aux->next;
		i++;
	}
	return (-1);
}

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
