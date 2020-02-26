/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:14:58 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/26 21:02:34 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <mlx.h>
#include "fractol.h"
#define THREADS 8

void	*threads(void *param)
{
	t_screen	*s;
	int			i;
	t_thread	thread[THREADS];
	pthread_t	t[THREADS];

	s = param;
	i = -1;
	while (++i < THREADS)
	{
		thread[i].s = s;
		thread[i].start = i * (s->image->height / THREADS);
		thread[i].finish = thread[i].start + s->image->height / THREADS;
		if (pthread_create(t + i, NULL, s->func, thread + i))
			sys_error();
	}
	i = -1;
	while (++i < THREADS)
		if (pthread_join(t[i], NULL))
			sys_error();
	mlx_put_image_to_window(s->mlx, s->win, s->image->img, 0, 0);
	return (NULL);
}
