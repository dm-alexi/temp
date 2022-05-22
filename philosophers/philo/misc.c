/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:06:25 by sscarecr          #+#    #+#             */
/*   Updated: 2021/10/14 23:58:55 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>
#include "philosophers.h"

int	get_nonnegative(char *s)
{
	int	n;

	n = 0;
	while (*s && (*s == ' ' || *s == '\n' || *s == '\t' || *s == '\r'
			|| *s == '\v' || *s == '\f'))
		++s;
	if (*s == '+')
		++s;
	if (!*s)
		return (-1);
	while (*s)
		if (*s >= '0' && *s <= '9')
			n = n * 10 + (*s++ - '0');
	else
		return (-1);
	return (n);
}

int	usage(void)
{
	printf("usage: ./philo number_of_philosophers time_to_die time_to_eat "
		"time_to_sleep [number_of_times_each_philosopher_must_eat]\n"
		"Note: all parameters must be positive integers.\n");
	return (0);
}

int	error(void)
{
	printf("Error: system error\n");
	return (1);
}

long long	now(void)
{
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	return (tp.tv_sec * 1000000 + tp.tv_usec);
}

int	clear(t_game *game)
{
	free(game->philos);
	free(game->forks);
	free(game->threads);
	return (1);
}
