/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:57:30 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/03/30 19:04:37 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*add_node(t_node *lst, long num)
{
	t_node	*new;
	t_node	*aux;

	new = (t_node *)ft_calloc(1, sizeof(t_node));
	new->data = num;
	new->next = NULL;
	if (!lst)
		lst = new;
	else
	{
		aux = lst;
		while(aux->next)
			aux = aux->next;
		aux->next = new;
	}
	return (lst);
}


void	ft_parsing(char **argv, t_node *lst)
{
	int		i;
	int		j;
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
			// printf("Node content: %li\n", aux->data);
			aux = aux->next;
		}
		else 
		{
			j = 0;
			while (arr[j])
			{
				nb = ft_atoi_ps(arr[j]);
				aux = add_node(aux, nb);
				// printf("Node content: %li\n", aux->data);
				aux = aux->next;
				j++;
			}
		}
		i++;
	}
}

void	check_doubles(t_node *lst)
{
	t_node	*aux;
	t_node	*aux2;
	long	nb;

	aux = lst;
	aux = aux->next->next;
	while (aux)
	{
		nb = aux->data;
		aux2 = lst;
		aux2 = aux2->next;
		while (aux2 != aux && aux2)
		{
			if (nb == aux2->data)
				error_found("Error (doubles)\n");
			aux2 = aux2->next;
		}
		aux = aux->next;
	}
}

int	main(int argc, char **argv)
{
	t_node	*lst;
	t_node	*aux;

	lst = ft_calloc(1, sizeof(t_node));
	if (argc > 1)
	{
		ft_parsing(argv, lst);
		check_doubles(lst);
		
		
		aux = lst;
		aux = aux->next; //para que no haya dos 0
		while (aux)
		{
			printf("Node content: %li\n", aux->data);
			aux = aux->next;
		}
		
		return (0);
	}
	else
	{
		ft_putstr_fd("Invalid number of arguments\n", 2);
		return (1);
	}
}
