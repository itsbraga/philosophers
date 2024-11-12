/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 23:46:13 by art3mis           #+#    #+#             */
/*   Updated: 2024/11/12 22:06:58 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	status_msg(t_philo *aristote, char *str)
{
	size_t	timestamp;

	if (aristote->data->died == true)
		return ;
	pthread_mutex_lock(&aristote->data->write_lock);
	timestamp = get_current_timestamp() - aristote->data->sim_start;
	if (aristote->data->died == false)
		printf("%zu\t-  Philo %d %s\n", timestamp, aristote->id, str);
	pthread_mutex_unlock(&aristote->data->write_lock);
}

void	death_announcement(t_philo *rousseau, int i)
{
	size_t	timestamp;

	pthread_mutex_lock(&rousseau->data->write_lock);
	timestamp = get_current_timestamp() - rousseau->data->sim_start;
	printf("%zu\t-\tPhilo %d died\n", timestamp, rousseau[i].id);
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
