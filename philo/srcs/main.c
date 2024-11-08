/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:28:53 by annabrag          #+#    #+#             */
/*   Updated: 2024/11/08 18:22:19 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	__walkthrough(void)
{
	printf("%s%s%s%s", BOLD, SEPARATOR_1, TITLE, SEPARATOR_2);
	rainbow_txt("\t./philo argv[1] argv[2] argv[3] argv[4]\n");
	printf("%s%s\n", RESET, "or");
	rainbow_txt("\t./philo argv[1] argv[2] argv[3] argv[4] argv[5]\n");
	printf("%s%s%s%s%s%s", RESET, ARGV1, ARGV2, ARGV3, ARGV4, ARGV5);
	printf("\n%s\n", FOOTER);
}

static int	__get_help_menu(void)
{
	write(2, "\n", 1);
	err_msg("Invalid amount of arguments.");
	write(2, "\n\n", 2);
	__walkthrough();
	return (FAILURE);
}

int	main(int argc, char **argv)
{
	t_data	ph_data;

	if (argc < 5 || argc > 6)
		__get_help_menu();
	if (args_check_is_successfull(argc, argv) == false)
		return (FAILURE);
	init(&ph_data, argv);
	init_threads(&ph_data);
	destroy_mutexes(&ph_data);
	return (SUCCESS);
}
