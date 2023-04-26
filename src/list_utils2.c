/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:11:57 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/04/26 12:17:14 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
