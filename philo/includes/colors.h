/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:10:24 by annabrag          #+#    #+#             */
/*   Updated: 2024/11/12 20:15:54 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# define RESET 			"\e[0m"

# define BOLD			"\e[1m"
# define ITAL			"\e[3m"
# define UNDERLINE		"\e[4m"
# define BLINK          "\e[5m"

# define GRAY			"\e[90m"
# define RED			"\e[31m"
# define GREEN			"\e[32m"
# define YELLOW			"\e[38;2;255;234;150m"
# define ORANGE			"\e[38;5;208m"
# define BLUE			"\e[34m"
# define PURPLE			"\e[35m"
# define PINK			"\e[38;2;255;182;193m"
# define CYAN			"\e[36m"
# define WHITE			"\e[37m"

# define LIGHT_GRAY		"\e[38;2;173;165;165m"
# define LIGHT_GRAY2	"\e[38;2;211;211;211m"

// Pastel colors
# define PASTEL_GREEN	"\e[38;2;173;235;179m"
# define PASTEL_DGREEN	"\e[38;2;152;168;105m"
# define PASTEL_BLUE	"\e[38;2;179;235;242m"
# define PASTEL_PURPLE	"\e[38;2;211;211;255m"
# define PASTEL_ORANGE	"\e[38;2;255;178;127m"

#endif