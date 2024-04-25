/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:42:38 by art3mis           #+#    #+#             */
/*   Updated: 2024/04/11 15:50:27 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eat_func(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	status_msg("has taken a fork (left)", philo);
	if (philo->data->nbr_of_philos == 1)
	{
		usleep(philo->data->time_to_die);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	pthread_mutex_lock(philo->right_fork);
	status_msg("has taken a fork (right)", philo);
	philo->eating = 1;
	status_msg("is eating", philo);
	pthread_mutex_lock(&philo->data->meal_lock);
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->meal_lock);
	usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

static void	sleep_func(t_philo *philo)
{
	status_msg("is sleeping", philo);
}

/*
	They don't really think, they wait until they have
	two forks to eat.
*/
static void	think_func(t_philo *philo)
{
	status_msg("is thinking", philo);
}

bool    is_dead(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->dead_lock);
    if (philo->data->died == 1)
    {
        pthread_mutex_unlock(&philo->data->dead_lock);
        return (true);
    }
    pthread_mutex_unlock(&philo->data->dead_lock);
    return (false);
}

void	*philos_routine(void *philo_ptr)
{
	t_philo *philo;

	philo = (t_philo *)philo_ptr;
	if (philo->id % 2 == 0)
		my_usleep(philo, 1);
	while (is_dead(philo) == false)
	{
		eat_func(philo);
		sleep_func(philo);
		think_func(philo);
	}
	return (NULL);
}
