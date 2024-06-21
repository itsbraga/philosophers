/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:15:34 by art3mis           #+#    #+#             */
/*   Updated: 2024/06/21 17:21:57 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	__is_space(char *argv)
{
	size_t	i;

	i = 0;
	if (argv[i] == 32 || (argv[i] >= 9 && argv[i] <= 13))
		return (true);
	return (false);
}

static bool	__is_only_number(char *argv)
{
	size_t	i;

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

static void	__errcontext_n_exit(char *reason)
{
	while (*reason)
	{
		write(STDERR_FILENO, "\nError: ", 8);
		write(STDERR_FILENO, reason, ft_strlen(reason));
		write(STDERR_FILENO, "\n", 1);
	}
	exit(EXIT_FAILURE);
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
			__errcontext_n_exit("Only integers are allowed");
		i++;
	}
	if (ft_atoi(argv[1]) > MAX_NBR_OF_PHILOS || ft_atoi(argv[1]) <= 0)
		__errcontext_n_exit("Invalid amount of philosophers");
	if (ft_atoi(argv[2]) <= 0)
		__errcontext_n_exit("Invalid time to die");
	if (ft_atoi(argv[3]) <= 0)
		__errcontext_n_exit("Invalid time to eat");
	if (ft_atoi(argv[4]) <= 0)
		__errcontext_n_exit("Invalid time to sleep");
	if (argv[5] != NULL && (ft_atoi(argv[5]) < 0))
		__errcontext_n_exit("Invalid number of times a philosopher must eat");
	printf("\n%s%s%s%s\n\n", BOLD, GREEN, "\nCheck successfull! ✅", RESET);
	return (true);
}
