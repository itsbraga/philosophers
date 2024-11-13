/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:37:23 by art3mis           #+#    #+#             */
/*   Updated: 2024/11/13 01:43:25 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	__init_data(t_data *data, char **argv)
{
	if (init_data_mutexes(data) == FAILURE)
		return (FAILURE);
	data->sim_start = get_current_timestamp();
	data->nbr_of_philos = ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);
	if (argv[5] != NULL)
		data->nbr_meal_must_eat = ft_atol(argv[5]);
	else
		data->nbr_meal_must_eat = -1;
	data->died = false;
	return (SUCCESS);
}

static int	__init_forks(t_data *data)
{
	unsigned int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->nbr_of_philos);
	if (data->forks == NULL)
		return (err_msg(ERR_MALLOC), FAILURE);
	i = 0;
	while (i < data->nbr_of_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

static int	__init_philos(t_data *data)
{
	unsigned int	i;

	data->philo = malloc(sizeof(t_philo) * data->nbr_of_philos);
	if (data->philo == NULL)
		return (err_msg(ERR_MALLOC), FAILURE);
	i = 0;
	while (i < data->nbr_of_philos)
	{
		data->philo[i].id = i + 1;
		data->philo[i].last_meal_time = data->sim_start;
		data->philo[i].meals_eaten = 0;
		data->philo[i].l_fork = i;
		if (i == data->nbr_of_philos - 1) // si c'est le dernier
			data->philo[i].r_fork = 0;
		else
			data->philo[i].r_fork = i + 1;
		data->philo[i].data = data;
		i++;
	}
	return (SUCCESS);
}

int	init_structs(char **argv)
{
	t_data	*data;

	data = data_struct();
	if (__init_data(data, argv) == FAILURE)
		return (err_msg(ERR_INIT_DATA), FAILURE);
	if (__init_forks(data) == FAILURE)
		return (err_msg(ERR_INIT_FORK), FAILURE);
	if (__init_philos(data) == FAILURE)
		return (err_msg(ERR_INIT_PHILO), FAILURE);
	return (SUCCESS);
}
