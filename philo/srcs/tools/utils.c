/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:46:13 by art3mis           #+#    #+#             */
/*   Updated: 2024/04/26 12:40:39 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	status_msg(char *str, t_philo *philo)
{
	size_t	time;

	pthread_mutex_lock(&philo->data->write_changes_lock);
	time = get_current_time() - philo->data->start_time;
	if (death_check(philo) == false && time >= 0)
		printf("%zu\t-\tPhilo %d: %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->data->write_changes_lock);
}
