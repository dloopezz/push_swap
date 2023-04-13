/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:32:22 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/04/13 15:12:53 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_swap(t_node *stack_a, t_node *stack_b, int check)
{
	if (check == SA)
	{
		if (!stack_a || !stack_a->next)
			return ;
		ft_swap(stack_a);
		ft_putstr_fd("sa\n", 1);
	}
	else if (check == SB)
	{
		if (!stack_b || !stack_b->next)
			return ;
		ft_swap(stack_b);
		ft_putstr_fd("sb\n", 1);	
	}
	else if (check == SS)
	{
		if (!stack_a || !stack_a->next)
			return ;
		ft_swap(stack_a);
		if (!stack_b || !stack_b->next)
			return ;
		ft_swap(stack_b);
		ft_putstr_fd("ss\n", 1);	
	}
}

void	do_rotate(t_node **stack_a, t_node **stack_b, int check)
{
	
	if (check == RA)
	{
		if (!*stack_a || !(*stack_a)->next)
			return ;
		ft_rotate(stack_a);
		ft_putstr_fd("ra\n", 1);	
	}
	else if (check == RB)
	{
		if (!*stack_b || !(*stack_b)->next)
			return ;
		ft_rotate(stack_b);
		ft_putstr_fd("rb\n", 1);	
	}
	else if (check == RR)
	{
		if (!*stack_a || !(*stack_a)->next)
			return ;
		ft_rotate(stack_a);
		if (!*stack_b || !(*stack_b)->next)
			return ;
		ft_rotate(stack_b);
		ft_putstr_fd("rr\n", 1);	
	}
}

void	do_rev_rotate(t_node **stack_a, t_node **stack_b, int check)
{
	if (check == RRA)
	{
		if (!*stack_a || !(*stack_a)->next)
			return ;
		ft_rev_rotate(stack_a);
		ft_putstr_fd("rra\n", 1);	
	}
	else if (check == RRB)
	{
		if (!*stack_b || !(*stack_b)->next)
			return ;
		ft_rev_rotate(stack_b);
		ft_putstr_fd("rrb\n", 1);	
	}
	else if (check == RRR)
	{
		if (!*stack_a || !(*stack_a)->next)
			return ;
		ft_rev_rotate(stack_a);
		if (!*stack_b || !(*stack_b)->next)
			return ;
		ft_rev_rotate(stack_b);
		ft_putstr_fd("rrr\n", 1);	
	}
}

void	do_push(t_node **stack_a, t_node **stack_b, int check)
{
	if (check == PA)
	{
		if (!*stack_a /* ||  !(*stack_a)->next */)
			return ;
		ft_push(stack_a, stack_b);
		ft_putstr_fd("pa\n", 1);	
	}
	else if (check == PB)
	{
		if (!*stack_b /* || !(*stack_b)->next */)
			return ;
		ft_push(stack_b, stack_a);
		ft_putstr_fd("pb\n", 1);	
	}
}
