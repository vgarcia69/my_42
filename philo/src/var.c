/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:01:36 by v                 #+#    #+#             */
/*   Updated: 2025/01/30 07:28:57 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
Init every mutex
*/
void	mutex_init(t_simu *simu)
{
	int	i;

	i = -1;
	pthread_mutex_init(&simu->mutex.on_satiating, NULL);
	pthread_mutex_init(&simu->mutex.on_end, NULL);
	pthread_mutex_init(&simu->mutex.on_start, NULL);
	pthread_mutex_init(&simu->mutex.on_print, NULL);
	while (++i < simu->philo_nbr)
		pthread_mutex_init(&simu->mutex.fork[i], NULL);
}

/*
Init variables
*/
void	var_init(t_simu *simu, int ac, char **av)
{
	int	i;

	i = -1;
	simu->philo_dead_id = 0;
	simu->satiated_nbr = 0;
	simu->on_death = 0;
	simu->starting_time = get_time_ms();
	while (++i < simu->philo_nbr)
	{
		simu->forks[i] = 0;
		simu->philo[i].id = i + 1;
		simu->philo[i].meal_nbr = 0;
		simu->philo[i].last_meal = simu->starting_time;
		simu->philo[i].ptr_simu = simu;
		simu->philo[i].meal_goal_nbr = -1;
		simu->philo[i].time_to_die = philo_atoi(av[1]);
		simu->philo[i].time_to_eat = philo_atoi(av[2]);
		simu->philo[i].time_to_sleep = philo_atoi(av[3]);
		if (ac == 6)
			simu->philo[i].meal_goal_nbr = philo_atoi(av[4]);
		simu->philo[i].nfork_id \
			= (simu->philo[i].id % simu->philo_nbr) + 1;
	}
}

/*
Init allocated arrays
*/
int	alloc_init(t_simu *simu, char *av)
{
	simu->philo_nbr = philo_atoi(av);
	simu->philo = malloc(sizeof(t_philo) * (simu->philo_nbr));
	if (simu->philo == NULL)
		return (1);
	simu->forks = malloc(sizeof(int) * simu->philo_nbr);
	if (simu->forks == NULL)
		return (free(simu->philo), 1);
	simu->mutex.fork = malloc(sizeof(pthread_mutex_t) * simu->philo_nbr);
	if (simu->mutex.fork == NULL)
		return (free(simu->philo), free(simu->forks), 1);
	return (0);
}

/*
Close pthread's variables
*/
void	close_pthread(t_simu *simu)
{
	int	i;

	i = -1;
	if (simu->philo_nbr > 1)
		while (++i < simu->philo_nbr)
			if (pthread_join(simu->philo[i].thread, NULL))
				printf("Error : Failed to join a thread\n");
	i = -1;
	while (++i < simu->philo_nbr)
		pthread_mutex_destroy(&simu->mutex.fork[i]);
	pthread_mutex_destroy(&simu->mutex.on_print);
	pthread_mutex_destroy(&simu->mutex.on_end);
	pthread_mutex_destroy(&simu->mutex.on_satiating);
	pthread_mutex_destroy(&simu->mutex.on_start);
}

void	free_alloc(t_simu *simu)
{
	free(simu->philo);
	free(simu->forks);
	free(simu->mutex.fork);
}
