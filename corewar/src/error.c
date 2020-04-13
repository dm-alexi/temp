/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 23:32:18 by sscarecr          #+#    #+#             */
/*   Updated: 2020/04/14 01:12:22 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** All error and usage messages.
*/

#include <stdio.h>
#include <unistd.h>
#include "libft.h"

void	sys_error(char *s)
{
	if (!s)
		write(STDERR_FILENO, "Error: ", 7);
	perror(s);
	exit(EXIT_FAILURE);
}

void	error(char *s)
{
	write(STDERR_FILENO, "Error: ", 7);
	write(STDERR_FILENO, s, ft_strlen(s));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}

void	error2(char *s, char *t)
{
	write(STDERR_FILENO, "Error: ", 7);
	write(STDERR_FILENO, s, ft_strlen(s));
	write(STDERR_FILENO, t, ft_strlen(t));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}

void	usage(void)
{
	ft_printf("Usage: ./corewar [[-d N | -dump N] -v N | -s] "
	"[-n N] <champion.cor> [-n N] <...>\n"
	"\t-d N\t: Dumps memory after N cycles (long format), then exits\n"
	"\t-dump N\t: Dumps memory after N cycles (short format), then exits\n"
	"\t-v N\t: Verbosity levels, can be added together to enable several\n"
	"\t\t  - 0 : Show only essentials\n"
	"\t\t  - 1 : Show lives\n"
	"\t\t  - 2 : Show cycles\n"
	"\t\t  - 4 : Show operations\n"
	"\t\t  - 8 : Show deaths\n"
	"\t\t  - 16 : Show PC movements (except for jumps)\n"
	"\t-s\t: Visualization mode\n");
	exit(EXIT_SUCCESS);
}
