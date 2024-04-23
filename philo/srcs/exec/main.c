/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:28:53 by annabrag          #+#    #+#             */
/*   Updated: 2024/04/19 12:41:05 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	__walkthrough(void)
{
	printf("%s%s%s%s", BOLD, SEPARATOR_1, TITLE, SEPARATOR_2);
	rainbow_txt("\t./philo argv[1] argv[2] argv[3] argv[4] argv[5]\n");
	printf("%s%s\n", RESET, "argv[1]:\tnumber of philosophers");
	printf("%s\n", "argv[2]:\ttime a philosopher will die if he doesn't eat");
	printf("%s\n", "argv[3]:\ttime it takes a philosopher to eat");
	printf("%s\n", "argv[4]:\ttime it takes a philosopher to sleep");
	printf("%s\n\n", "argv[5]:\tnumber of times a philosopher must eat");
	printf("%s\n\n", FOOTER);
}

static int	__error_help(void)
{
	printf("%s%s%s", BOLD, RED, "\nError: Invalid amount of arguments");
	printf("%s\n\n\n", RESET);
	__walkthrough();
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_prog			prog;
	t_data			data;
	t_philo			philos[MAX_NBR_OF_PHILOS];
	pthread_mutex_t	forks[MAX_NBR_OF_PHILOS];
	size_t			nbr_of_philos;

	if (argc != 5 || argc != 6)
		__error_help();
	if (args_check_successfull(argc, argv) == false)
		return (EXIT_FAILURE);
	nbr_of_philos = ft_atoi(argv[1]);
	init_prog(&prog, data, philos);
	init_forks(forks, nbr_of_philos);
	init_philos(&prog, forks, argv);
	// create threads + destroy mutexes;
	return (EXIT_SUCCESS);
}
