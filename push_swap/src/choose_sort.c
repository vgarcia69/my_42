/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:46:28 by vgarcia           #+#    #+#             */
/*   Updated: 2024/12/17 08:25:44 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// quick sort 3 algo
static t_stack	*mini_sort(t_stack *a)
{
	if (a->value[a->top] < a->value[a->top - 1]
		&& a->value[a->top - 1] > a->value[a->top - 2])
		rrx(a, 'a');
	if (a->value[a->top] > a->value[a->top - 1]
		&& a->value[a->top - 1] > a->value[a->top - 2])
	{
		sx(a, 'a');
		rx(a, 'a');
	}
	if (a->value[a->top] < a->value[a->top - 2]
		&& a->value[a->top - 1] > a->value[a->top - 2])
		sx(a, 'a');
	if (a->value[a->top] > a->value[a->top - 1]
		&& a->value[a->top] < a->value[a->top - 2])
		sx(a, 'a');
	if (a->value[a->top] > a->value[a->top - 1]
		&& a->value[a->top - 1] < a->value[a->top - 2])
		rx(a, 'a');
	return (a);
}

// sorting algo if there is 5 or less numbers
static t_stack	*small_sort(t_stack *a, t_stack *b)
{
	int	small;

	small = 0;
	a = index_it(a);
	a->max_val_i = update_max_i(a);
	while (a->top >= 3)
	{
		if (calcul_cost_a(a, small) < 0)
			while (a->value[a->top] != small)
				rrx(a, 'a');
		else
			while (a->value[a->top] != small)
				rx(a, 'a');
		px(a, b, 'b');
		small++;
	}
	a = mini_sort(a);
	while (b->top >= 0)
		px(b, a, 'a');
	return (a);
}

// check which algo it should choose
t_stack	*check_solver(t_stack *a)
{
	t_stack	*b;

	if (create_stack(&b, a->max_size) == -1)
		return (err(), NULL);
	a = index_it(a);
	if (is_sorted(a))
		return (a);
	if (a->top == 2)
		a = mini_sort(a);
	else if (a->top == 1)
	{
		if (a->value[a->top] > a->value[a->top - 1])
			sx(a, 'a');
	}
	else if (a->top > 5)
		a = solve(a, b);
	else
		a = small_sort(a, b);
	return (free(b->value), free(b), a);
}
