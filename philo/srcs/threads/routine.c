/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:29:26 by art3mis           #+#    #+#             */
/*   Updated: 2024/06/03 21:51:17 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*__philo_routine(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	if (philo->id % 2 == 0)
		my_usleep(philo, 1);
	while (death_check(philo) == false)
	{
		eat_func(philo);
		sleep_func(philo);
		think_func(philo);
	}
	return ((void *)0);
}

void	create_threads(t_data *ph_data)
{
	size_t	i;

	i = 0;
	ph_data->start_time = get_current_time();
	while (i < ph_data->nbr_of_philos)
	{
		if (pthread_create(&ph_data->philos[i].thread, NULL, &__philo_routine,
				&ph_data->philos[i]) != 0)
		{
			printf("%s%s%s\n", RED, "Error: Could not create threads.", RESET);
			destroy_mutexes(ph_data);
		}
		i++;
	}
	while (i < ph_data->nbr_of_philos)
	{
		if (pthread_join(ph_data->philos[i].thread, NULL) != 0)
		{
			printf("%s%s%s\n", RED, "Error: Could not join threads.", RESET);
			destroy_mutexes(ph_data);
		}
		i++;
	}
}
