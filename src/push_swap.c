/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:57:30 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/03/30 13:17:24 by dlopez-s         ###   ########.fr       */
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

int	check_args(char *nb)
{
	int	i;

	i = 0;
	if (!nb[i])
		return (1);
	while (nb[i])
	{
		if ((nb[i] <= '0' && nb[i] >= '9') && (nb[i] != '-' || nb[i] != '+' || nb[i] != ' ')) //hay un error aquí (no comprueba bien)
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	long		nb;
	char	**arr;
	t_node	*lst = NULL;
	
	if (argc > 1)
	{
		i = 1;
		while (argv[i])
		{
			arr = ft_split(argv[i], SPACE);
			if (!arr[1])
			{
				nb = ft_atoi_ps(argv[i]);
				lst = add_node(lst, nb);
				printf("Node content: %li\n", lst->data);
				lst = lst->next;
			}
			else
			{
				j = 0;
				while (arr[j])
				{
					nb = ft_atoi_ps(arr[j]);
					lst = add_node(lst, nb);
					printf("Node content: %li\n", lst->data);
					lst = lst->next;
					j++;
				}
			}
			i++;
		}
		return (0);
	}
	else
	{
		ft_putstr_fd("Invalid number of arguments\n", 2);
		return (1);
	}
}
