/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:37:14 by annabrag          #+#    #+#             */
/*   Updated: 2024/04/11 16:32:27 by art3mis          ###   ########.fr       */
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

# define MAX_AMOUNT_OF_PHILOS 200

/******************************************************************************\
 * STRUCTS
\******************************************************************************/

t_rules;

typedef struct s_philo
{
	// pthread_t		thread;
	int				id;
	int				ate;
	size_t			start_time;
	size_t			last_meal;
	size_t			meals_eaten;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*meal_lock;
	t_rules			*rules;
}				t_philo;

typedef struct s_rules
{
	t_philo			*philo;
	size_t			number_of_philos;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			number_times_must_eat;
	int				*died;
}				t_rules;

typedef struct	s_prog
{
	t_philo			*philos;
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
}				t_prog;

/******************************************************************************\
 * MANDATORY
\******************************************************************************/

size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
bool    global_check_is_successfull(int argc, char **argv);

bool    is_dead(t_philo *philo);

#endif