/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:08:03 by vgarcia           #+#    #+#             */
/*   Updated: 2024/12/17 08:45:10 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	err(void)
{
	write(2, "Error\n", 6);
	return (-1);
}

static int	one_arg(char *av, t_stack **a)
{
	int		i;
	int		j;
	int		nbr;
	char	**all;

	i = 0;
	all = ft_split(av, ' ');
	if (all == NULL)
		return (-1);
	while (all[i])
		i++;
	if (create_stack(a, i) == -1)
		return (-1);
	j = i;
	while (i > 0)
	{
		if (ft_c_atoi(all[--i], &nbr) == -1)
			return (free((*a)->value), free(*a), free_all_str(all, j), -1);
		push(*a, nbr);
	}
	free_all_str(all, j);
	return (0);
}

char	*multiple_args(char **av, int ac, char *str)
{
	int		i;
	char	*temp;

	i = 1;
	str = ft_strjoin("", av[1]);
	if (str == NULL)
		return (NULL);
	while (i < ac - 1)
	{
		if (av[i][0] == '\0')
			return (err(), str);
		i++;
		temp = str;
		str = ft_strjoin(temp, " ");
		if (str == NULL)
			return (NULL);
		free(temp);
		temp = str;
		str = ft_strjoin(temp, av[i]);
		if (str == NULL)
			return (NULL);
		free(temp);
	}
	return (str);
}

static int	check_double(t_stack *a)
{
	int	i;
	int	j;

	i = 0;
	while (i <= a->top)
	{
		j = i + 1;
		while (j <= a->top)
		{
			if (a->value[i] == a->value[j])
				return (free(a->value), free(a), -1);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	char	*str;

	str = NULL;
	a = NULL;
	if (ac == 1)
		return (0);
	str = multiple_args(av, ac, str);
	if (str == NULL)
		return (err());
	if (one_arg(str, &a) == -1)
		return (free(str), err());
	free(str);
	if (check_double(a) == -1)
		return (err());
	a = check_solver(a);
	free(a->value);
	free(a);
	return (0);
}
