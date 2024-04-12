/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:41:18 by art3mis           #+#    #+#             */
/*   Updated: 2024/04/13 00:23:21 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_current_time(void)
{
	struct timeval	current_time;
	
	if (gettimeofday(&current_time, NULL) == -1)
	{
		printf("%s%s%s\n", BOLD, RED, "Error: gettimeofday() returned -1");
		printf("%s", RESET);
		return (-1);
	}
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void	my_usleep(t_philo *philo, size_t time)
{
	size_t	start_time;

	start_time = get_current_time();
	while (is_dead(philo) == false)
	{
		if (get_current_time() - start_time >= time)
			break ;
		usleep(100);
	}
}
