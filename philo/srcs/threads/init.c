/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:37:23 by art3mis           #+#    #+#             */
/*   Updated: 2024/04/19 13:18:24 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	__init_user_params(t_data *ph_data, char **argv)
{
	ph_data->nbr_of_philos = ft_atoi(argv[1]);
	ph_data->time_to_die = ft_atoi(argv[2]);
	ph_data->time_to_eat = ft_atoi(argv[3]);
	ph_data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
	{
		ph_data->nbr_times_must_eat = ft_atoi(argv[5]);
		if (ph_data->nbr_times_must_eat <= 0)
			return (EXIT_FAILURE);
	}
	else
		ph_data->nbr_times_must_eat = -1;
	// pthread_mutex_init(&ph_data->write_changes_lock, NULL);
	// pthread_mutex_init(&ph_data->dead_lock, NULL);
	// pthread_mutex_init(&ph_data->meal_lock, NULL);
	return (EXIT_SUCCESS);
}

int	init_forks(t_data *ph_data)
{
	int	i;

	i = 0;
	while (i < ph_data->nbr_of_philos)
	{
		if (pthread_mutex_init(&ph_data->forks[i], NULL) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	i = 0;
	ph_data->philos[0].left_fork = &ph_data->forks[0];
	ph_data->philos[0].right_fork = &ph_data->forks[ph_data->nbr_of_philos - 1];
	i = 1;
	while (i < ph_data->nbr_of_philos)
	{
		ph_data->philos[i].left_fork = &ph_data->forks[i];
		ph_data->philos[i].right_fork = &ph_data->forks[i - 1];
		i++;
	}
	return (EXIT_SUCCESS);
}

void	init_philos(t_data *ph_data, char **argv)
{
	int		i;

	i = 0;
	while (i < ph_data->nbr_of_philos)
	{
		ph_data->philos[i].data = ph_data;
		ph_data->philos[i].id = i + 1;
		ph_data->philos[i].eating = 0;
		ph_data->philos[i].meals_eaten = 0;
		ph_data->philos[i].data->start_time = get_current_time();
		ph_data->philos[i].last_meal = get_current_time();
		ph_data->died = 0;
		__init_user_params(&ph_data->philos[i], argv);
		pthread_mutex_init(&ph_data->write_changes_lock, NULL);
		pthread_mutex_init(&ph_data->dead_lock, NULL);
		pthread_mutex_init(&ph_data->meal_lock, NULL);
		i++;
	}
}

int	init(t_data *ph_data, char **argv)
{
	if (__init_user_params(ph_data, argv) == EXIT_FAILURE)
	{
		printf("%s%s\n", RED, "Error: could not initialize from your params.");
		printf("%s", RESET);
		return (EXIT_FAILURE);
	}
	if (init_forks(ph_data) == EXIT_FAILURE)
	{
		printf("%s%s", RED, "Error: could not initialize mutexes ");
		printf("%s%s\n", "for the forks.", RESET);
		return (EXIT_FAILURE);
	}
	init_philos(ph_data, argv);
	return (EXIT_SUCCESS);
}
