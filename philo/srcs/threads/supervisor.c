/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:37:09 by art3mis           #+#    #+#             */
/*   Updated: 2024/11/13 00:57:56 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_if_someone_died(t_philo *confucius)
{
	pthread_mutex_lock(&confucius->data->death_lock);
	if (confucius->data->died == true)
	{
		pthread_mutex_unlock(&confucius->data->death_lock);
		return (true);
	}
	pthread_mutex_unlock(&confucius->data->death_lock);
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
	size_t			curr_time;

	while (1)
	{
		i = 0;
		while (i < data->nbr_of_philos)
		{
			pthread_mutex_lock(&data->meal_lock);
			curr_time = get_current_timestamp();
			if (curr_time - data->philo[i].last_meal_time >= data->time_to_die)
			{
				pthread_mutex_unlock(&data->meal_lock);
				return (__someone_died(data, i));
			}
			if (__check_if_all_ate(data) == true)
			{
				pthread_mutex_unlock(&data->meal_lock);
				return ;
			}
			pthread_mutex_unlock(&data->meal_lock);
			i++;
		}
		ft_usleep(1, data);
	}
}
