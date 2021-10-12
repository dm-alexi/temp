/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:32:55 by sscarecr          #+#    #+#             */
/*   Updated: 2021/10/12 23:42:34 by sscarecr         ###   ########.fr       */
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
	int		counter;

	p = (t_philo *)param;
	counter = 0;
	while (!p->max_eat || (p->max_eat > 0 && counter < p->max_eat))
	{
		pthread_mutex_lock(p->left);
		printf("%lld %d has taken a fork\n", now(), p->num);
		pthread_mutex_lock(p->right);
		p->last_meal = now();
		printf("%lld %d has taken a fork\n", p->last_meal, p->num);
		printf("%lld %d is eating\n", p->last_meal, p->num);
		usleep(1000 * p->time_to_eat);
		pthread_mutex_unlock(p->left);
		pthread_mutex_unlock(p->right);
		printf("%lld %d is sleeping\n", now(), p->num);
		++counter;
	}
	return (NULL);
}

int	go(int *args)
{
	pthread_t		*threads;
	t_philo			*philo;
	pthread_mutex_t	*mutex;
	int				i;

	threads = (pthread_t *)malloc(sizeof(pthread_t) * args[0]);
	philo = (t_philo *)malloc(sizeof(t_philo) * args[0]);
	mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * args[0]);
	if (!threads || !philo || !mutex)
		return (error(NULL));
	i = 0;
	while (i < args[0])
		if (pthread_mutex_init(mutex + i++, NULL))
			return (error(NULL));
	while (--i >= 0)
	{
		philo[i] = (t_philo){.num = i + 1, .time_to_die = args[1], .time_to_eat
			= args[2], .time_to_sleep = args[3], .max_eat = args[4],
			.right = mutex + (i + ((i + 1) % 2)) % args[0],
			.left = mutex + (i + (i % 2)) % args[0], .last_meal = now()};
		printf("%d: %d, %d\n", i + 1, (i + (i % 2)) % args[0] + 1, (i + ((i + 1) % 2)) % args[0] + 1);
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
