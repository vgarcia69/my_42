/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 08:47:03 by vgarcia           #+#    #+#             */
/*   Updated: 2025/01/30 07:18:36 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
Checks if the input is correct
*/
int	check_args(int ac, char **av)
{
	int	args[5];
	int	i;

	i = -1;
	if (ac < 5 || ac > 6)
		return (-1);
	while (av[++i])
	{
		args[i] = philo_atoi(av[i]);
		if (args[i] <= 0)
			return (-1);
	}
	if (args[0] > 200)
		return (-1);
	return (0);
}

/*
Atoi with philo's requirements
*/
int	philo_atoi(const char *nptr)
{
	unsigned int	result;
	int				i;
	int				t;

	result = 0;
	i = 0;
	t = 1;
	if (nptr[i] == '+')
		++i;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = result * 10 + nptr[i++] - 48;
	if (nptr[i] != '\0')
		return (-1);
	return (result * t);
}

/*
Printf secured
*/
void	philo_print(char *str, t_philo *philo)
{
	time_t	to_print;

	pthread_mutex_lock(&philo->ptr_simu->mutex.on_print);
	to_print = get_time_ms() - philo->ptr_simu->starting_time;
	if (philo->time_to_die && !philo->ptr_simu->on_death)
		printf("%ld %d %s\n", to_print, philo->id, str);
	pthread_mutex_unlock(&philo->ptr_simu->mutex.on_print);
}

/*
Check if the philo is dead / satiated, or if someone died
*/
void	update_end(t_philo *philo)
{
	if (!philo->ptr_simu->on_death)
	{
		if (get_time_ms() - philo->last_meal >= philo->time_to_die)
		{
			pthread_mutex_unlock(&philo->ptr_simu->mutex.on_end);
			philo->time_to_die = 0;
			philo->ptr_simu->philo_dead_id = philo->id;
		}
		else if (philo->ptr_simu->satiated_nbr == philo->ptr_simu->philo_nbr)
			pthread_mutex_unlock(&philo->ptr_simu->mutex.on_end);
	}
}

/*
Handle end of the routine
*/
void	manage_end(t_simu *simu)
{
	time_t	to_print;

	pthread_mutex_lock(&simu->mutex.on_end);
	simu->on_death = 1;
	pthread_mutex_lock(&simu->mutex.on_print);
	to_print = get_time_ms() - simu->starting_time;
	if (simu->philo_dead_id != 0)
	{
		printf("%ld %d died\n", to_print, simu->philo_dead_id);
	}
	pthread_mutex_unlock(&simu->mutex.on_print);
}
