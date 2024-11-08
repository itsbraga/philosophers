/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:19:21 by annabrag          #+#    #+#             */
/*   Updated: 2024/11/08 18:19:45 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	__is_space(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == 32 || (argv[i] >= 9 && argv[i] <= 13))
		return (true);
	return (false);
}

static bool	__is_only_number(char *argv)
{
	int	i;

	i = 0;
	if (__is_space(&argv[i]) && argv[i + 1] == true)
		i++;
	while (argv[i] != '\0')
	{
		if (argv[i] < 48 || argv[i] > 57)
			return (false);
		i++;
	}
	return (true);
}

static void	__exit_with_context(char *reason)
{
	write(2, "\n", 1);
	err_msg(reason);
	exit(FAILURE);
}

/*
	 Check that the input contains only numbers, they should all be bigger
	 than 0 except the number of meals each philo needs to eat.
*/
bool	args_check_is_successfull(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (__is_only_number(argv[i]) == false)
			__exit_with_context("Only integers are allowed");
		i++;
	}
	if (ft_atoi(argv[1]) > MAX_NBR_OF_PHILOS || ft_atoi(argv[1]) <= 0)
		__exit_with_context("Invalid amount of philosophers");
	if (ft_atoi(argv[2]) <= 0)
		__exit_with_context("Invalid time_to_die");
	if (ft_atoi(argv[3]) <= 0)
		__exit_with_context("Invalid time_to_eat");
	if (ft_atoi(argv[4]) <= 0)
		__exit_with_context("Invalid time_to_sleep");
	if (argv[5] != NULL && (ft_atoi(argv[5]) < 0))
		__exit_with_context("Invalid \
		number_of_times_each_philosopher_must_eat");
	printf("\n%s%s%s\n\n", BOLD GREEN, "\nCheck successfull! ✅", RESET);
	return (true);
}
