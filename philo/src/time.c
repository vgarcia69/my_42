/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 08:23:55 by v                 #+#    #+#             */
/*   Updated: 2025/01/30 07:26:17 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
Get the current time in microsec
*/
time_t	get_time_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

/*
Usleep which keeps receiving informations
*/
void	philo_usleep(time_t time_to_sleep, t_philo *philo)
{
	time_t	time_spent;

	time_spent = get_time_ms();
	while (time_to_sleep > get_time_ms() - time_spent)
	{
		update_end(philo);
		if (philo->ptr_simu->on_death)
			return ;
		usleep(50);
	}
	update_end(philo);
}
