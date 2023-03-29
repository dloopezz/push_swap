/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:57:30 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/03/29 18:04:43 by dlopez-s         ###   ########.fr       */
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
		{
			aux = aux->next;
			aux->next = new;
		}
	}
	return (lst);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	long		nb;
	char	**arr;
	t_node	*lst;

	if (argc >= 1)
	{
		i = 1;
		while (argv[i])
		{
			arr = ft_split(argv[i], SPACE);
			if (!arr[1])
			{
				nb = ft_atoi(argv[i]);
				lst = add_node(lst, nb);
				printf("Node content: %li\n", lst->data);
				lst = lst->next;
			}
			else
			{
				j = 0;
				while (arr[j])
				{
					nb = ft_atoi(arr[j]);
					lst = add_node(lst, nb);
					printf("Node content: %li\n", lst->data);
					lst = lst->next;
					j++;
				}
			}
			i++;
		}
	}
	return (0);
}
