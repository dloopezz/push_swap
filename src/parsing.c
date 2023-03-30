/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:31:41 by lopezz            #+#    #+#             */
/*   Updated: 2023/03/30 21:41:46 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_doubles(t_node *lst)
{
	t_node	*aux;
	t_node	*aux2;

	aux = lst->next->next;
	while (aux)
	{
		aux2 = lst->next;
		while (aux2 != aux && aux2)
		{
			if (aux->data == aux2->data)
				error_found("Error (doubles)\n");
			aux2 = aux2->next;
		}
		aux = aux->next;
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

void	ft_parsing(char **argv, t_node *lst)
{
	int		i;
	long	nb;
	char	**arr;
	t_node	*aux;

	aux = lst;
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
	}
}
