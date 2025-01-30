/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 08:32:51 by vgarcia           #+#    #+#             */
/*   Updated: 2025/01/30 07:31:29 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

# define YELLOW "\033[33m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define RESET "\033[0m"

typedef struct s_simu	t_simu;

typedef struct s_mutexes
{
	pthread_mutex_t	on_end;
	pthread_mutex_t	on_start;
	pthread_mutex_t	on_print;
	pthread_mutex_t	on_satiating;
	pthread_mutex_t	*fork;
}	t_mutexes;

typedef struct s_philo
{
	int			id;
	int			meal_nbr;
	int			nfork_id;
	int			meal_goal_nbr;
	time_t		last_meal;
	time_t		time_to_die;
	time_t		time_to_eat;
	time_t		time_to_sleep;
	pthread_t	thread;
	t_simu		*ptr_simu;
}	t_philo;

typedef struct s_simu
{
	t_mutexes	mutex;
	t_philo		*philo;
	int			*forks;
	int			on_death;
	int			philo_nbr;
	int			philo_dead_id;
	int			satiated_nbr;
	time_t		starting_time;
}	t_simu;

//philo life / routines
int		routines(t_simu *simu);
void	eats(t_philo *philo);
int		satiated(t_philo *philo);
void	thinks(t_philo *philo);
void	*philo_life(void *arg);
void	sleeps(t_philo *philo);
void	grab_fork(t_philo *philo, int fork_id);

// var
void	var_init(t_simu *simu, int ac, char **av);
int		alloc_init(t_simu *simu, char *av);
void	mutex_init(t_simu *simu);
void	free_alloc(t_simu *simu);
void	close_pthread(t_simu *simu);

// time
time_t	get_time_ms(void);
void	philo_usleep( time_t time_to_sleep, t_philo *philo);

// utils
int		check_args(int ac, char **av);
void	philo_print(char *str, t_philo *philo);
int		philo_atoi(const char *nptr);
void	update_end(t_philo *philo);
void	manage_end(t_simu *simu);

#endif
