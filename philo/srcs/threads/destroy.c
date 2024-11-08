/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:45:53 by annabrag          #+#    #+#             */
/*   Updated: 2024/11/08 18:21:19 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	__free_data(t_data *ph_data)
{
	if (ph_data->philos)
	{
		free(ph_data->philos);
		ph_data->philos = NULL;
	}
	if (ph_data->forks)
	{
		free(ph_data->forks);
		ph_data->forks = NULL;
	}
}

void	destroy_mutexes(t_data *ph_data)
{
	int	i;

	i = 0;
	while (i < ph_data->nbr_of_philos)
	{
		pthread_mutex_destroy(&ph_data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&ph_data->write_lock);
	pthread_mutex_destroy(&ph_data->dead_lock);
	pthread_mutex_destroy(&ph_data->meal_lock);
	__free_data(ph_data);
}
