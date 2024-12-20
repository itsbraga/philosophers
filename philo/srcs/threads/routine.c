/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:20:45 by annabrag          #+#    #+#             */
/*   Updated: 2024/11/15 00:10:44 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	__take_forks(t_philo *voltaire)
{
	if (voltaire->id % 2 == 0)
	{
		pthread_mutex_lock(&voltaire->data->forks[voltaire->r_fork]);
		status_msg(voltaire, "has taken a fork");
		pthread_mutex_lock(&voltaire->data->forks[voltaire->l_fork]);
		status_msg(voltaire, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&voltaire->data->forks[voltaire->l_fork]);
		status_msg(voltaire, "has taken a fork");
		pthread_mutex_lock(&voltaire->data->forks[voltaire->r_fork]);
		status_msg(voltaire, "has taken a fork");
	}
}

static void	__drop_forks(t_philo *descartes)
{
	if (descartes->id % 2 == 0)
	{
		pthread_mutex_unlock(&descartes->data->forks[descartes->r_fork]);
		pthread_mutex_unlock(&descartes->data->forks[descartes->l_fork]);
	}
	else
	{
		pthread_mutex_unlock(&descartes->data->forks[descartes->l_fork]);
		pthread_mutex_unlock(&descartes->data->forks[descartes->r_fork]);
	}
}

static void	__eat(t_philo *nietzsche)
{
	__take_forks(nietzsche);
	pthread_mutex_lock(&nietzsche->data->meal_lock);
	status_msg(nietzsche, "is eating");
	nietzsche->last_meal_time = get_current_timestamp();
	nietzsche->meals_eaten++;
	if ((int)nietzsche->meals_eaten == data_struct()->nbr_meal_must_eat)
	{
		pthread_mutex_lock(&data_struct()->full_lock);
		data_struct()->full++;
		pthread_mutex_unlock(&data_struct()->full_lock);
	}
	pthread_mutex_unlock(&nietzsche->data->meal_lock);
	ft_usleep(nietzsche->data->time_to_eat, nietzsche->data);
	__drop_forks(nietzsche);
}

static void	__sleep(t_philo *socrate)
{
	status_msg(socrate, "is sleeping");
	ft_usleep(socrate->data->time_to_sleep, socrate->data);
}

void	*routine(void *philo)
{
	t_philo	*platon;

	platon = (t_philo *)philo;
	if (data_struct()->nbr_of_philos == 1)
		philone(platon);
	if (platon->id % 2 == 0)
		ft_usleep(10, data_struct());
	while (check_if_someone_died(platon) == false)
	{
		__eat(platon);
		if (data_struct()->nbr_of_philos % 2 == 1)
			ft_usleep(data_struct()->time_to_eat / 3, data_struct());
		if (check_if_someone_died(platon) == true)
			break ;
		__sleep(platon);
		status_msg(platon, "is thinking");
	}
	return (NULL);
}
