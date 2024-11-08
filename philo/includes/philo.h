/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:18:10 by annabrag          #+#    #+#             */
/*   Updated: 2024/11/08 18:20:05 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdbool.h>
# include "structs.h"
# include "defines.h"
# include "colors.h"

/******************************************************************************\
 * EXEC
\******************************************************************************/

// check_args.c
bool	args_check_is_successfull(int argc, char **argv);

// init.c
int		init(t_data *ph_data, char **argv);

/******************************************************************************\
 * THREADS
\******************************************************************************/

// destroy.c
void	destroy_mutexes(t_data *ph_data);

// forks.c
void	take_forks(t_philo *philo);
void	drop_forks(t_philo *philo);

// actions.c
void	eat(t_philo *philo);
void	asleep(t_philo *philo);
void	think(t_philo *philo);
bool	death_check(t_philo *philo);

// routine.c
void	init_threads(t_data *ph_data);

/******************************************************************************\
 * TOOLS
\******************************************************************************/

// lib.c
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);

// msg.c
void	status_msg(char *str, t_philo *philo);
void	err_msg(char *reason);

// time.c
size_t	get_current_time(void);
void	my_usleep(t_philo *philo, size_t time);

#endif