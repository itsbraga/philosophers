/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:37:23 by art3mis           #+#    #+#             */
/*   Updated: 2024/04/26 18:26:50 by annabrag         ###   ########.fr       */
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
		ph_data->nbr_times_each_must_eat = ft_atoi(argv[5]);
		if (ph_data->nbr_times_each_must_eat <= 0)
			return (EXIT_FAILURE);
	}
	else
		ph_data->nbr_times_each_must_eat = -1;
	return (EXIT_SUCCESS);
}

static int	__init_forks(t_data *ph_data)
{
	size_t	i;

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
	i = 0;
	printf("nb philos: %zu\n", ph_data->nbr_of_philos);
	while (i < ph_data->nbr_of_philos)
	{
		ph_data->philos[i].left_fork = &ph_data->forks[i];
		ph_data->philos[i].right_fork = &ph_data->forks[i - 1];
		i++;
	}
	return (EXIT_SUCCESS);
}

// static int	__init_mutexes_forks(t_data *ph_data)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < ph_data->nbr_of_philos)
// 	{
// 		if (pthread_mutex_init(&ph_data->forks[i], NULL) != 0)
// 			return (EXIT_FAILURE);
// 		i++;
// 	}
// }

static void	__init_philos(t_data *ph_data, char **argv)
{
	size_t	i;

	i = 0;
	while (i < ph_data->nbr_of_philos)
	{
		ph_data->philos[i].data = ph_data;
		ph_data->philos[i].id = i + 1;
		ph_data->philos[i].eating = 0;
		ph_data->philos[i].meals_count = 0;
		ph_data->philos[i].data->start_time = get_current_time();
		ph_data->philos[i].last_meal = get_current_time();
		ph_data->philos[i].died = 0;
		__init_user_params(ph_data, argv);
		i++;
	}
}

int	init(t_data *ph_data, char **argv)
{
	ft_bzero(ph_data, sizeof(t_data));
	pthread_mutex_init(&ph_data->write_changes_lock, NULL);
	pthread_mutex_init(&ph_data->dead_lock, NULL);
	pthread_mutex_init(&ph_data->meal_lock, NULL);
	if (__init_user_params(ph_data, argv) == EXIT_FAILURE)
	{
		printf("%s%s\n", RED, "Error: could not initialize from your params.");
		printf("%s", RESET);
		return (EXIT_FAILURE);
	}
	if (__init_forks(ph_data) == EXIT_FAILURE)
	{
		printf("%s%s", RED, "Error: could not initialize mutexes ");
		printf("%s%s\n", "for the forks.", RESET);
		return (EXIT_FAILURE);
	}
	__init_philos(ph_data, argv);
	return (EXIT_SUCCESS);
}
