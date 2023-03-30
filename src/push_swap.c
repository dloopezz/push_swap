/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:57:30 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/03/30 21:42:43 by lopezz           ###   ########.fr       */
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
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
	return (lst);
}

void	read_list(t_node *lst)
{
	t_node	*aux;

	aux = lst->next; //para que no salga primer 0
	while (aux)
	{
		printf("Node content: %li\n", aux->data);
		aux = aux->next;
	}
}

int	main(int argc, char **argv)
{
	t_node	*lst;

	lst = ft_calloc(1, sizeof(t_node));
	if (argc > 1)
	{
		ft_parsing(argv, lst);
		check_doubles(lst);
		
		read_list(lst);
		return (0);
	}
	else
	{
		ft_putstr_fd("Invalid number of arguments\n", 2);
		return (1);
	}
}
