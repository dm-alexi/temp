/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 17:04:28 by asmall            #+#    #+#             */
/*   Updated: 2020/06/29 18:06:09 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static int	get_color(t_battlefield *cell)
{
	int					i;

	i = -1;
	while (++i <= MAX_PLAYERS)
		if (g_colors[i] == cell->color)
			break ;
	return (i);
}

void		draw_text(char *text, int y, SDL_Color color)
{
	SDL_Surface	*text_surface;
	SDL_Texture	*text_texture;
	SDL_Rect	coor;

	text_texture = NULL;
	coor.x = SCREEN_WIDTH - INFORMATION_SIZE + OFFSET;
	coor.y = y;
	TTF_SizeText(g_font, text, &coor.w, &coor.h);
	if (!(text_surface = TTF_RenderText_Solid(g_font, text, color)) ||
	!(text_texture = SDL_CreateTextureFromSurface(g_main_render, text_surface)))
		error(SDL_GetError());
	SDL_RenderCopy(g_main_render, text_texture, NULL, &coor);
	SDL_DestroyTexture(text_texture);
	SDL_FreeSurface(text_surface);
}

void		draw_distribution(t_battlefield *arena, int y)
{
	int			colors[MAX_PLAYERS + 1];
	int			i;
	SDL_Rect	coor;

	ft_bzero(colors, sizeof(int) * (MAX_PLAYERS + 1));
	i = -1;
	while (++i < MEM_SIZE)
		colors[get_color(arena + i)]++;
	coor.x = SCREEN_WIDTH - INFORMATION_SIZE + OFFSET;
	coor.y = y;
	coor.h = BAR_HEIGHT;
	i = -1;
	while (++i < MAX_PLAYERS)
	{
		coor.w = colors[i] * (double)BAR_WIDTH / MEM_SIZE + 0.5;
		SDL_SetRenderDrawColor(g_main_render, g_colors[i] & 0xff,
			g_colors[i] >> 8 & 0xff, g_colors[i] >> 16 & 0xff, 255);
		SDL_RenderFillRect(g_main_render, &coor);
		coor.x += coor.w;
	}
	coor.w = SCREEN_WIDTH - INFORMATION_SIZE + OFFSET + BAR_WIDTH - coor.x;
	SDL_SetRenderDrawColor(g_main_render, g_colors[i] & 0xff,
		g_colors[i] >> 8 & 0xff, g_colors[i] >> 16 & 0xff, 255);
	SDL_RenderFillRect(g_main_render, &coor);
}

void		draw_live_bar(t_vm *vm, int y)
{
	int			i;
	double		sum;
	SDL_Rect	coor;

	coor.y = y;
	coor.x = SCREEN_WIDTH - INFORMATION_SIZE + OFFSET;
	coor.h = BAR_HEIGHT;
	sum = 0.0;
	i = vm->num_players;
	while (--i >= 0)
		sum += vm->players[i].lives_in_current_period;
	if (sum == 0.0)
		return ;
	while (++i < vm->num_players - 1)
	{
		coor.w = vm->players[i].lives_in_current_period * BAR_WIDTH / sum + 0.5;
		SDL_SetRenderDrawColor(g_main_render, g_colors[i] & 0xff,
			g_colors[i] >> 8 & 0xff, g_colors[i] >> 16 & 0xff, 255);
		SDL_RenderFillRect(g_main_render, &coor);
		coor.x += coor.w;
	}
	coor.w = SCREEN_WIDTH - INFORMATION_SIZE + OFFSET + BAR_WIDTH - coor.x;
	SDL_SetRenderDrawColor(g_main_render, g_colors[i] & 0xff,
		g_colors[i] >> 8 & 0xff, g_colors[i] >> 16 & 0xff, 255);
	SDL_RenderFillRect(g_main_render, &coor);
}
