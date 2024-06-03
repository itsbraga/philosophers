/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:37:14 by annabrag          #+#    #+#             */
/*   Updated: 2024/06/03 21:59:57 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/******************************************************************************\
 * ABOUT THE PROJECT
\******************************************************************************/
/*
	The dining philosophers problem is a famous problem in computer science
	used to illustrate common issues in concurrent programming. The problem
	was originally formulated in 1965 by Edsger Dijkstra, and is stated as
	follows:

	X amount of philosophers sit at a round table with bowls of food.
	Forks are placed in front of each philosopher.
	There are as many forks as philosophers.
	All day the philosophers take turns eating, sleeping, and thinking.
	A philosopher must have two forks in order to eat, and each fork
	may only be used by one philosopher at a time. At any time a
	philosopher can pick up or set down a fork,
	but cannot start eating until picking up both forks.
	The philosophers alternatively eat, sleep, or think.
	While they are eating, they are not thinking nor sleeping,
	while thinking, they are not eating nor sleeping,
	and, of course, while sleeping, they are not eating nor thinking.
*/

# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdbool.h>
# include "defines.h"

# define MAX_NBR_OF_PHILOS 200

/******************************************************************************\
 * STRUCTS
\******************************************************************************/

struct	s_data;

typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	int					died;
	int					eating;
	size_t				last_meal;
	size_t				meals_count;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*left_fork;
	struct s_data		*data;
}				t_philo;

typedef struct s_data
{
	t_philo				*philos;
	size_t				nbr_of_philos;
	size_t				start_time;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	size_t				nbr_times_each_must_eat;
	pthread_mutex_t		*forks;
	pthread_mutex_t		write_lock;
	pthread_mutex_t		dead_lock;
	pthread_mutex_t		meal_lock;
}				t_data;

// write -> save writes changes after a thread has accessed a variable
//			and modified its value

/******************************************************************************\
 * MANDATORY
\******************************************************************************/

void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
bool	args_check_is_successfull(int argc, char **argv);

size_t	get_current_time(void);
void	my_usleep(t_philo *philo, size_t time);
void	status_msg(char *str, t_philo *philo);

int		alloc(t_data *ph_data);
int		init(t_data *ph_data, char **argv);
void	create_threads(t_data *ph_data);

void	eat_func(t_philo *philo);
void	sleep_func(t_philo *philo);
void	think_func(t_philo *philo);
bool	death_check(t_philo *philo);

void	destroy_mutexes(t_data *ph_data);

#endif