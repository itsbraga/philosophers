/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:37:09 by art3mis           #+#    #+#             */
/*   Updated: 2024/11/12 23:09:11 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_if_someone_died(t_philo *locke)
{
	pthread_mutex_lock(&locke->data->death_lock);
	if (locke->data->died == true)
	{
		pthread_mutex_unlock(&locke->data->death_lock);
		return (true);
	}
	pthread_mutex_unlock(&locke->data->death_lock);
	return (false);
}

static void	__someone_died(t_data *data, int i)
{
	pthread_mutex_lock(&data->death_lock);
	data->died = true;
	pthread_mutex_unlock(&data->death_lock);
	death_announcement(data->philo, i);
}

static bool	__check_if_all_ate(t_data *data)
{
	unsigned int	i;
	unsigned int	count;

	if (data->nbr_meal_must_eat == -1)
		return (false);
	i = 0;
	count = 0;
	pthread_mutex_lock(&data->meal_lock);
	while (i < data->nbr_of_philos)
	{
		if ((int)data->philo[i].meals_eaten >= data->nbr_meal_must_eat)
			count++;
		i++;
	}
	pthread_mutex_unlock(&data->meal_lock);
	if (count == data->nbr_of_philos)
		return (true);
	return (false);
}

void	supervisor(t_data *data)
{
	unsigned int	i;

	while (1)
	{
		i = 0;
		while (i < data->nbr_of_philos)
		{
			if (__check_if_all_ate(data) == true)
				break ;
			if (get_current_timestamp() - data->philo[i].last_meal_time
				>= data->time_to_die)
			{
				__someone_died(data, i);
				break ;
			}
			i++;
		}
	}
}
