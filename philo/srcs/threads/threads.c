/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:09:39 by art3mis           #+#    #+#             */
/*   Updated: 2024/11/12 22:46:10 by art3mis          ###   ########.fr       */
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

static int  __join_threads(t_philo *confucius, t_data *data)
{
    unsigned int i;

    i = 0;
	while (i < data->nbr_of_philos)
	{
		if (pthread_join(confucius->thread[i], NULL) != 0)
		{
			free(confucius->thread);
            return (err_msg(ERR_THREAD_JOIN), FAILURE);
		}
		i++;
	}
    return (SUCCESS);
}

int manage_threads(t_philo *confucius, t_data *data)
{
	unsigned int	i;

	confucius->thread = malloc(sizeof(pthread_t) * data->nbr_of_philos);
	if (confucius->thread == NULL)
		return (FAILURE);
	i = 0;
	while (i < data->nbr_of_philos)
	{
		if (pthread_create(&confucius->thread[i], NULL, &routine, \
				(void *)&confucius[i]) != 0)
		{
			free(confucius->thread);
            return (err_msg(ERR_THREAD_CREA), FAILURE);
		}
		i++;
	}
	supervisor(data);
    if (__join_threads(confucius, data) == FAILURE)
        return (FAILURE);
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
