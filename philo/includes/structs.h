/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:04:22 by annabrag          #+#    #+#             */
/*   Updated: 2024/11/14 20:48:38 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "philo.h"

struct s_data;

typedef struct s_philo
{
	pthread_t			*thread;
	unsigned int		id;
	size_t				last_meal_time;
	unsigned int		meals_eaten;
	unsigned int		r_fork;
	unsigned int		l_fork;
	struct s_data		*data;
}				t_philo;

/*	write_lock:

	save writes changes after a thread has accessed
	a variable and modified its value
*/
typedef struct s_data
{
	t_philo				*philo;
	bool				died;
	unsigned int		nbr_of_philos;
	size_t				sim_start;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	unsigned int		full;
	int					nbr_meal_must_eat;
	pthread_mutex_t		*forks;
	pthread_mutex_t		write_lock;
	pthread_mutex_t		death_lock;
	pthread_mutex_t		meal_lock;
	pthread_mutex_t		full_lock;
}				t_data;

#endif