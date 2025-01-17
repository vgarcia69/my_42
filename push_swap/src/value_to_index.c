/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_to_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:23:01 by vgarcia           #+#    #+#             */
/*   Updated: 2024/12/13 13:50:08 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	*init_ptr(int *index_nbr, int v, size_t n)
{
	while (n--)
		index_nbr[n] = v;
	return (index_nbr);
}

static int	*fill_ptr(int *index_nbr, t_stack *a)
{
	int	i;
	int	big;
	int	tmp;

	tmp = a->top;
	while (tmp >= 0)
	{
		big = INT_MIN;
		i = -1;
		while (++i <= a->top)
			if (a->value[i] >= big && index_nbr[i] == -1)
				big = a->value[i];
		i = 0;
		while (a->value[i] != big && i <= a->top)
			++i;
		index_nbr[i] = tmp--;
	}
	return (index_nbr);
}

static t_stack	*va_to_in(t_stack *a, int *index_nbr)
{
	int	i;

	i = 0;
	while (i <= a->top)
	{
		a->value[i] = index_nbr[i];
		i++;
	}
	free(index_nbr);
	return (a);
}

t_stack	*index_it(t_stack *a)
{
	int	*index_nbr;

	index_nbr = malloc(sizeof(int) * (a->top + 1));
	if (index_nbr == NULL)
		return (NULL);
	index_nbr = init_ptr(index_nbr, -1, a->top + 1);
	index_nbr = fill_ptr(index_nbr, a);
	a = va_to_in(a, index_nbr);
	return (a);
}
