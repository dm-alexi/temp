/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:31:00 by sscarecr          #+#    #+#             */
/*   Updated: 2020/01/22 23:35:38 by sscarecr         ###   ########.fr       */
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
#define PLUS 69
#define MINUS 78
#define EIGHT 91
#define TWO 84
#define FOUR 86
#define SIX 88
#define SEVEN 89
#define NINE 92

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
	else if (key == PLUS)
		map->matrix.scale *= 1.04;
	else if (key == MINUS)
		map->matrix.scale /= 1.04;
	else if (key == UP)
		map->matrix.move[1] -= map->matrix.scale;
	else if (key == DOWN)
		map->matrix.move[1] += map->matrix.scale;
	else if (key == LEFT)
		map->matrix.move[0] -= map->matrix.scale;
	else if (key == RIGHT)
		map->matrix.move[0] += map->matrix.scale;
	else if (key == EIGHT)
		map->matrix.rotate[0] += M_PI / 36;
	else if (key == TWO)
		map->matrix.rotate[0] -= M_PI / 36;
	else if (key == SIX)
		map->matrix.rotate[1] += M_PI / 36;
	else if (key == FOUR)
		map->matrix.rotate[1] -= M_PI / 36;
	else if (key == SEVEN)
		map->matrix.rotate[2] += M_PI / 36;
	else if (key == NINE)
		map->matrix.rotate[2] -= M_PI / 36;
	matrix_result(map);
	ft_printf("%d ", key);
	return (0);
}
