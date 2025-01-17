/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_func2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:02:00 by vgarcia           #+#    #+#             */
/*   Updated: 2024/12/15 13:03:59 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rrx(t_stack *stack, char tag)
{
	int	i;
	int	tmp;
	int	tmp2;

	if (stack == NULL || stack->top < 1)
		return (-1);
	i = 0;
	while (i < stack->top)
	{
		tmp = stack->value[i];
		tmp2 = stack->value[i + 1];
		stack->value[i] = tmp2;
		stack->value[i + 1] = tmp;
		i++;
	}
	if (tag == 'a')
		write(1, "rra\n", 4);
	else if (tag == 'b')
		write (1, "rrb\n", 4);
	return (0);
}

int	rr(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	if (rx(a, 's') == -1)
		i++;
	if (rx(b, 's') == -1)
		i++;
	if (i != 2)
		write(1, "rr\n", 3);
	return (0);
}

int	rx(t_stack *stack, char tag)
{
	int	i;
	int	tmp;
	int	tmp2;

	if (stack == NULL || stack->top < 1)
		return (-1);
	i = stack->top;
	while (i > 0)
	{
		tmp = stack->value[i];
		tmp2 = stack->value[i - 1];
		stack->value[i - 1] = tmp;
		stack->value[i] = tmp2;
		i--;
	}
	if (tag == 'a')
		write(1, "ra\n", 3);
	else if (tag == 'b')
		write (1, "rb\n", 3);
	return (0);
}

int	rrr(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	if (rrx(a, 's') == -1)
		i++;
	if (rrx(b, 's') == -1)
		i++;
	if (i != 2)
		write(1, "rrr\n", 4);
	return (0);
}
