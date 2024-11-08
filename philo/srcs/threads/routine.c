/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:29:26 by art3mis           #+#    #+#             */
/*   Updated: 2024/11/08 18:52:41 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*__philo_routine(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	if (philo->id % 2 == 1)
		my_usleep(philo, 200);
	while (philo->died == 0)
	{
		eat(philo);
		asleep(philo);
		think(philo);
	}
	return ((void *)0);
}

void	init_threads(t_data *ph_data)
{
	int	i;

	i = 0;
	ph_data->start_time = get_current_time();
	while (i < ph_data->nbr_of_philos)
	{
		if (pthread_create(&ph_data->philos[i].thread, NULL, &__philo_routine,
				(void *)&ph_data->philos[i]) != 0)
		{
			err_msg(ERR_THREAD_CREA);
			destroy_mutexes(ph_data);
		}
		i++;
	}
	i = 0;
	while (i < ph_data->nbr_of_philos)
	{
		if (pthread_join(ph_data->philos[i].thread, NULL) != 0)
		{
			err_msg(ERR_THREAD_JOIN);
			destroy_mutexes(ph_data);
		}
		i++;
	}
}
