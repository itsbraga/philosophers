/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 23:46:13 by art3mis           #+#    #+#             */
/*   Updated: 2024/11/08 18:22:01 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	status_msg(char *str, t_philo *philo)
{
	size_t	timestamp;

	pthread_mutex_lock(&philo->data->write_lock);
	timestamp = get_current_time() - philo->data->start_time;
	if (philo->died == 0 && timestamp >= 0)
		printf("%zu\t-\tPhilo %d: %s\n", timestamp, philo->id, str);
	pthread_mutex_unlock(&philo->data->write_lock);
}

void	err_msg(char *reason)
{
	if (reason != NULL)
	{
		write(2, ERR_PREFIX, ft_strlen(ERR_PREFIX));
		write(2, reason, ft_strlen(reason));
		write(2, "\n", 1);
	}
}
