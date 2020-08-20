/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 20:48:36 by sscarecr          #+#    #+#             */
/*   Updated: 2020/08/21 00:20:42 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void	draw_text(t_game *game, char *text, int y, SDL_Color color)
{
	SDL_Surface	*text_surface;
	SDL_Texture	*text_texture;
	SDL_Rect	coor;

	if (!text || !*text)
		return ;
	text_texture = NULL;
	coor.x = game->width + OFFSET;
	coor.y = y;
	TTF_SizeText(game->font, text, &coor.w, &coor.h);
	if (!(text_surface = TTF_RenderText_Solid(game->font, text, color)) ||
	!(text_texture = SDL_CreateTextureFromSurface(game->renderer,
	text_surface)))
		error(SDL_GetError());
	SDL_RenderCopy(game->renderer, text_texture, NULL, &coor);
	SDL_DestroyTexture(text_texture);
	SDL_FreeSurface(text_surface);
}

static void	draw_int(t_game *game, int n, int y, SDL_Color color)
{
	char	*number;

	if (!(number = ft_itoa(n)))
		sys_error();
	draw_text(game, number, y, color);
	free(number);
}

static void	draw_players(t_game *game, int pos)
{
	SDL_Color	color;

	if (game->p1)
	{
		color = (SDL_Color){.a = 255, .r = BLUE & 0xff,
			.g = BLUE >> 8 & 0xff, .b = BLUE >> 16 & 0xff};
		draw_text(game, game->p1, pos, color);
		if (game->current == game->finish)
			draw_int(game, game->score1, pos + 20, color);
		pos += 40;
	}
	if (game->p2)
	{
		color = (SDL_Color){.a = 255, .r = RED & 0xff,
			.g = RED >> 8 & 0xff, .b = RED >> 16 & 0xff};
		draw_text(game, game->p2, pos, color);
		if (game->current == game->finish)
			draw_int(game, game->score2, pos + 20, color);
	}
}

static void	draw_result(t_game *game, int y)
{
	SDL_Color	color;
	int			col;
	char		*full_line;
	char		*p;

	if (game->score1 == game->score2)
	{
		color = (SDL_Color){255, 255, 255, 255};
		draw_text(game, "DRAW", y, color);
	}
	else
	{
		p = game->score1 > game->score2 ? game->p1 : game->p2;
		col = game->score1 > game->score2 ? BLUE : RED;
		if (!(full_line = ft_strjoin(p, " won!")))
			sys_error();
		color = (SDL_Color){.a = 255, .r = col & 0xff, .g = col >> 8 & 0xff,
			.b = col >> 16 & 0xff};
		draw_text(game, full_line, y, color);
		free(full_line);
	}
}

void		draw_menu(t_game *game)
{
	static const SDL_Color	white = (SDL_Color){255, 255, 255, 255};

	if (game->current != game->finish)
		draw_text(game, game->vis_pause ? "***Pause***" : "***Running***",
			20, white);
	else
		draw_result(game, 20);
	draw_players(game, 80);
	draw_text(game, "Speed, %:", 200, white);
	draw_int(game, (INIT_DELAY) * 100 / game->delay, 220, white);
	draw_text(game, "SPACE :        pause", 260, white);
	draw_text(game, "UP / DOWN :    speed up / down", 280, white);
	draw_text(game, "LEFT / RIGHT : 5 turns back / forward", 300, white);
	draw_text(game, "HOME :         go to start", 320, white);
	draw_text(game, "END :          go to finish", 340, white);
	draw_text(game, "ESC :          exit", 360, white);
}
