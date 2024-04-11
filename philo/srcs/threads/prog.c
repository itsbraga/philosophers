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
	pthread_mutex_lock(philo->right_fork);
	// message("has taken his right fork", philo, philo->id);
	if (philo->rules->number_of_philos == 1)
	{
		usleep(philo->rules->time_to_die);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	pthread_mutex_lock(philo->left_fork);
	// message("has taken his left fork", philo, philo->id);
	philo->ate = 1;
	// message ("is eating", philo, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = // get_current_time();
	philo->rules->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	usleep(philo->rules->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

static void	sleep_func(t_philo *philo)
{
	// message("is sleeping", philo, philo->id);
}

static void	think_func(t_philo *philo)
{
	// message("is thinking", philo, philo->id);
}

void	*prog(void *ptr)
{
	t_philo *philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		usleep(1);
	while (is_dead(philo) == false)
	{
		// eat_func(philo);
		sleep_func(philo);
		think_func(philo);
	}
	return (ptr);
}

void	*start_prog(void *ptr)
{
	t_philo	*philos;

	philos = (t_philo *)ptr;
	// while (1)
	// {
	// 	if (check_if_is_dead(philos) == true
	// 		|| check_if_all_ate(philos) == true)
	// 		break ;
	// }
	return (ptr);
}
