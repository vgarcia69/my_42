/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_solver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:16:53 by v                 #+#    #+#             */
/*   Updated: 2024/12/15 13:13:04 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i <= a->top)
	{
		if (a->value[i] < a->value[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	to_pos(int nbr)
{
	if (nbr < 0)
		nbr = -nbr;
	return (nbr);
}

int	update_max_i(t_stack *stack)
{
	int	i;
	int	max_i;

	i = 0;
	max_i = 0;
	while (i <= stack->top)
	{
		if (stack->value[i] > stack->value[max_i])
			max_i = i;
		i++;
	}
	return (max_i);
}

static void	simple_rot(t_stack *a, t_stack *b, int ma, int mb)
{
	while (ma > 0)
	{
		rx(a, 'a');
		--ma;
	}
	while (ma < 0)
	{
		rrx(a, 'a');
		++ma;
	}
	while (mb > 0)
	{
		rx(b, 'b');
		--mb;
	}
	while (mb < 0)
	{
		rrx(b, 'b');
		++mb;
	}
}

void	rotate(t_stack *a, t_stack *b, int ma, int mb)
{
	while (ma > 0 && mb > 0)
	{
		rr(a, b);
		--ma;
		--mb;
	}
	while (ma < 0 && mb < 0)
	{
		rrr(a, b);
		++ma;
		++mb;
	}
	simple_rot(a, b, ma, mb);
}
