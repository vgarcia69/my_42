/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:07:11 by vgarcia           #+#    #+#             */
/*   Updated: 2024/12/17 08:26:17 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
https://cdn.intra.42.fr/pdf/pdf/143130/fr.subject.pdf
*/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int		*value;
	int		top;
	int		max_val_i;
	int		max_size;
}	t_stack;

int		ss(t_stack *a, t_stack *b);
int		sx(t_stack *stack, char tag);
int		px(t_stack *from, t_stack *to, char tag);
int		rx(t_stack *stack, char tag);
int		rr(t_stack *a, t_stack *b);
int		rrx(t_stack *stack, char tag);
int		rrr(t_stack *a, t_stack *b);

int		push(t_stack *stack, int value);
int		pop(t_stack *stack);
int		create_stack(t_stack **new_stack, int max_size);

int		err(void);
int		is_sorted(t_stack *a);
int		ft_c_atoi(const char *nptr, int *nbr);
int		to_pos(int nbr);
int		update_max_i(t_stack *stack);
void	rotate(t_stack *a, t_stack *b, int ma, int mb);
int		calcul_cost_a(t_stack *b, int nbr);

t_stack	*solve(t_stack *a, t_stack *b);
t_stack	*index_it(t_stack *a);
t_stack	*check_solver(t_stack *a);
#endif
