/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:04:22 by annabrag          #+#    #+#             */
/*   Updated: 2024/11/08 18:51:52 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "philo.h"

struct s_data;
typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	int					died;
	int					is_eating;
	int					last_meal;
	int					meals_count;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*left_fork;
	struct s_data		*data;
}				t_philo;

/*	write_lock:

	save writes changes after a thread has accessed
	a variable and modified its value
*/
typedef struct s_data
{
	t_philo				*philos;
	int					nbr_of_philos;
	size_t				start_time;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	int					nbr_times_each_must_eat;
	pthread_mutex_t		*forks;
	pthread_mutex_t		write_lock;
	pthread_mutex_t		dead_lock;
	pthread_mutex_t		meal_lock;
}				t_data;

#endif