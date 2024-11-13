/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:41:18 by art3mis           #+#    #+#             */
/*   Updated: 2024/11/13 21:34:09 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_current_timestamp(void)
{
	struct timeval	curr_time;

	if (gettimeofday(&curr_time, NULL) == -1)
	{
		err_msg("gettimeofday() failed");
		return (-1);
	}
	return ((curr_time.tv_sec * 1000) + (curr_time.tv_usec / 1000));
}

void	ft_usleep(size_t msec, t_data *data)
{
	// diviser ca tout les X pour que si il un philo meurt 
	// il arrete le programme
	size_t	start;
	bool	is_dead;

	start = get_current_timestamp();
	is_dead = check_if_someone_died(data->philo);
	while ((get_current_timestamp() - start < msec) && is_dead == false)
		usleep(1000);
}
