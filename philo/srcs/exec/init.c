/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:37:23 by art3mis           #+#    #+#             */
/*   Updated: 2024/11/08 18:19:53 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	__init_data(t_data *ph_data, char **argv)
{
	ph_data->nbr_of_philos = ft_atoi(argv[1]);
	ph_data->time_to_die = ft_atoi(argv[2]);
	ph_data->time_to_eat = ft_atoi(argv[3]);
	ph_data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
	{
		ph_data->nbr_times_each_must_eat = ft_atoi(argv[5]);
		if (ph_data->nbr_times_each_must_eat <= 0)
			return (FAILURE);
	}
	else
		ph_data->nbr_times_each_must_eat = -1;
	pthread_mutex_init(&ph_data->write_lock, NULL);
	pthread_mutex_init(&ph_data->dead_lock, NULL);
	pthread_mutex_init(&ph_data->meal_lock, NULL);
	return (SUCCESS);
}

static int	__init_forks(t_data *ph_data)
{
	int	i;

	ph_data->forks = malloc(sizeof(pthread_mutex_t) * ph_data->nbr_of_philos);
	if (ph_data->forks == NULL)
	{
		err_msg("Memory allocation failure --> forks");
		return (FAILURE);
	}
	i = 0;
	while (i < ph_data->nbr_of_philos)
	{
		if (pthread_mutex_init(&ph_data->forks[i], NULL) != 0)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

static void	__fork_assignment(t_data *ph_data)
{
	int	i;

	ph_data->philos[0].left_fork = &ph_data->forks[0];
	ph_data->philos[0].right_fork = &ph_data->forks[ph_data->nbr_of_philos - 1];
	i = 0;
	while (i < ph_data->nbr_of_philos)
	{
		ph_data->philos[i].left_fork = &ph_data->forks[i];
		ph_data->philos[i].right_fork = &ph_data->forks[i - 1];
		i++;
	}
}

static int	__init_philos(t_data *ph_data, char **argv)
{
	int	i;

	ph_data->philos = malloc(sizeof(t_philo) * ph_data->nbr_of_philos);
	if (ph_data->philos == NULL)
	{
		err_msg("Memory allocation failure --> philos");
		return (FAILURE);
	}
	i = 0;
	while (i < ph_data->nbr_of_philos)
	{
		ph_data->philos[i].data = ph_data;
		ph_data->philos[i].id = i + 1;
		ph_data->philos[i].is_eating = 0;
		ph_data->philos[i].meals_count = 0;
		ph_data->philos[i].data->start_time = get_current_time();
		ph_data->philos[i].last_meal = get_current_time();
		ph_data->philos[i].died = 0;
		i++;
	}
	return (SUCCESS);
}

int	init(t_data *ph_data, char **argv)
{
	ft_bzero(ph_data, sizeof(t_data));
	if (__init_data(ph_data, argv) == FAILURE)
	{
		err_msg("Failed to initialize from your parameters.");
		return (FAILURE);
	}
	if (__init_forks(ph_data) == FAILURE)
	{
		err_msg("Something went wrong with fork initialization.");
		return (FAILURE);
	}
	__fork_assignment(ph_data);
	if (__init_philos(ph_data, argv) == FAILURE)
	{
		err_msg("Failed to initialize philosopher threads.");
		return (FAILURE);
	}
	return (SUCCESS);
}
