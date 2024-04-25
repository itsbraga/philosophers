/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:34:10 by art3mis           #+#    #+#             */
/*   Updated: 2024/04/25 18:19:36 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_monitoring(void *philo_ptr)
{
	t_philo	*philos;

	philos = (t_philo *)philo_ptr;
	while (1)
	{
		if (check_if_one_died(philos) == true)
			break ;
	}
	return (philo_ptr);
}
