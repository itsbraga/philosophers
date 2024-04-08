/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:46:13 by art3mis           #+#    #+#             */
/*   Updated: 2024/04/09 01:01:22 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int i;
	int sign;
	int res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= 48 && str[i] <= 57))
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * sign);
}

void	destroy_mutexes(char *str, t_routine *routine, pthread_mutex_t *forks)
{
	size_t	i;

	i = 0;
	if (str)
		printf("%s\n", str);
	pthread_mutex_destroy(&routine->dead_lock);
	pthread_mutex_destroy(&routine->meal_lock);
	while (i < routine->philos[0].number_of_philos)
		pthread_mutex_destroy(&forks[i++]);
}