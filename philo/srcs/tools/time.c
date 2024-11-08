/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:41:18 by art3mis           #+#    #+#             */
/*   Updated: 2024/11/08 18:22:11 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_current_time(void)
{
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) == -1)
	{
		err_msg("gettimeofday() failed");
		return (-1);
	}
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void	my_usleep(t_philo *philo, size_t time)
{
	size_t	start_time;

	start_time = get_current_time();
	while (philo->died == 0)
	{
		if (get_current_time() - start_time >= time)
			break ;
		usleep(100);
	}
}
