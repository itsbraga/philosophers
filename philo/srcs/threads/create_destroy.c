/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:29:26 by art3mis           #+#    #+#             */
/*   Updated: 2024/04/25 18:28:00 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void __free_all_data(t_data *ph_data)
{
    if (ph_data->philos)
        free(ph_data->philos);
    if (ph_data->forks)
        free(ph_data->forks);
}

void    destroy_mutexes(t_data *ph_data)
{
    int i;

    i = 0;
    while (i < ph_data->nbr_of_philos)
    {
        pthread_mutex_destroy(&ph_data->forks[i]);
        i++;
    }
    pthread_mutex_destroy(&ph_data->write_changes_lock);
    pthread_mutex_destroy(&ph_data->dead_lock);
    pthread_mutex_destroy(&ph_data->meal_lock);
    __free_all_data(ph_data);
}
