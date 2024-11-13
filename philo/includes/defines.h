/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:18:59 by annabrag          #+#    #+#             */
/*   Updated: 2024/11/13 01:52:36 by art3mis          ###   ########.fr       */
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

# define ERR_ARG "Invalid amount of arguments. Please check below..."
# define ERR_MUST_EAT "Invalid number_of_times_each_philosopher_must_eat"
# define ERR_PHILO "Invalid amount of philosophers"
# define ERR_TTD "Invalid time_to_die"
# define ERR_TTE "Invalid time_to_eat"
# define ERR_TTS "Invalid time_to_sleep"

/******************************************************************************\
 * WALKTHROUGH MENU
\******************************************************************************/

# define SEPARATOR_1 "========================[ "
# define TITLE "WALKTHROUGH"
# define SEPARATOR_2 " ]========================\n\n"
# define FOOTER "=================================================\
=============="
# define ARGV1 "[1] amount of philosophers\n"
# define ARGV2 "[2] time a philosopher will die if he doesn't eat\n"
# define ARGV3 "[3] time it takes a philosopher to eat\n"
# define ARGV4 "[4] time it takes a philosopher to sleep\n"
# define ARGV5 "[5] number of times a philosopher must eat\n"

/******************************************************************************\
 * CUSTOM
\******************************************************************************/

# define DEATH "\n\n\
               ...\n\
             ;::::;\n\
           ;::::; :;\n\
         ;:::::'   :;\n\
        ;:::::;     ;.\n\
       ,:::::'       ;           OOO\\\n\
       ::::::;       ;          OOOOO\\\n\
       ;:::::;       ;         OOOOOOOO\n\
      ,;::::::;     ;'         / OOOOOOO\n\
    ;:::::::::`. ,,,;.        /  / DOOOOOO\n\
  .';:::::::::::::::::;,     /  /     DOOOO\n\
 ,::::::;::::::;;;;::::;,   /  /        DOOO\n\
;`::::::`'::::::;;;::::: ,#/  /          DOOO\n\
:`:::::::`;::::::;;::: ;::#  /            DOOO\n\
::`:::::::`;:::::::: ;::::# /              DOO\n\
`:`:::::::`;:::::: ;::::::#/               DOO\n\
 :::`:::::::`;; ;:::::::::##                OO\n\
 ::::`:::::::`;::::::::;:::#                OO\n\
 `:::::`::::::::::::;'`:;::#                O\n\
  `:::::`::::::::;' /  / `:#\n\
   ::::::`:::::;'  /  /   `#\n\n"

#endif