/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.school-21.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:32:55 by sscarecr          #+#    #+#             */
/*   Updated: 2021/10/10 19:32:07 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>
#include "philosophers.h"

int	philosopher(void *param)
{
	t_philo	*p;

	p = (t_philo *)param;
	return (0);
}

int	go(int *args)
{
	pthread_t	*threads;
	t_philo		*philo;
	int			i;

	threads = (pthread_t *)malloc(sizeof(pthread_t) * args[0]);
	philo = (t_philo *)malloc(sizeof(t_philo) * args[0]);
	if (!threads || !philo)
		return (error(NULL));
	i = args[0];
	while (--i >= 0)
		philo[i] = (t_philo){.num = i + 1, .time_to_die = args[1], .time_to_eat
			= args[2], .time_to_sleep = args[3], .max_eat = args[4]};
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
		arguments[i - 1] = get_uint(av[i]);
		if (arguments[i - 1] < 0)
			return (error(av[i]));
	}
	return (go(arguments));
}
