/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:09:39 by art3mis           #+#    #+#             */
/*   Updated: 2024/11/13 21:46:49 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data_mutexes(t_data *data)
{
	if (pthread_mutex_init(&data->write_lock, NULL) != 0)
		return (FAILURE);
	if (pthread_mutex_init(&data->death_lock, NULL) != 0)
		return (FAILURE);
	if (pthread_mutex_init(&data->meal_lock, NULL) != 0)
		return (FAILURE);
	return (SUCCESS);
}

int manage_threads(t_philo *locke)
{
	unsigned int	i;

	locke->thread = malloc(sizeof(pthread_t) * data_struct()->nbr_of_philos);
	if (locke->thread == NULL)
		return (err_msg(ERR_MALLOC), FAILURE);
	i = 0;
	while (i < data_struct()->nbr_of_philos)
	{
		if (pthread_create(&locke->thread[i], NULL, &routine, \
			(void *)&locke[i]) != 0)
		{
			while (i--)
				pthread_join(locke->thread[i], NULL);
			free(locke->thread);
			return (err_msg(ERR_THREAD_CREA), FAILURE);
		}
		i++;
	}
	supervisor(data_struct());
	i = 0;
	while (i < data_struct()->nbr_of_philos)
	{
		if (pthread_join(locke->thread[i], NULL) != 0)
			return (err_msg(ERR_THREAD_JOIN), FAILURE);
		i++;
	}
	return (SUCCESS);
}

void	destroy_mutexes(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->nbr_of_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->death_lock);
	pthread_mutex_destroy(&data->meal_lock);
}
