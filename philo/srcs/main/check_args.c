/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:19:21 by annabrag          #+#    #+#             */
/*   Updated: 2024/11/13 01:48:51 by art3mis          ###   ########.fr       */
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
	 Checks if the input contains only numbers, they should all be bigger
	 than 0 except the number of meals each philo needs to eat.
*/
bool	args_check_is_successfull(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argv == NULL || argv[i] == NULL)
		return (false);
	if (argc < 5 || argc > 6)
		get_help_menu();
	while (i < argc)
	{
		if (__is_only_number(argv[i]) == false)
			__exit_with_context("Only integers are allowed");
		i++;
	}
	if (ft_atol(argv[1]) > MAX_NBR_OF_PHILOS || ft_atol(argv[1]) <= 0)
		__exit_with_context(ERR_PHILO);
	if (ft_atol(argv[2]) <= 0)
		__exit_with_context(ERR_TTD);
	if (ft_atol(argv[3]) <= 0)
		__exit_with_context(ERR_TTE);
	if (ft_atol(argv[4]) <= 0)
		__exit_with_context(ERR_TTS);
	if (argv[5] != NULL && (ft_atol(argv[5]) < 0))
		__exit_with_context(ERR_MUST_EAT);
	printf("\n%s\n\n\n", BOLD BLINK GREEN "Argument check passed successfully!"\
	RESET);
	return (true);
}
