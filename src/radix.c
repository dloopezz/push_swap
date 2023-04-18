/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:04:20 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/04/18 19:16:27 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int ft_itob(int nb)
{
	int	bin[32];
	int	i;

	i = 0;
	while (nb)
	{
		bin[i] = nb & 1; //aquí se almacena el número en binario, cosa que no necesito para el algoritmo pero me puede enir bien en un futuro
		nb = nb >> 1;
		i++;
	}
	return (i);
}

void radix(t_node **stack_a, t_node **stack_b, int lst_size)
{
	int	max;
	int bin_digits;
	int	i;
	int	j;
	
	i = 0;
	lst_setindex(*stack_a);
	max = lst_maxindex(*stack_a);
	bin_digits = ft_itob(max);
	// printf("bin_digits: %i\n", bin_digits);
	while (i < bin_digits)
	{
		j = 0;
		while (j < lst_size)
		{
			//ps_bit
			j++;
		}
		while (*stack_b)
			do_push(stack_a, stack_b, PB);
		i++;
	}
}
