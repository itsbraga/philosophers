/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:40:01 by art3mis           #+#    #+#             */
/*   Updated: 2024/11/13 20:55:48 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (s == NULL && n == 0)
		return ;
	while (i < n)
	{
		*(char *)(s + i) = 0;
		i++;
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

long	ft_atol(const char *str)
{
	long	sign;
	long	nbr;

	if (str == NULL)
		return (0);
	while (*str != '\0' && (*str == 32 || (*str >= 9 && *str <= 13)))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	nbr = 0;
	while (*str != '\0' && (*str >= 48 && *str <= 57))
	{
		nbr = (nbr * 10) + (*str - 48);
		str++;
	}
	return (nbr * sign);
}
