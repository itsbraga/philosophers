/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:18:10 by annabrag          #+#    #+#             */
/*   Updated: 2024/11/13 01:43:46 by art3mis          ###   ########.fr       */
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
 * MAIN
\******************************************************************************/

// parsing.c
bool	args_check_is_successfull(int argc, char **argv);

// init_structs.c
int		init_structs(char **argv);

// main.c
t_data	*data_struct(void);

/******************************************************************************\
 * THREADS
\******************************************************************************/

// routine.c
void	*routine(void *philo);

// threads.c
int		init_data_mutexes(t_data *data);
int		manage_threads(t_philo *locke);
void	destroy_mutexes(t_data *data);

// supervisor.c
bool	check_if_someone_died(t_philo *confucius);
void	supervisor(t_data *data);

/******************************************************************************\
 * TOOLS
\******************************************************************************/

// custom.c
void	rainbow_txt_nonl(const char *str);
char	*color_if_nbr(const char *str);
int		get_help_menu(void);

// lib.c
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *str);
long	ft_atol(const char *str);
char	*ft_strcat(char *dest, char *src);
char	*ft_strncat(char *dest, char *src, size_t n);

// msg.c
void	status_msg(t_philo *aristote, char *str);
void	death_announcement(t_philo *rousseau, int i);
void	err_msg(char *reason);

// time.c
size_t	get_current_timestamp(void);
void	ft_usleep(size_t msec, t_data *data);

#endif