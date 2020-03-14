/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 20:27:21 by sscarecr          #+#    #+#             */
/*   Updated: 2020/03/14 16:37:04 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "visual.h"

void	image_put_pixel(t_image *image, int x, int y, int color)
{
	int		i;

	i = x * image->bpp / 8 + y * image->sizeline;
	if (x < 0 || y < 0 || x >= image->width || y >= image->height)
		return ;
	if (image->endian)
	{
		if (image->bpp > 24)
			image->map[i++] = 0;
		image->map[i++] = color >> 16;
		image->map[i++] = color >> 8;
		image->map[i] = color;
	}
	else
	{
		image->map[i++] = color;
		image->map[i++] = color >> 8;
		image->map[i++] = color >> 16;
		if (image->bpp > 24)
			image->map[i] = 0;
	}
}

void	draw_cell(t_game *game, int x, int y, int color)
{
	int	i;
	int j;

	i = -1;
	while (++i < game->cell)
	{
		j = -1;
		while (++j < game->cell)
			image_put_pixel(game->screen->image, x + j, y + i, !i || !j ||
			i == game->cell - 1 || j == game->cell - 1 ? GREY : color);
	}
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;
	int	color;

	i = -1;
	while (++i < game->h)
	{
		j = -1;
		while (++j < game->w)
		{
			color = BLACK;
			if (game->current->table[i * game->w + j] != '.')
				color = (ft_toupper(game->current->table[i * game->w + j]) == 'X'
				? RED : BLUE);
			draw_cell(game, j * game->cell, i * game->cell, color);
		}
	}
	image_put_pixel(game->screen->image, 0, game->screen->image->height - 2, WHITE);
	mlx_put_image_to_window(game->screen->mlx, game->screen->win,
	game->screen->image->img, 0, 0);
}

void	draw_menu(t_game *game)
{
	mlx_string_put(game->screen->mlx, game->screen->win,
	game->screen->image->width + 10, 10, BLUE, game->p1);
	mlx_string_put(game->screen->mlx, game->screen->win,
	game->screen->image->width + 10, 40, WHITE, "vs.");
	mlx_string_put(game->screen->mlx, game->screen->win,
	game->screen->image->width + 10, 70, RED, game->p2);
}