/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorytms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:25:47 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/04/26 12:05:08 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorythm3(t_node **stack_a, t_node **stack_b)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->data;
	b = (*stack_a)->next->data;
	c = (*stack_a)->next->next->data;
	if (a > b && a < c && b < c)
		do_swap(*stack_a, *stack_b, SA);
	else if (a > b && a > c && b > c)
	{
		do_swap(*stack_a, *stack_b, SA);
		do_rev_rotate(stack_a, stack_b, RRA);
	}
	else if (a > b && a > c && b < c)
		do_rotate(stack_a, stack_b, RA);
	else if (a < b && a < c && b > c)
	{
		do_swap(*stack_a, *stack_b, SA);
		do_rotate(stack_a, stack_b, RA);
	}
	else if (a < b && a > c && b > c)
		do_rev_rotate(stack_a, stack_b, RRA);
}

void	algorythm5(t_node **stack_a, t_node **stack_b)
{
	int	lst_size;
	int	min;

	lst_size = ft_listsize(*stack_a);
	while (lst_size > 3)
	{
		min = lst_getmin(*stack_a);
		while (lst_getindex(min, *stack_a) != 0)
		{
			if (lst_getindex(min, *stack_a) < lst_size / 2)
				do_rotate(stack_a, stack_b, RA);
			else
				do_rev_rotate(stack_a, stack_b, RRA);
		}
		if (lst_getindex(min, *stack_a) == 0)
		{
			do_push(stack_a, stack_b, PB);
			lst_size = ft_listsize(*stack_a);
		}
	}
	algorythm3(stack_a, stack_b);
	do_push(stack_a, stack_b, PA);
	do_push(stack_a, stack_b, PA);
}

void	choose_algorythm(t_node **stack_a, t_node **stack_b)
{
	int	lst_size;

	lst_size = ft_listsize(*stack_a);
	if (lst_size == 2)
		do_swap(*stack_a, *stack_b, SA);
	else if (lst_size == 3)
		algorythm3(stack_a, stack_b);
	else if (lst_size == 5)
		algorythm5(stack_a, stack_b);
	else
		radix(stack_a, stack_b, lst_size);
}
