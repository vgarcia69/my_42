/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 08:33:32 by vgarcia           #+#    #+#             */
/*   Updated: 2025/01/30 07:25:40 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int ac, char **av)
{
	t_simu	simulation;

	if (check_args(ac, &av[1]))
		return (printf("Error : Input\n"), 1);
	if (alloc_init(&simulation, av[1]))
		return (printf("Error : Memory Allocation\n"), 1);
	var_init(&simulation, ac, &av[1]);
	mutex_init(&simulation);
	routines(&simulation);
	close_pthread(&simulation);
	free_alloc(&simulation);
	return (0);
}
