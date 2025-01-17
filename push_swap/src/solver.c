/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 08:42:09 by vgarcia           #+#    #+#             */
/*   Updated: 2024/12/26 11:44:49 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// calcul the cost of the best way to put a->val on top
int	calcul_cost_a(t_stack *b, int nbr)
{
	int	i;

	i = b->top;
	while (i >= 0)
	{
		if (i == b->top)
			if (b->value[i] == nbr)
				break ;
		if (b->value[i] == nbr)
			break ;
		i--;
	}
	if (i <= b->top / 2)
		return (-(i + 1));
	return (b->top - i);
}

// calcul the cost of the best way to put a->val in B sorted
static int	calcul_cost_b(t_stack *b, int nbr)
{
	int	i;

	i = b->top;
	while (i >= 0)
	{
		if (i == b->top)
		{
			if (b->value[i] < nbr && b->value[0] > nbr)
				break ;
		}
		else
			if (b->value[i] < nbr && b->value[i + 1] > nbr)
				break ;
		i--;
	}
	if (i == -1)
		i = b->max_val_i;
	if (i <= b->top / 2)
		return (-(i + 1));
	return (b->top - i);
}

//to calc the abs value result of both moves
static int	calc_move(int ma, int mb)
{
	if (ma < 0 && mb >= 0)
		return (mb + (-ma));
	if (mb < 0 && ma >= 0)
		return (ma + (-mb));
	if (ma < 0 && mb < 0)
	{
		ma *= -1;
		mb *= -1;
	}
	if (ma > mb)
		return (ma);
	return (mb);
}

//find the cheapest cost move to do
static void	find_best_move(t_stack *a, t_stack *b, int *ma, int *mb)
{
	int	best_move;
	int	i;
	int	move_a_tmp;
	int	move_b_tmp;

	i = a->top;
	best_move = INT_MAX;
	while (i >= 0)
	{
		move_a_tmp = calcul_cost_a(a, a->value[i]);
		move_b_tmp = calcul_cost_b(b, a->value[i]);
		if (calc_move(move_a_tmp, move_b_tmp) < best_move)
		{
			best_move = calc_move(move_a_tmp, move_b_tmp);
			*ma = move_a_tmp;
			*mb = move_b_tmp;
		}
		i--;
	}
}

//main part of the big solver
t_stack	*solve(t_stack *a, t_stack *b)
{
	int	ma;
	int	mb;

	a = index_it(a);
	px(a, b, 'b');
	b->max_val_i = update_max_i(b);
	a->max_val_i = update_max_i(a);
	while (a->top >= 0)
	{
		find_best_move(a, b, &ma, &mb);
		rotate(a, b, ma, mb);
		px(a, b, 'b');
		b->max_val_i = update_max_i(b);
		a->max_val_i = update_max_i(a);
	}
	while (b->top >= 0)
		px(b, a, 'a');
	if (calcul_cost_a(a, 0) > 0)
		while (a->value[a->top] != 0)
			rx(a, 'a');
	else
		while (a->value[a->top] != 0)
			rrx(a, 'a');
	return (a);
}
