/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_func1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:31:11 by vgarcia           #+#    #+#             */
/*   Updated: 2024/12/13 13:51:54 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sx(t_stack *stack, char tag)
{
	int	tmp;

	if (stack == NULL || stack->top < 1)
		return (-1);
	tmp = stack->value[stack->top - 1];
	stack->value[stack->top - 1] = stack->value[stack->top];
	stack->value[stack->top] = tmp;
	if (tag == 'a')
		write(1, "sa\n", 3);
	else if (tag == 'b')
		write(1, "sb\n", 3);
	return (0);
}

int	ss(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	if (sx(a, 's') != -1)
		i++;
	if (sx(b, 's') != -1)
		i++;
	if (i != 2)
		write(1, "ss\n", 3);
	return (0);
}

int	px(t_stack *from, t_stack *to, char tag)
{
	if (from == NULL || push(to, from->value[from->top]) < 0 || pop(from) < 0)
		return (-1);
	if (to->value[to->top] > to->value[to->max_val_i])
		to->max_val_i = to->top;
	if (tag == 'a')
		write (1, "pa\n", 3);
	else if (tag == 'b')
		write (1, "pb\n", 3);
	return (0);
}
