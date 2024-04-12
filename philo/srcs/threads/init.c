/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:37:23 by art3mis           #+#    #+#             */
/*   Updated: 2024/04/13 00:35:29 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	__init_user_params(t_prog *prog, char **argv)
{
	prog->rules.nbr_of_philos = ft_atoi(argv[1]);
	prog->rules.time_to_die = ft_atoi(argv[2]);
	prog->rules.time_to_eat = ft_atoi(argv[3]);
	prog->rules.time_to_sleep = ft_atoi(argv[4]);
	prog->philo->died = 0;
	if (argv[5] != NULL)
	{
		prog->rules.nbr_times_must_eat = ft_atoi(argv[5]);
		if (prog->rules.nbr_times_must_eat <= 0)
			return (EXIT_FAILURE);
	}
	else
		prog->rules.nbr_times_must_eat = -1;
	return (EXIT_SUCCESS);
}

void	init_forks(pthread_mutex_t *forks, size_t nbr_of_philos)
{
	int	i;

	i = 0;
	while (i < nbr_of_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

int	init_philos(t_prog *prog, pthread_mutex_t *forks, char **argv)
{
	int		i;
	size_t	nbr_of_philos;

	i = 0;
	nbr_of_philos = ft_atoi(argv[1]);
	while (i < nbr_of_philos)
	{
		prog->philo[i].id = i + 1;
		prog->philo[i].ate = 0;
		prog->philo[i].meals_eaten = 0;
		__init_user_params(&prog->philo[i], argv);
		prog->philo[i].start_time = get_current_time();
		prog->philo[i].last_meal = get_current_time();
		prog->philo[i].write_changes_lock = &prog->write_changes_lock;
		prog->philo[i].dead_lock = &prog->dead_lock;
		prog->philo[i].meal_lock = &prog->meal_lock;
		prog->philo[i].died = &prog->dead_flag; // can be changed by only died = 0 if not (int *)
		prog->philo[i].left_fork = &forks[i];
		// if (i == 0)
		// 	prog->philo[i].right_fork = &forks[prog->rules->nbr_of_philos - 1];
		// else
		// 	prog->philo[i].right_fork = &forks[i - 1];
		i++;
	}
}

void	init_prog(t_prog *prog, t_rules rules, t_philo *philo)
{
	prog->dead_flag = 0;
	prog->philo = philo;
	prog->rules = rules;
	pthread_mutex_init(&prog->write_changes_lock, NULL);
	pthread_mutex_init(&prog->dead_lock, NULL);
	pthread_mutex_init(&prog->meal_lock, NULL);
}
