/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:46:13 by art3mis           #+#    #+#             */
/*   Updated: 2024/04/19 13:21:32 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool    is_dead(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->dead_lock);
    if (philo->data->died == 1)
    {
        pthread_mutex_unlock(&philo->data->dead_lock);
        return (true);
    }
    pthread_mutex_unlock(&philo->data->dead_lock);
    return (false);
}

void	show_status(char *str, t_philo *philo)
{
	size_t	time;

	pthread_mutex_lock(&philo->data->write_changes_lock);
	time = get_current_time() - philo->data->start_time;
	if (is_dead(philo) == false && time >= 0)
		printf("%zu\t-\tPhilo %d: %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->data->write_changes_lock);
}
