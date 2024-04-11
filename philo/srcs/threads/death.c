/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:54:45 by art3mis           #+#    #+#             */
/*   Updated: 2024/04/11 15:56:36 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool    is_dead(t_philo *philo)
{
    pthread_mutex_lock(philo->dead_lock);
    if (*philo->rules->died == 1)
    {
        pthread_mutex_unlock(philo->dead_lock);
        return (true);
    }
    pthread_mutex_unlock(philo->dead_lock);
    return (false);
}
