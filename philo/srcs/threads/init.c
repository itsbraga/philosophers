/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:37:23 by art3mis           #+#    #+#             */
/*   Updated: 2024/04/09 00:58:47 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_forks_mutexes(pthread_mutex_t *forks, size_t number_of_philos)
{
	size_t	i;

	i = 0;
	while (i < number_of_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

int	init(t_philo *philo, char **argv)
{
	philo->number_of_philos = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
	{
		philo->number_times_must_eat = ft_atoi(argv[5]);
		if (philo->number_times_must_eat <= 0)
			return (EXIT_FAILURE);
	}
	else
		philo->number_times_must_eat = -1;
	return (EXIT_SUCCESS);
}
