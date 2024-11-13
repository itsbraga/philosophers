/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:18:59 by annabrag          #+#    #+#             */
/*   Updated: 2024/11/13 20:53:53 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H
# define MAX_NBR_OF_PHILOS 200

/******************************************************************************\
 * EXIT STATUS
\******************************************************************************/

# define SUCCESS 0
# define FAILURE 1

/******************************************************************************\
 * ERROR
\******************************************************************************/

# define ERR_PREFIX "\e[31m\e[1merror: \e[0m"

# define ERR_MALLOC "Memory allocation failed"
# define ERR_THREAD_CREA "Thread creation failed"
# define ERR_THREAD_JOIN "Thread join failed"

# define ERR_INIT_DATA "Failed to initialize from your parameters"
# define ERR_INIT_FORK "Something went wrong with fork initialization"
# define ERR_INIT_PHILO "Failed to initialize philosopher threads"

# define ERR_ARG "Invalid amount of arguments"
# define ERR_MUST_EAT "Invalid number_of_times_each_philosopher_must_eat"
# define ERR_PHILO "Invalid amount of philosophers"
# define ERR_TTD "Invalid time_to_die"
# define ERR_TTE "Invalid time_to_eat"
# define ERR_TTS "Invalid time_to_sleep"

#endif