/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:32:55 by sscarecr          #+#    #+#             */
/*   Updated: 2021/10/16 00:41:43 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include "philosophers.h"

void	print(t_game *game, int num, char *str)
{
	pthread_mutex_lock(&game->output);
	if (!game->stop)
		printf("%lld %d %s\n", now(), num, str);
	pthread_mutex_unlock(&game->output);
}

void	*philos(void *param)
{
	t_philo	*p;
	t_game	*game;

	p = (t_philo *)param;
	game = (t_game *)p->game;
	while (!game->stop)
	{
		print(game, p->num, "is thinking");
		// while (game->last_one == p->num)
		// 	usleep(STEP);
		pthread_mutex_lock(p->left);
		print(game, p->num, "has taken a fork");
		pthread_mutex_lock(p->right);
		p->last_meal = now();
		print(game, p->num, "has taken a fork");
		print(game, p->num, "is eating");
		usleep(1000 * game->tte);
		print(game, p->num, "is sleeping");
		pthread_mutex_unlock(p->left);
		pthread_mutex_unlock(p->right);
		pthread_mutex_lock(&game->output);
		if (game->max_meals && (++(p->meals) == game->max_meals))
			++(game->finished);
		// game->last_one = p->num;
		pthread_mutex_unlock(&game->output);
		usleep(1000 * game->tts);
	}
	return (NULL);
}

void	loop(t_game *game)
{
	int	i;

	while (!game->stop)
	{
		i = -1;
		pthread_mutex_lock(&game->output);
		while (++i < game->number)
		{
			if (now() - (game->philos + i)->last_meal > game->ttd)
			{
				printf("%lld %d died\n", now(), i + 1);
				printf("%lld his last meal\n", (game->philos + i)->last_meal);
				game->stop = TRUE;
				break ;
			}
			//else printf("-- %lld %lld\n", now() - (game->philos + i)->last_meal, game->ttd);
		}
		if (game->max_meals > 0 && game->finished == game->number)
			game->stop = TRUE;
		pthread_mutex_unlock(&game->output);
		usleep(STEP);
	}
}

int	init(t_game *game)
{
	int	i;

	game->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* game->number);
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
		game->philos[i] = (t_philo){.num = i + 1, .last_meal = now(),
			// .left = game->forks + i,
			// .right = game->forks + (i + 1) % game->number,
			.right = game->forks + (i + ((i + 1) % 2)) % game->number,
			.left = game->forks + (i + (i % 2)) % game->number,
			.meals = 0, .game = game};
	// game->philos[game->number - 1].left = game->forks;
	// game->philos[game->number - 1].right = game->forks + game->number - 1;
	while (++i < game->number)
		if (pthread_create(game->threads + i, NULL, philos, game->philos + i))
			return (1);
	loop(game);
	// while (--i >= 0)
	// 	pthread_join(game->threads[i], NULL);
	while (--i >= 0)
		pthread_detach(game->threads[i]);
	return (0);
}

int	main(int ac, char **av)
{
	static long long	arg[5] = {0};
	int					i;
	t_game				game;

	if (ac < 5 || ac > 6)
		return (usage());
	i = 0;
	while (++i < ac)
		arg[i - 1] = get_nonnegative(av[i]);
	if (arg[0] < 1 || arg[1] < 0 || arg[2] < 0 || arg[3] < 0 || arg[4] < 0)
		return (usage());
	game = (t_game){.finished = 0, .number = arg[0], .ttd = arg[1],
		.tte = arg[2], .tts = arg[3], .max_meals = arg[4], .last_one = 0,
		.forks = NULL, .philos = NULL, .threads = NULL, .stop = 0};
	// printf("TTD = %lld\nTTE = %lld\nTTS = %lld\n num = %d\n", game.ttd, game.tte, game.tts, game.number);
	if (init(&game) && clear(&game))
		return (error());
	clear(&game);
	return (0);
}
