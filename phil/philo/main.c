/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.school-21.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:32:55 by sscarecr          #+#    #+#             */
/*   Updated: 2021/10/13 20:58:07 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include "philosophers.h"

int		waits(t_rules *game, int num, long long timer, int check)
{
	while (timer > 0)
	{
		timer -= STEP;
		usleep(STEP);
		if (check && now() - (game->philos + num - 1)->last_meal >= game->ttd)
			game->finish = TRUE;
		if (game->finish)
			return (1);
	}
	return (0);
}

void*	philosopher(void *param)
{
	t_philo	*p;
	int		counter;
	t_rules	*game;

	p = (t_philo *)param;
	game = p->rules;
	counter = 0;
	while (0)
	{
		pthread_mutex_lock(p->left);
		printf("%lld %d has taken a fork\n", now(), p->num);
		pthread_mutex_lock(p->right);
		p->last_meal = now();
		printf("%lld %d has taken a fork\n", p->last_meal, p->num);
		printf("%lld %d is eating\n", p->last_meal, p->num);
		waits(game, p->num, game->tte, FALSE);
		pthread_mutex_unlock(p->left);
		pthread_mutex_unlock(p->right);
		pthread_mutex_lock(&game->output);
		printf("%lld %d is sleeping\n", now(), p->num);
		if (game->meals > 0 && ++counter == game->meals)
			if (++game->filled == game->number)
				game->finish = TRUE;
		pthread_mutex_unlock(&game->output);
		waits(game, p->num, game->tts, TRUE);
		pthread_mutex_lock(&game->output);
		printf("%lld %d is thinking\n", now(), p->num);
		pthread_mutex_unlock(&game->output);
	}
	return (NULL);
}

int	init(t_rules *game)
{
	int			i;
	
	game->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) *
		(game->number));
	game->threads = (pthread_t *)malloc(sizeof(pthread_t) * game->number);
	game->philos = (t_philo *)malloc(sizeof(t_philo) * game->number);
	if (!(game->forks) || !(game->threads) || !(game->philos)
		|| pthread_mutex_init(&game->output, NULL))
		return (1);
	i = 0;
	while (i < game->number)
		if (pthread_mutex_init(game->forks + i ++, NULL))
			return (1);
	while (--i >= 0)
	{
		game->philos[i] = (t_philo){.num = i + 1, .last_meal = now(),
			.right = game->forks + (i + ((i + 1) % 2)) % game->number,
			.left = game->forks + (i + (i % 2)) % game->number,
			.rules = game};
		printf("%d: %d, %d\n", i + 1, (i + (i % 2)) % game->number + 1, (i + ((i + 1) % 2)) % game->number + 1);
	}
	while (++i < game->number)
		if (pthread_create(game->threads + i, NULL, philosopher, game->philos + i))
			return (1);
	while (--i >= 0)
		if (pthread_join(game->threads[i], NULL))
			return (1);
	return (0);
}

int clear(t_rules *game)
{
	free(game->philos);
	free(game->forks);
	return (1);
}

int	main(int ac, char **av)
{
	static int	args[5] = {0};
	int			i;
	t_rules		game;

	if (ac < 5 || ac > 6)
		return (usage());
	i = 0;
	while (++i < ac)
	{
		args[i - 1] = get_microseconds(av[i]);
		if (args[i - 1] < 0)
			return (error(av[i]));
	}
	game = (t_rules){.number = args[0], .ttd = args[1], .tte = args[2],
		.tts = args[3], .finish = FALSE, .forks = NULL,
		.philos = NULL, .threads = NULL};
	game.meals = -1;
	if (ac == 6)
		game.meals = args[4];
	if (init(&game) && clear(&game))
		return (error(NULL));
	clear(&game);
	return (0);
}
