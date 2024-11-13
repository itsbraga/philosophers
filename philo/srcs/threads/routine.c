/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:20:45 by annabrag          #+#    #+#             */
/*   Updated: 2024/11/13 00:38:27 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	__take_forks(t_philo *voltaire)
{
	if (voltaire->id % 2 == 0)
	{
		pthread_mutex_lock(&voltaire->data->forks[voltaire->r_fork]);
		status_msg(voltaire, "has taken a fork \e[3m(right)\e[0m");
		pthread_mutex_lock(&voltaire->data->forks[voltaire->l_fork]);
		status_msg(voltaire, "has taken a fork \e[3m(left)\e[0m");
	}
	else
	{
		pthread_mutex_lock(&voltaire->data->forks[voltaire->l_fork]);
		status_msg(voltaire, "has taken a fork \e[3m(left)\e[0m");
		pthread_mutex_lock(&voltaire->data->forks[voltaire->r_fork]);
		status_msg(voltaire, "has taken a fork \e[3m(right)\e[0m");
	}
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
	pthread_mutex_unlock(&nietzsche->data->meal_lock);
	ft_usleep(nietzsche->data->time_to_eat, nietzsche->data);
	__drop_forks(nietzsche);
}

void	*routine(void *philo)
{
	t_philo	*platon;

	platon = (t_philo *)philo;
	if (platon->id % 2 == 0)
	{
		status_msg(platon, "is thinking...");
		ft_usleep(1, platon->data);
	}
	while (check_if_someone_died(platon) == false)
	{
		__eat(platon);
		if (check_if_someone_died(platon) == true)
			break ;
		status_msg(platon, "is sleeping 🧸");
		ft_usleep(platon->data->time_to_sleep, platon->data);
		status_msg(platon, "is thinking...");
	}
	return (NULL);
}
