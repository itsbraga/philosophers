/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:46:13 by art3mis           #+#    #+#             */
/*   Updated: 2024/04/12 23:07:12 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	show_status(char *str, t_philo *philo)
{
	size_t	time;

	pthread_mutex_lock(philo->write_changes_lock);
	time = get_current_time() - philo->start_time;
	if (is_dead(philo) == false && time >= 0)
		printf("%zu\t-\tPhilo %d: %s\n", time, philo->id, str);
	pthread_mutex_unlock(philo->write_changes_lock);
}

bool    is_dead(t_philo *philo)
{
    pthread_mutex_lock(philo->dead_lock);
    if (*philo->died == 1)
    {
        pthread_mutex_unlock(philo->dead_lock);
        return (true);
    }
    pthread_mutex_unlock(philo->dead_lock);
    return (false);
}
