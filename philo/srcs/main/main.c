/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:28:53 by annabrag          #+#    #+#             */
/*   Updated: 2024/11/12 22:44:36 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_data(t_data *data)
{
	if (data->philo)
	{
		free(data->philo);
		data->philo = NULL;
	}
	if (data->forks)
	{
		free(data->forks);
		data->forks = NULL;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
		get_help_menu();
	if (args_check_is_successfull(argc, argv) == false)
		return (FAILURE);
	if (init_structs(&data, argv) == FAILURE)
		return (FAILURE);
	if (manage_threads(data.philo, &data) == FAILURE)
		return (FAILURE);
	destroy_mutexes(&data);
	free_data(&data);
	return (SUCCESS);
}
