/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:52:08 by vgarcia           #+#    #+#             */
/*   Updated: 2024/12/13 15:41:20 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	push(t_stack *stack, int value)
{
	if (stack == NULL || stack->top >= stack->max_size)
		return (-1);
	stack->top++;
	stack->value[stack->top] = value;
	return (0);
}

int	pop(t_stack *stack)
{
	int	new_max;
	int	i;

	new_max = -1;
	i = stack->top - 1;
	if (stack == NULL || stack->top == -1)
		return (-1);
	stack->value[stack->top--] = 0;
	return (0);
}

int	create_stack(t_stack **new_stack, int max_size)
{
	*new_stack = malloc(sizeof(t_stack));
	if (*new_stack == NULL)
		return (-1);
	(*new_stack)->max_size = max_size;
	(*new_stack)->top = -1;
	(*new_stack)->value = malloc(sizeof(int) * (max_size + 1));
	if ((*new_stack)->value == NULL)
		return (free(*new_stack), -1);
	(*new_stack)->max_val_i = 0;
	return (0);
}
