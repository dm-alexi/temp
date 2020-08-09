/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 20:27:21 by sscarecr          #+#    #+#             */
/*   Updated: 2020/08/09 09:35:37 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "libft.h"
#include "visual.h"

static void	image_put_pixel(t_image *image, int x, int y, int color)
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

static void	draw_cell(t_game *game, int x, int y, int color)
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

static void	draw_scores(t_game *game)
{
	static char	score1[10];
	static char score2[10];
	char		*t;

	if (!score1[0])
	{
		t = ft_itoa(game->score1);
		ft_strcat(score1, t);
		free(t);
		t = ft_itoa(game->score2);
		ft_strcat(score2, t);
		free(t);
	}
	mlx_string_put(game->screen->mlx, game->screen->win,
	WIDTH - BORDER - 10 * ft_strlen(score1), BORDER, BLUE, score1);
	if (game->p2)
		mlx_string_put(game->screen->mlx, game->screen->win,
		WIDTH - BORDER - 10 * ft_strlen(score2), 7 * BORDER, RED, score2);
}

static void	draw_menu(t_game *game)
{
	mlx_string_put(game->screen->mlx, game->screen->win,
	game->screen->image->width + 2 * BORDER, BORDER, BLUE, game->p1);
	if (game->p2)
	{
		mlx_string_put(game->screen->mlx, game->screen->win,
		game->screen->image->width + 2 * BORDER, 4 * BORDER, WHITE, "vs.");
		mlx_string_put(game->screen->mlx, game->screen->win,
		game->screen->image->width + 2 * BORDER, 7 * BORDER, RED, game->p2);
	}
	mlx_string_put(game->screen->mlx, game->screen->win,
	game->screen->image->width + 2 * BORDER, 40 * BORDER, WHITE,
	"LEFT / RIGHT - move 1 step");
	mlx_string_put(game->screen->mlx, game->screen->win,
	game->screen->image->width + 2 * BORDER, 43 * BORDER, WHITE,
	"PAGE UP / PAGE DOWN - move 10 steps");
	mlx_string_put(game->screen->mlx, game->screen->win,
	game->screen->image->width + 2 * BORDER, 46 * BORDER, WHITE,
	"UP / DOWN, HOME / END - start / finish");
	if (game->current == game->finish)
		draw_scores(game);
}

void		draw(t_game *game)
{
	int	i;
	int	j;
	int	color;

	mlx_clear_window(game->screen->mlx, game->screen->win);
	i = -1;
	while (++i < game->h)
	{
		j = -1;
		while (++j < game->w)
		{
			color = BLACK;
			if (game->current->table[i * game->w + j] != '.')
				color = (ft_toupper(game->current->table[i * game->w + j])
				== 'X' ? RED : BLUE);
			draw_cell(game, j * game->cell, i * game->cell, color);
		}
	}
	mlx_put_image_to_window(game->screen->mlx, game->screen->win,
	game->screen->image->img, BORDER, BORDER);
	draw_menu(game);
}
