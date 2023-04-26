/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:02:35 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/04/26 12:08:50 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

# include "../libft/libft.h"

# define SPACE 32
# define FALSE 1

# define SA 0
# define SB 1
# define SS 2

# define RA 0
# define RB 1
# define RR 2

# define RRA 0
# define RRB 1
# define RRR 2

# define PA 0
# define PB 1

typedef struct s_node
{
	long			data;
	int				index;
	struct s_node	*next;
}				t_node;

//PUSH_SWAP
t_node		*add_node(t_node *stack_a, long num);
void		ft_parsing(char **argv, t_node *stack_a);
void		handle_string(char **arr, t_node *aux, long nb);
long long	ft_atoi_ps(const char *str);
void		check_doubles(t_node *stack_a);
int			check_ordered(t_node *stack_a);
void		free_all(t_node *st_a, t_node *st_b, t_node *aux1, t_node *aux2);

//MOVES
void		ft_swap(t_node *stack);
void		do_swap(t_node *stack_a, t_node *stack_b, int check);
void		ft_rotate(t_node **stack);
void		do_rotate(t_node **stack_a, t_node **stack_b, int check);
void		ft_rev_rotate(t_node **stack);
void		do_rev_rotate(t_node **stack_a, t_node **stack_b, int check);
void		ft_push(t_node **stack_a, t_node **stack_b);
void		do_push(t_node **stack_a, t_node **stack_b, int check);

//ALGORYTHM
void		choose_algorythm(t_node **stack_a, t_node **stack_b);
void		algorythm3(t_node **stack_a, t_node **stack_b);
void		algorythm5(t_node **stack_a, t_node **stack_b);
void		radix(t_node **stack_a, t_node **stack_b, int lst_size);
int			ft_itob(int nb);
void		sort_numbers(t_node **stack_a, t_node **stack_b, int size);

//MY LIST FUNCTIONS
t_node		*lstlast_ps(t_node *lst);
void		lstadd_back_ps(t_node **lst, t_node *new);
void		lstadd_front_ps(t_node **lst, t_node *new);
void		read_list(t_node *stack);
int			ft_listsize(t_node *stack);
int			lst_getmin(t_node *stack);
int			lst_getmax(t_node *stack);
int			lst_maxindex(t_node *stack);
int			lst_getindex(long num, t_node *stack);
void		lst_setindex(t_node *stack);
void		free_lst(t_node *stack);

#endif