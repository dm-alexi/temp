/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:28:09 by sscarecr          #+#    #+#             */
/*   Updated: 2020/03/13 23:19:43 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "visual.h"

static int		win_close(void *param)
{
	t_screen	*s;

	s = param;
	mlx_destroy_window(s->mlx, s->win);
	mlx_destroy_image(s->mlx, s->image->img);
	mlx_destroy_image(s->mlx, s->menu->img);
	free(s->image);
	free(s->menu);
	free(s->title);
	free(s);
	exit(EXIT_SUCCESS);
	return (0);
}

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
	!(s->win = mlx_new_window(s->mlx, width, height, title)) ||
	!(s->image = new_image(s->mlx, width, height)) ||
	!(s->menu = new_image(s->mlx, MENU_WIDTH, MENU_HEIGHT)))
		sys_error();
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

	if (game->h * CELL > MAX_HEIGHT || game->w * CELL > MAX_WIDTH)
		error("The map is too big to visualize.\n");
	height = game->h * CELL > MIN_HEIGHT ? game->h * CELL : MIN_HEIGHT;
	width = game->w * CELL > MIN_WIDTH ? game->w * CELL : MIN_WIDTH;
	game->screen = get_screen(height, width + MENU_WIDTH, get_title(game));
	mlx_hook(game->screen->win, 17, 1L << 17, &win_close, game->screen);
	//mlx_hook(game->screen->win, 2, 1L << 0, &key_handle, game->screen);
	//mlx_hook(game->screen->win, 4, 1L << 2, &mouse_handle, game->screen);
	mlx_loop(game->screen->mlx);
}
