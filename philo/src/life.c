/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:36:18 by vgarcia           #+#    #+#             */
/*   Updated: 2025/01/29 14:11:11 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
Sleeps (time_to_sleep)
*/
void	sleeps(t_philo *philo)
{
	philo_print(BLUE "is sleeping" RESET, philo);
	philo_usleep(philo->time_to_sleep, philo);
}

/*
Locks both index forks
*/
void	grab_fork(t_philo *philo, int fork_id)
{
	while (!philo->ptr_simu->on_death)
	{
		pthread_mutex_lock(&philo->ptr_simu->mutex.fork[fork_id - 1]);
		update_end(philo);
		if (philo->ptr_simu->forks[fork_id - 1] == 0)
		{
			philo->ptr_simu->forks[fork_id - 1] = 1;
			philo_print(GREEN "has taken a fork" RESET, philo);
			pthread_mutex_unlock(&philo->ptr_simu->mutex.fork[fork_id - 1]);
			break ;
		}
		pthread_mutex_unlock(&philo->ptr_simu->mutex.fork[fork_id - 1]);
	}
}

/*
Start eating (time_to_eat), unlock both index forks
*/
void	eats(t_philo *philo)
{
	philo_print(YELLOW "is eating" RESET, philo);
	philo_usleep(philo->time_to_eat, philo);
	pthread_mutex_lock(&philo->ptr_simu->mutex.fork[philo->id - 1]);
	philo->ptr_simu->forks[philo->id - 1] = 0;
	pthread_mutex_unlock(&philo->ptr_simu->mutex.fork[philo->id - 1]);
	pthread_mutex_lock(&philo->ptr_simu->mutex.fork[philo->nfork_id - 1]);
	philo->ptr_simu->forks[philo->nfork_id - 1] = 0;
	pthread_mutex_unlock(&philo->ptr_simu->mutex.fork[philo->nfork_id - 1]);
	philo->last_meal = get_time_ms();
	++philo->meal_nbr;
	if (philo->meal_goal_nbr != -1)
	{
		if (philo->meal_goal_nbr <= philo->meal_nbr)
		{
			philo->meal_nbr = -1;
			return ;
		}
	}
}

/*
Think to let time to others to grab the forks
*/
void	thinks(t_philo *philo)
{
	philo_print(RED "is thinking" RESET, philo);
	philo_usleep((philo->time_to_die - \
		(philo->time_to_eat + philo->time_to_sleep)) * 0.7, philo);
}

/*
Check if the mealGoal has been reached
*/
int	satiated(t_philo *philo)
{
	if (philo->meal_nbr == -1)
	{
		pthread_mutex_lock(&philo->ptr_simu->mutex.on_satiating);
		++philo->ptr_simu->satiated_nbr;
		pthread_mutex_unlock(&philo->ptr_simu->mutex.on_satiating);
		update_end(philo);
		return (1);
	}
	update_end(philo);
	return (0);
}
