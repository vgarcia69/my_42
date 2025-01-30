/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 08:57:59 by vgarcia           #+#    #+#             */
/*   Updated: 2025/01/30 15:56:16 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
Sad fate for the lonely guy
*/
static void	sad_fate(t_philo *philo)
{
	time_t	to_print;

	to_print = get_time_ms() - philo->ptr_simu->starting_time;
	printf("%ld %d", to_print, philo->id);
	printf(BLUE " has taken a fork\n" RESET);
	philo_usleep(philo->time_to_die, philo);
	to_print = get_time_ms() - philo->ptr_simu->starting_time;
	printf("%ld %d died\n", to_print, philo->id);
}

/*
Program the routines for each philo
*/
void	*philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->ptr_simu->mutex.on_start);
	pthread_mutex_unlock(&philo->ptr_simu->mutex.on_start);
	if (philo->id % 2)
		thinks(philo);
	while (!philo->ptr_simu->on_death)
	{
		grab_fork(philo, philo->id);
		grab_fork(philo, philo->nfork_id);
		eats(philo);
		if (satiated(philo) || philo->ptr_simu->on_death)
			break ;
		sleeps(philo);
		thinks(philo);
	}
	return (NULL);
}

/*
Manage the threads / main thread
*/
int	routines(t_simu *simu)
{
	int	i;

	i = -1;
	if (simu->philo_nbr == 1)
	{
		return (sad_fate(&simu->philo[0]));
		return (0);
	}
	pthread_mutex_lock(&simu->mutex.on_start);
	pthread_mutex_lock(&simu->mutex.on_end);
	while (++i < simu->philo_nbr)
	{
		if (pthread_create(&simu->philo[i].thread, NULL, \
			&philo_life, &simu->philo[i]))
		{
			pthread_mutex_unlock(&simu->mutex.on_start);
			pthread_mutex_unlock(&simu->mutex.on_end);
			close_pthread(simu);
			return (1);
		}
	}
	pthread_mutex_unlock(&simu->mutex.on_start);
	manage_end(simu);
	return (0);
}
