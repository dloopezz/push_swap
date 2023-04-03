/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:02:35 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/04/03 17:47:06 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

# include "../libft/libft.h"

# define SPACE 32
# define FALSE 1

//#define NODE struct s_node

typedef struct s_node
{
	long			data;
	struct s_node	*next;
}				t_node;

t_node		*add_node(t_node *stack_a, long num);
void		ft_parsing(char **argv, t_node *stack_a);
void		handle_string(char **arr, t_node *aux, long nb);
long long	ft_atoi_ps(const char *str);
void		read_list(t_node *stack_a);
void		check_doubles(t_node *stack_a);

void		ft_swap(t_node *lst);
void	ft_rotate(t_node *lst);

#endif