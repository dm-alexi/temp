/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:32:55 by sscarecr          #+#    #+#             */
/*   Updated: 2021/10/15 00:16:20 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <semaphore.h>
#include <wait.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include "philosophers.h"

void	print(t_game *game, char *str)
{
	sem_wait(game->output);
	printf("%lld %d %s\n", now() / 1000, game->id, str);
	sem_post(game->output);
}

// void	*philos(void *param)
// {
// 	t_philo	*p;
// 	t_game	*game;

// 	p = (t_philo *)param;
// 	game = (t_game *)p->game;
// 	while (game->number > 1 && !game->stop)
// 	{
// 		print(game, p->num, "is thinking");
// 		pthread_mutex_lock(p->left);
// 		print(game, p->num, "has taken a fork");
// 		p->last_meal = now();
// 		print(game, p->num, "has taken a fork");
// 		print(game, p->num, "is eating");
// 		usleep(game->tte);
// 		pthread_mutex_unlock(p->left);
// 		pthread_mutex_unlock(p->right);
// 		print(game, p->num, "is sleeping");
// 		pthread_mutex_lock(&game->output);
// 		if (game->max_meals && (++(p->meals) == game->max_meals))
// 			++(game->finished);
// 		pthread_mutex_unlock(&game->output);
// 		usleep(game->tts - 1000);
// 		usleep(1000);
// 	}
// 	return (NULL);
// }

void *cycle(void *param)
{
	t_game	*game;

	game = (t_game*)param;
	while (1)
	{
		print(game, "is thinking");
		sem_wait(game->access);
		sem_wait(game->forks);
		print(game, "has taken a fork");
		sem_wait(game->forks);
		print(game, "has taken a fork");
		sem_post(game->access);
		print(game, "is eating");
		usleep(game->tte);
		print(game, "is sleeping");
		if (!--game->max_meals)
			sem_post(game->fed);
		sem_post(game->forks);
		sem_post(game->forks);
		usleep(game->tts - 1000);
		usleep(1000);
	}
}

// void	loop(t_game *game)
// {
// 	int	i;

// 	if (game->number == 1)
// 	{
// 		print(game, 1, "is thinking");
// 		print(game, 1, "has taken a fork");
// 	}
// 	while (!game->stop)
// 	{
// 		i = -1;
// 		pthread_mutex_lock(&game->output);
// 		while (++i < game->number)
// 			if (now() - (game->philos + i)->last_meal >= game->ttd)
// 			{
// 				printf("%lld %d died\n", now() / 1000, i + 1);
// 				game->stop = TRUE;
// 				break ;
// 			}
// 		if (game->max_meals > 0 && game->finished == game->number)
// 			game->stop = TRUE;
// 		pthread_mutex_unlock(&game->output);
// 		usleep(STEP);
// 	}
// }

void	init(int ac, char **av, t_game *game)
{
	static long long	arg[5] = {0};

	if (ac < 5 || ac > 6)
		usage();
	while (--ac > 0)
		arg[ac - 1] = get_nonnegative(av[ac]);
	if (arg[0] < 1 || arg[1] < 1 || arg[2] < 1 || arg[3] < 1 || arg[4] < 0)
		usage();
	*game = (t_game){.finished = 0, .number = arg[0], .ttd = arg[1] * 1000LL,
		.tte = arg[2] * 1000LL, .tts = arg[3] * 1000LL, .max_meals = arg[4],
		.last_meal = now(), .forks = sem_open(SEM, O_CREAT | O_EXCL, 0644, arg[0]),
		.output = sem_open(OUT, O_CREAT | O_EXCL, 0644, 1),
		.access = sem_open(ACC, O_CREAT | O_EXCL, 0644, 1),
		.death = sem_open(DEA, O_CREAT | O_EXCL, 0644, 0),
		.fed = sem_open(FED, O_CREAT | O_EXCL, 0644, 0)};
	sem_unlink(SEM);
	sem_unlink(OUT);
	sem_unlink(ACC);
	sem_unlink(DEA);
	sem_unlink(FED);
	if (game->forks == SEM_FAILED || game->output == SEM_FAILED ||
		game->access == SEM_FAILED || game->death == SEM_FAILED ||
		game->fed == SEM_FAILED)
		error();
}

void go(t_game *game)
{
	pthread_t	thread;

	pthread_create(&thread, NULL, cycle, game);
	while (TRUE)
	{
		sem_wait(game->output);
		if (now() - game->last_meal >= game->ttd)
			{
				printf("%lld %d died\n", now() / 1000, game->id);
				sem_post(game->death);
				exit(0);
			}
		sem_post(game->output);
		usleep(STEP);
	}
}

int	main(int ac, char **av)
{
	int		i;
	t_game	game;
	pid_t	*philos;
	pid_t	pid;			

	init(ac, av, &game);
	if (!(philos = (pid_t*)malloc(sizeof(pid_t) * game.number)))
		error();
	i = -1;
	while (++i < game.number)
		if (!(pid = fork()))
		{
			game.id = i + 1;
			go(&game);
			return (0);
		}
		else
			philos[i] = pid;
	sem_wait(game.death);
	while (--i >= 0)
		kill(philos[i], SIGTERM);
	// while (--i >= 0)
	// 	waitpid(philos[i], &pid, 0);
	free(philos);
	clear(&game);
	return (0);
}
