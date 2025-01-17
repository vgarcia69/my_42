/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:44:37 by vgarcia           #+#    #+#             */
/*   Updated: 2024/12/15 13:01:35 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_c_atoi(const char *nptr, int *nbr)
{
	unsigned long long int	result;
	int						i;
	int						t;

	result = 0;
	i = 0;
	t = 1;
	if (nptr[i] == '-')
		t = -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		++i;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = result * 10 + nptr[i++] - 48;
	if ((result > INT_MAX && t == 1)
		|| (result > 2147483648 && t == -1)
		|| (nptr[i]))
		return (-1);
	*nbr = result * t;
	return (0);
}
