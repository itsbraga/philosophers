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

static void	eat_func(t_prog *prog)
{
	pthread_mutex_lock(prog->philo->left_fork);
	show_status("has taken his/her left fork", prog->philo);
	if (prog->rules.nbr_of_philos == 1)
	{
		usleep(prog->rules.time_to_die);
		pthread_mutex_unlock(prog->philo->right_fork);
		return ;
	}
	pthread_mutex_lock(prog->philo->right_fork);
	show_status("has taken his/her right fork", prog->philo);
	prog->philo->ate = 1;
	show_status("is eating", prog->philo);
	pthread_mutex_lock(prog->philo->meal_lock);
	prog->philo->last_meal = get_current_time();
	prog->philo->meals_eaten++;
	pthread_mutex_unlock(prog->philo->meal_lock);
	usleep(prog->rules.time_to_eat);
	pthread_mutex_unlock(prog->philo->left_fork);
	pthread_mutex_unlock(prog->philo->right_fork);
}

static void	sleep_func(t_philo *philo)
{
	show_status("is sleeping", philo);
}

/*
	They don't really think, they wait until they have
	two forks to eat.
*/
static void	think_func(t_philo *philo)
{
	show_status("is thinking", philo);
}

void	*thread_tasks(void *data)
{
	t_philo *philo;
	t_prog	*prog;

	philo = (t_philo *)data;
	if (philo->id % 2 == 0)
		my_usleep(philo, 1);
	while (is_dead(philo) == false)
	{
		eat_func(prog);
		sleep_func(philo);
		think_func(philo);
	}
	return (data);
}

void	*start_thread_tasks(void *data)
{
	t_philo	*philos;

	philos = (t_philo *)data;
	// while (1)
	// {
	// 	if (check_if_is_dead(philos) == true
	// 		|| check_if_all_ate(philos) == true)
	// 		break ;
	// }
	return (data);
}
