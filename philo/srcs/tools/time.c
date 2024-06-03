/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:41:18 by art3mis           #+#    #+#             */
/*   Updated: 2024/06/03 21:43:11 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_current_time(void)
{
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) == -1)
	{
		printf("%s%s%s\n", RED, "Error: gettimeofday() failed", RESET);
		return (-1);
	}
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void	my_usleep(t_philo *philo, size_t time)
{
	size_t	start_time;

	start_time = get_current_time();
	while (death_check(philo) == false)
	{
		if (get_current_time() - start_time >= time)
			break ;
		usleep(100);
	}
}
