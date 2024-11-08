/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:18:59 by annabrag          #+#    #+#             */
/*   Updated: 2024/11/08 18:50:45 by annabrag         ###   ########.fr       */
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

/******************************************************************************\
 * WALKTHROUGH MENU
\******************************************************************************/

# define SEPARATOR_1 "========================="
# define TITLE " WALKTHROUGH "
# define SEPARATOR_2 "=========================\n\n"
# define FOOTER "=================================================\
=============="
# define ARGV1 "argv[1]:\tnumber of philosophers\n"
# define ARGV2 "argv[2]:\ttime a philosopher will die if he doesn't eat\n"
# define ARGV3 "argv[3]:\ttime it takes a philosopher to eat\n"
# define ARGV4 "argv[4]:\ttime it takes a philosopher to sleep\n"
# define ARGV5 "argv[5]:\tnumber of times a philosopher must eat\n"

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