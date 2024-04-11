/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:37:23 by art3mis           #+#    #+#             */
/*   Updated: 2024/04/11 16:35:29 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_from_user_params(t_rules *rules, char **argv)
{
	rules->number_of_philos = ft_atoi(argv[1]);
	rules->time_to_die = ft_atoi(argv[2]);
	rules->time_to_eat = ft_atoi(argv[3]);
	rules->time_to_sleep = ft_atoi(argv[4]);
	rules->died = 0;
	if (argv[5] != NULL)
	{
		rules->number_times_must_eat = ft_atoi(argv[5]);
		if (rules->number_times_must_eat <= 0)
			return (EXIT_FAILURE);
	}
	else
		rules->number_times_must_eat = -1;
	return (EXIT_SUCCESS);
}

int	init_philos(t_rules *rules, t_prog *prog, pthread_mutex_t *forks, char **argv)
{
	int		i;
	size_t	number_of_philos;

	i = 0;
	number_of_philos = ft_atoi(argv[1]);
	while (i < number_of_philos)
	{
		rules->philo[i].id = i + 1;
		rules->philo[i].ate = 0;
		rules->philo[i].meals_eaten = 0;
		rules->philo[i].rules = rules;
		init_from_user_params(&rules->philo[i], argv);
		rules->philo[i].start_time = gettimeofday(, NULL);
		i++;
	}
}

void	init_mutexes(pthread_mutex_t *forks, size_t number_of_philos)
{
	size_t	i;

	i = 0;
	while (i < number_of_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}
