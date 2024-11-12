/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:20:45 by annabrag          #+#    #+#             */
/*   Updated: 2024/11/12 22:46:32 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	__take_forks(t_philo *voltaire)
{
	pthread_mutex_lock(&voltaire->data->forks[voltaire->l_fork]);
	status_msg(voltaire, "has taken a fork (left)");
	if (voltaire->data->nbr_of_philos == 1)
	{
		pthread_mutex_unlock(&voltaire->data->forks[voltaire->l_fork]);
		return ;
	}
	pthread_mutex_lock(&voltaire->data->forks[voltaire->r_fork]);
	status_msg(voltaire, "has taken a fork (right)");
}

static void	__drop_forks(t_philo *descartes)
{
	pthread_mutex_unlock(&descartes->data->forks[descartes->r_fork]);
	pthread_mutex_unlock(&descartes->data->forks[descartes->l_fork]);
}

static void	__eat(t_philo *nietzsche)
{
	__take_forks(nietzsche);
	pthread_mutex_lock(&nietzsche->data->meal_lock);
	status_msg(nietzsche, "is eating");
	nietzsche->last_meal_time = get_current_timestamp();
	nietzsche->meals_eaten++;
	ft_usleep(nietzsche->data->time_to_eat, nietzsche->data);
	pthread_mutex_unlock(&nietzsche->data->meal_lock);
	__drop_forks(nietzsche);
}

static void	__asleep(t_philo *socrate)
{
	status_msg(socrate, "is sleeping");
	ft_usleep(socrate->data->time_to_sleep, socrate->data);
}

void	*routine(void *philo)
{
	t_philo	*platon;

	platon = (t_philo *)philo;
	if (platon->id % 2 == 0)
	{
		status_msg(platon, "is thinking");
		ft_usleep(200, platon->data); // changer valeur random
	}
	while (1)
	{
		if (check_if_someone_died(platon) == true)
			break ;
		__eat(platon);
		__asleep(platon);
		status_msg(platon, "is thinking");
	}
	return (NULL);
}
