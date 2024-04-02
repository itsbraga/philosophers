/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:37:14 by annabrag          #+#    #+#             */
/*   Updated: 2024/04/02 15:21:39 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>

typedef struct s_philo
{
	pthread_t	thread;
	long long	time_to_eat;
	long long	time_to_sleep;
	long long	time_to_die;
}				t_philo;
