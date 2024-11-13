/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 23:46:13 by art3mis           #+#    #+#             */
/*   Updated: 2024/11/13 21:16:58 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	status_msg(t_philo *aristote, char *str)
{
	size_t	timestamp;

	pthread_mutex_lock(&aristote->data->write_lock);
	timestamp = get_current_timestamp() - aristote->data->sim_start;
	pthread_mutex_lock(&aristote->data->death_lock);
	if (aristote->data->died == false)
		printf("%zu %d %s\n", timestamp, aristote->id, str);
	pthread_mutex_unlock(&aristote->data->death_lock);
	pthread_mutex_unlock(&aristote->data->write_lock);
}

void	death_announcement(t_philo *rousseau, int i)
{
	size_t	timestamp;

	pthread_mutex_lock(&rousseau->data->write_lock);
	timestamp = get_current_timestamp() - rousseau->data->sim_start;
	printf("%zu %d died\n", timestamp, rousseau[i].id);
	pthread_mutex_unlock(&rousseau->data->write_lock);
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
