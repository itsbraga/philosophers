/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:45:53 by annabrag          #+#    #+#             */
/*   Updated: 2024/04/26 17:12:26 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	__free_data(t_data *ph_data)
{
	if (ph_data->philos)
		free(ph_data->philos);
	if (ph_data->forks)
		free(ph_data->forks);
}

void	destroy_mutexes(t_data *ph_data)
{
	size_t	i;

	i = 0;
	while (i < ph_data->nbr_of_philos)
	{
		pthread_mutex_destroy(&ph_data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&ph_data->write_changes_lock);
	pthread_mutex_destroy(&ph_data->dead_lock);
	pthread_mutex_destroy(&ph_data->meal_lock);
	__free_data(ph_data);
}
