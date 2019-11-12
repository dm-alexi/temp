/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:54:19 by sscarecr          #+#    #+#             */
/*   Updated: 2019/11/12 21:54:22 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	a_error(const char *s)
{
	write(2, s, ft_strlen(s));
	exit(1);
}

void	file_error(const char *s)
{
	write(2, "Invalid file name: ", 19);
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
	exit(1);
}

void	flag_error(char c)
{
	static char	s[] = "Incorrect flag: - \n";

	s[17] = c;
	write(2, s, 18);
	exit(1);
}

void	mem_error(void)
{
	write(2, "Error: memory allocation failed.\n", 33);
	exit(1);
}
