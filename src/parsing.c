/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:31:41 by lopezz            #+#    #+#             */
/*   Updated: 2023/04/19 18:23:33 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_ordered(t_node *stack_a)
{
	t_node *comp;
	t_node *cur;
	
	cur = stack_a;
	comp = stack_a->next;
	while (comp)
	{
		if (cur->data > comp->data)
		{

			return (0);
		}
		cur = cur->next;
		comp = comp->next;
	}
	return (1);
}

void	check_doubles(t_node *stack_a)
{
	t_node	*aux1;
	t_node	*aux2;

	aux1 = stack_a->next->next;
	while (aux1)
	{
		aux2 = stack_a->next;
		while (aux2 != aux1 && aux2)
		{
			if (aux1->data == aux2->data)
				error_found("Error (doubles)\n");
			aux2 = aux2->next;
		}
		aux1 = aux1->next;
	}
}

void	handle_string(char **arr, t_node *aux, long nb)
{
	int	j;

	j = 0;
	while (arr[j])
	{
		nb = ft_atoi_ps(arr[j]);
		aux = add_node(aux, nb);
		aux = aux->next;
		j++;
	}
}

void	ft_parsing(char **argv, t_node *stack_a)
{
	int		i;
	long	nb;
	char	**arr;
	t_node	*aux;

	aux = stack_a;
	
	i = 1;
	while (argv[i])
	{
		arr = ft_split(argv[i], SPACE);
		if (!arr[1])
		{
			nb = ft_atoi_ps(argv[i]);
			aux = add_node(aux, nb);
			aux = aux->next;
		}
		else
			handle_string(arr, aux, nb);
		i++;
		free_mtx(arr);
	}
}
