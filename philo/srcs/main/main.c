/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:28:53 by annabrag          #+#    #+#             */
/*   Updated: 2024/11/13 01:48:29 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*data_struct(void)
{
	static t_data	instance;

	return (&instance);
}

void	free_data(t_data *data)
{
	free(data->philo->thread);
	data->philo->thread = NULL;
	free(data->philo);
	data->philo = NULL;
	free(data->forks);
	data->forks = NULL;
}

// int	main(int argc, char **argv)
// {
// 	t_data	data;

// 	if (argc < 5 || argc > 6)
// 		get_help_menu();
// 	if (args_check_is_successfull(argc, argv) == false)
// 		return (FAILURE);
// 	if (init_structs(&data, argv) == FAILURE)
// 		return (FAILURE);
// 	if (manage_threads(data.philo, &data) == FAILURE)
// 		return (FAILURE);
// 	destroy_mutexes(&data);
// 	free_data(&data);
// 	return (SUCCESS);
// }

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
