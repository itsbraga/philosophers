/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:28:53 by annabrag          #+#    #+#             */
/*   Updated: 2024/11/13 12:12:27 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_data(t_data *data)
{
	if (data->philo != NULL && data->philo->thread != NULL)
	{
		free(data->philo->thread);
		data->philo->thread = NULL;
	}
	if (data->philo != NULL)
	{
		free(data->philo);
		data->philo = NULL;
	}
	if (data->forks != NULL)
	{
		free(data->forks);
		data->forks = NULL;
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = data_struct();
	if (args_check_is_successfull(argc, argv) == false)
		return (FAILURE);
	if (init_structs(argv) == FAILURE)
		return (FAILURE);
	if (manage_threads(data->philo) == FAILURE)
		return (FAILURE);
	destroy_mutexes(data);
	free_data(data);
	return (SUCCESS);
}
