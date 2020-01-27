/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:31:00 by sscarecr          #+#    #+#             */
/*   Updated: 2020/01/27 20:38:33 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "fdf.h"
#define ESC 53
#define UP 126
#define DOWN 125
#define LEFT 123
#define RIGHT 124
#define NUM_PLUS 69
#define PLUS 24
#define NUM_MINUS 78
#define MINUS 27
#define NUM_EIGHT 91
#define EIGHT 28
#define NUM_TWO 84
#define TWO 19
#define NUM_FOUR 86
#define FOUR 21
#define NUM_SIX 88
#define SIX 22
#define NUM_SEVEN 89
#define SEVEN 26
#define NUM_NINE 92
#define NINE 25
#define NUM_FIVE 87
#define FIVE 23
#define MOVE_SPEED 5
#define ROTATE_SPEED (M_PI / 180)
#define SCALE_FACTOR 1.04

int		win_close(void *param)
{
	(void)param;
	exit(EXIT_SUCCESS);
}

int		key_handle(int key, void *param)
{
	t_map	*map;
	
	map = param;
	if (key == ESC)
		win_close(param);
	else if (key == PLUS || key == NUM_PLUS)
		map->matrix.scale *= SCALE_FACTOR;
	else if (key == MINUS || key == NUM_MINUS)
		map->matrix.scale /= SCALE_FACTOR;
	else if (key == UP)
		map->matrix.move[1] -= MOVE_SPEED;
	else if (key == DOWN)
		map->matrix.move[1] += MOVE_SPEED;
	else if (key == LEFT)
		map->matrix.move[0] -= MOVE_SPEED;
	else if (key == RIGHT)
		map->matrix.move[0] += MOVE_SPEED;
	else if (key == EIGHT  || key == NUM_EIGHT)
		map->matrix.rotate[0] += ROTATE_SPEED;
	else if (key == TWO ||  key == NUM_TWO)
		map->matrix.rotate[0] -= ROTATE_SPEED;
	else if (key == SIX || key == NUM_SIX)
		map->matrix.rotate[1] += ROTATE_SPEED;
	else if (key == FOUR || key == NUM_FOUR)
		map->matrix.rotate[1] -= ROTATE_SPEED;
	else if (key == SEVEN || key == NUM_SEVEN)
		map->matrix.rotate[2] -= ROTATE_SPEED;
	else if (key == NINE || key == NUM_NINE)
		map->matrix.rotate[2] += ROTATE_SPEED;
	else  if (key == FIVE || key == NUM_FIVE)
		matrix_init(map);
	matrix_result(map);
	//ft_printf("%d ", key);
	return (0);
}
