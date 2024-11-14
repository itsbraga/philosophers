/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:39:06 by art3mis           #+#    #+#             */
/*   Updated: 2024/11/15 00:03:58 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	rainbow_txt_nonl(const char *str)
{
	const char	*colors[8] = {RED, PASTEL_ORANGE, YELLOW, GREEN, CYAN, BLUE, \
	PURPLE, PINK};
	size_t		nb_colors;
	size_t		i;
	size_t		len;

	nb_colors = sizeof(colors) / sizeof(colors[0]);
	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		printf("%s%c", colors[i % nb_colors], str[i]);
		i++;
	}
	printf(RESET);
}

static char	*__color_digit(char digit)
{
	if (digit == '1')
		return ("\e[38;2;152;168;105m1\e[0m");
	else if (digit == '2')
		return ("\e[38;2;255;234;150m2\e[0m");
	else if (digit == '3')
		return ("\e[38;2;255;178;127m3\e[0m");
	else if (digit == '4')
		return ("\e[38;2;255;182;193m4\e[0m");
	else if (digit == '5')
		return ("\e[38;2;211;211;255m5\e[0m");
	return (NULL);
}

char	*color_if_nbr(const char *str)
{
	char	*new_str;
	char	*colored_digit;

	new_str = malloc((ft_strlen(str) * 10) + 1);
	if (new_str == NULL)
		return (NULL);
	new_str[0] = '\0';
	while (*str != '\0')
	{
		colored_digit = __color_digit(*str);
		if (colored_digit != NULL)
			ft_strcat(new_str, colored_digit);
		else
			ft_strncat(new_str, (char *)str, 1);
		str++;
	}
	return (new_str);
}

void	walkthrough(void)
{
	printf(BOLD SEPARATOR_1);
	rainbow_txt_nonl(TITLE);
	printf("%s\n\t%s\n", SEPARATOR_2, \
	color_if_nbr("./philo argv[1] argv[2] argv[3] argv[4]"));
	printf("\n\t\t\t   %s\n\n\t%s\n", RESET "or", \
	color_if_nbr("./philo argv[1] argv[2] argv[3] argv[4] argv[5]"));
	printf("\n\n%s%s%s%s", color_if_nbr(ARGV1), color_if_nbr(ARGV2), \
	color_if_nbr(ARGV3), color_if_nbr(ARGV4));
	printf("%s%s\n%s\n", OPTIONAL, color_if_nbr(ARGV5), FOOTER);
}

int	get_help_menu(void)
{
	err_msg(ERR_ARG);
	write(2, "\n", 2);
	walkthrough();
	exit (FAILURE);
}
