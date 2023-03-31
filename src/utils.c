/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:49:26 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/03/31 17:31:32 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi_ps(const char *str)
{
	int			i;
	int			sign;
	long long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while(str[i] == SPACE)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (((str[i] < '0' || str[i] > '9')) || ft_strlen(str) == 0)
		error_found("Error\n");
	while (str[i] >= '0' && str[i] <= '9')
		nb = (str[i++] - '0') + (nb * 10);
	if ((str[i] < '0' || str[i] > '9') && str[i] && str[i] != SPACE)
		error_found("Error\n");
	nb *= sign; //meter en if de abajo
	if (nb > INT_MAX || nb < INT_MIN)
		error_found("Error\n");
	return (nb);
}
