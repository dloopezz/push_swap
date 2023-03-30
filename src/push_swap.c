/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:57:30 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/03/30 16:10:01 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*add_node(t_node *lst, long num)
{
	t_node	*new;
	t_node	*aux;

	new = (t_node *)malloc(sizeof(t_node));
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

// int	check_doubles(t_node *lst)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (lst->next)
// 	{

// 		i++;
// 	}
// 	return (0);
// }

t_node	*ft_parsing(char **argv, t_node *lst)
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
	return (lst);
}

int	main(int argc, char **argv)
{
	t_node	*lst = NULL;
	t_node	*aux;

	if (argc > 1)
	{
		aux = ft_parsing(argv, lst);
		printf("Node content: %li\n", aux->data);
		
		
		// while (lst->next)
		// {
		// 	printf("Node content: %li\n", lst->data);
		// 	lst = lst->next;
		// }
		
		// check_doubles(lst);
		return (0);
	}
	else
	{
		ft_putstr_fd("Invalid number of arguments\n", 2);
		return (1);
	}
}
