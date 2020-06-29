/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 17:04:28 by asmall            #+#    #+#             */
/*   Updated: 2020/06/29 13:17:25 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int		choose_reverse_color(t_battlefield *cell)
{
	static const int	colors[] = {0x00009b, 0x009b9b, 0x008000, 0x9b0000,
		0x800080, 0x9b9b00, 0xa9a9a9, 0x323232, 0x6f6f6f};
	int					i;

	i = -1;
	while (++i < 8)
		if (colors[i] == cell->color)
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

void	push_distribution(t_battlefield *arena, int y)
{
	int			colors[9];
	int			i;
	float		k;
	SDL_Rect	coor;

	k = BAR_WIDTH / (float)MEM_SIZE;
	i = -1;
	while (++i < 9)
		colors[i] = 0;
	i = -1;
	while (++i < MEM_SIZE)
		colors[choose_reverse_color(&arena[i])]++;
	i = -1;
	coor.y = y;
	coor.x = SCREEN_WIDTH - INFORMATION_SIZE + 25;
	while (++i < 9)
	{
		coor.h = 15;
		coor.w = colors[i] * k;
		SDL_SetRenderDrawColor(g_main_render, g_colors[i] & 0xff,
			g_colors[i] >> 8 & 0xff, g_colors[i] >> 16 & 0xff, 255);
		SDL_RenderFillRect(g_main_render, &coor);
		coor.x += coor.w;
	}
}

void	push_live_breakdown(t_vm *vm, int y)
{
	int			sum;
	SDL_Rect	coor;

	coor.y = y;
	coor.x = SCREEN_WIDTH - INFORMATION_SIZE + 25;
	coor.h = 15;
	sum = 0;
	if (vm->live_calls > 0)
		live_players(vm, coor, sum);
	else
	{
		SDL_SetRenderDrawColor(g_main_render, 255, 255, 255, 255);
		coor.w = INFORMATION_SIZE - OFFSET;
		SDL_RenderDrawRect(g_main_render, &coor);
	}
}