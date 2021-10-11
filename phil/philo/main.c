/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.school-21.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:32:55 by sscarecr          #+#    #+#             */
/*   Updated: 2021/10/11 20:26:00 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include "philosophers.h"

void*	philosopher(void *param)
{
	t_philo	*p;
	long long	last_meal;

	p = (t_philo *)param;
	last_meal = now();
	printf("%d - %lld\n", p->num, last_meal);

	return (NULL);
}

int	go(int *args)
{
	pthread_t		*threads;
	t_philo			*philo;
	pthread_mutex_t	*mutex;
	int			i;

	threads = (pthread_t *)malloc(sizeof(pthread_t) * args[0]);
	philo = (t_philo *)malloc(sizeof(t_philo) * args[0]);
	mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * args[0]);
	if (!threads || !philo || !mutex)
		return (error(NULL));
	i = args[0];
	while (--i >= 0)
	{
		philo[i] = (t_philo){.num = i + 1, .time_to_die = args[1], .time_to_eat
			= args[2], .time_to_sleep = args[3], .max_eat = args[4]};

	}
	while (++i < args[0])
		if (pthread_create(threads + i, NULL, philosopher, philo + i))
			return (error(NULL));
	while (--i >= 0)
		if (pthread_join(threads[i], NULL))
			return (error(NULL));
	return (0);
}

int	main(int ac, char **av)
{
	static int	arguments[5] = {0};
	int			i;

	if (ac < 5 || ac > 6)
		return (usage());
	i = 0;
	while (++i < ac)
	{
		arguments[i - 1] = get_non_negative(av[i]);
		if (arguments[i - 1] < 0)
			return (error(av[i]));
	}
	return (go(arguments));
}
