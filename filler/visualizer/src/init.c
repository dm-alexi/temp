/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:28:09 by sscarecr          #+#    #+#             */
/*   Updated: 2020/08/09 09:39:40 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "libft.h"
#include "visual.h"

static t_image	*new_image(void *mlx, int width, int height)
{
	t_image	*image;

	if (!(image = (t_image*)ft_memalloc(sizeof(t_image))) ||
	!(image->img = mlx_new_image(mlx, width, height)))
		sys_error();
	image->map = mlx_get_data_addr(image->img, &(image->bpp),
		&(image->sizeline), &(image->endian));
	image->height = height;
	image->width = width;
	return (image);
}

static void		*get_screen(int height, int width, char *title)
{
	t_screen	*s;

	if (!(s = (t_screen*)malloc(sizeof(t_screen))) ||
	!(s->mlx = mlx_init()) ||
	!(s->win = mlx_new_window(s->mlx, width + MENU_WIDTH + 2 * BORDER,
	height + 2 * BORDER, title)) ||
	!(s->image = new_image(s->mlx, width, height)))
		sys_error();
	s->play = 0;
	return (s);
}

static char		*get_title(t_game *game)
{
	char	*title;

	if (game->p2)
	{
		if (!(title = (char*)malloc(ft_strlen(game->p1) +
		ft_strlen(game->p2) + 6)))
			sys_error();
		ft_strcpy(title, game->p1);
		ft_strcat(title, " vs. ");
		ft_strcat(title, game->p2);
	}
	else if (!(title = ft_strjoin(game->p1, ", single player")))
		sys_error();
	return (title);
}

void			init_visual(t_game *game)
{
	int		width;
	int		height;

	game->cell = HEIGHT / game->h > TABLE_WIDTH / game->w ?
		TABLE_WIDTH / game->w : HEIGHT / game->h;
	if (game->cell < MIN_CELL)
		error("The map is too big to visualize.\n");
	height = game->h * game->cell;
	width = game->w * game->cell;
	game->title = get_title(game);
	game->screen = get_screen(height, width, game->title);
	mlx_hook(game->screen->win, 17, 1L << 17, &win_close, game);
	mlx_hook(game->screen->win, 2, 1L << 0, &key_handle, game);
	draw(game);
	mlx_loop(game->screen->mlx);
}
