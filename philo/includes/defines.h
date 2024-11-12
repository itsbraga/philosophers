/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:18:59 by annabrag          #+#    #+#             */
/*   Updated: 2024/11/12 21:05:37 by art3mis          ###   ########.fr       */
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

/******************************************************************************\
 * WALKTHROUGH MENU
\******************************************************************************/

# define SEPARATOR_1 "========================="
# define TITLE " WALKTHROUGH "
# define SEPARATOR_2 "=========================\n\n"
# define FOOTER "=================================================\
=============="
# define ARGV1 "[1] amount of philosophers\n"
# define ARGV2 "[2] time a philosopher will die if he doesn't eat\n"
# define ARGV3 "[3] time it takes a philosopher to eat\n"
# define ARGV4 "[4] time it takes a philosopher to sleep\n"
# define ARGV5 "[5] number of times a philosopher must eat\n"

/******************************************************************************\
 * ABOUT THE PROJECT
\******************************************************************************/
/*
	The dining philosophers problem is a famous problem in computer science
	used to illustrate common issues in concurrent programming. The problem
	was originally formulated in 1965 by Edsger Dijkstra, and is stated as
	follows:

	X amount of philosophers sit at a round table with bowls of food.
	Forks are placed in front of each philosopher.
	There are as many forks as philosophers.
	All day the philosophers take turns eating, sleeping, and thinking.
	A philosopher must have two forks in order to eat, and each fork
	may only be used by one philosopher at a time. At any time a
	philosopher can pick up or set down a fork,
	but cannot start eating until picking up both forks.
	The philosophers alternatively eat, sleep, or think.
	While they are eating, they are not thinking nor sleeping,
	while thinking, they are not eating nor sleeping,
	and, of course, while sleeping, they are not eating nor thinking.
*/

#endif