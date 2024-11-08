/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:20:45 by annabrag          #+#    #+#             */
/*   Updated: 2024/11/08 18:21:05 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	take_forks(philo);
	pthread_mutex_lock(&philo->data->meal_lock);
	philo->is_eating = 1;
	status_msg("is eating", philo);
	philo->last_meal = get_current_time();
	philo->meals_count++;
	usleep(philo->data->time_to_eat);
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->data->meal_lock);
	drop_forks(philo);
}

void	asleep(t_philo *philo)
{
	status_msg("is sleeping", philo);
	usleep(philo->data->time_to_sleep);
}

/* They don't really think, they wait until they have two forks to eat. */
void	think(t_philo *philo)
{
	status_msg("is thinking", philo);
}

bool	death_check(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->dead_lock);
	if (philo->died == 1)
	{
		pthread_mutex_unlock(&philo->data->dead_lock);
		return (true);
	}
	pthread_mutex_unlock(&philo->data->dead_lock);
	return (false);
}
