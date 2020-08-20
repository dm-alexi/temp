/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 20:47:51 by sscarecr          #+#    #+#             */
/*   Updated: 2020/08/21 00:12:22 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static char	*get_title(t_game *game)
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

static void	init_visual(t_game *game)
{
	game->cell = HEIGHT / (game->h < game->w ? game->w : game->h);
	if (game->cell < MIN_CELL)
		error("The map is too big to visualize.\n");
	game->height = game->h * (game->cell + 1) + 1;
	game->width = game->w * (game->cell + 1) + 1;
	game->title = get_title(game);
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		error2("SDL could not initialize. SDL error: ", SDL_GetError());
	if (!(game->window = SDL_CreateWindow(game->title, SDL_WINDOWPOS_UNDEFINED,
	SDL_WINDOWPOS_UNDEFINED, game->width + MENU_WIDTH, game->height,
	SDL_WINDOW_SHOWN)))
		error2("SDL could not create window. SDL error: ", SDL_GetError());
	if (!(game->renderer = SDL_CreateRenderer(game->window, -1,
	SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
		error2("SDL could not create renderer. SDL error: ", SDL_GetError());
	if (TTF_Init() < 0)
		error2("SDL_ttf could not initialize. SDL error: ", TTF_GetError());
	if (!(game->font = TTF_OpenFont(FONT, FONT_SIZE)))
		error(TTF_GetError());
}

static void	draw_arena(t_game *game)
{
	SDL_Rect	cell;
	int			i;
	int			j;
	int			color;

	cell.w = game->cell;
	cell.h = game->cell;
	i = -1;
	while (++i < game->h)
	{
		j = -1;
		cell.y = i * (cell.h + 1) + 1;
		while (++j < game->w)
		{
			cell.x = j * (cell.w + 1) + 1;
			color = GREY;
			if (game->current->table[i * game->w + j] != '.')
				color = (ft_toupper(game->current->table[i * game->w + j])
				== 'X' ? RED : BLUE);
			SDL_SetRenderDrawColor(game->renderer, color & 0xff,
				color >> 8 & 0xff, color >> 16 & 0xff, 255);
			SDL_RenderFillRect(game->renderer, &cell);
			SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, 255);
		}
	}
}

static void	visualize(t_game *game)
{
	SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
	SDL_RenderClear(game->renderer);
	draw_arena(game);
	draw_menu(game);
	SDL_RenderPresent(game->renderer);
}

void		visualization(t_game *game)
{
	init_visual(game);
	game->current = game->start;
	game->delay = INIT_DELAY;
	while (!game->vis_quit)
	{
		event_handler(game);
		visualize(game);
		while (game->vis_pause && !game->vis_quit)
		{
			event_handler(game);
			visualize(game);
		}
		if (game->vis_quit)
			break ;
		SDL_Delay(game->delay);
		if (game->current->next)
			game->current = game->current->next;
	}
	TTF_CloseFont(game->font);
	TTF_Quit();
	SDL_DestroyRenderer(game->renderer);
	SDL_DestroyWindow(game->window);
	SDL_Quit();
}
