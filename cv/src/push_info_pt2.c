/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_info_pt2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 15:49:05 by asmall            #+#    #+#             */
/*   Updated: 2020/06/26 17:21:17 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void		push_players(t_vm *vm, int start_y)
{
	unsigned	i;
	int			pos;
	SDL_Color	color;

	i = -1;
	pos = start_y;
	while (++i < vm->num_players)
	{
		push_int_text(i + 1, "Player # ", pos);
		set_sdl_color(&color, i);
		push_char_text(vm->players[i].header.prog_name, pos + 20, color);
		push_int_text(vm->players[i].last_alive,
			"Last alive: ", pos + 40);
		push_int_text(vm->players[i].lives_in_current_period,
			"Lives in current period : ", pos + 60);
		push_int_text(vm->players[i].num_cursors,
			"Number of coaches: ", pos + 80);
		pos += 110;
	}
}

SDL_Color	winner_info(t_vm *vm, SDL_Texture *text_texture,
				SDL_Surface *text_surface, SDL_Rect pos)
{
	SDL_Color	winner;

	winner.a = 255;
	set_sdl_color(&winner, vm->last_alive - 1);
	text_surface = TTF_RenderText_Solid(g_font, "Winner is: ", WHITE);
	text_texture = SDL_CreateTextureFromSurface(g_main_render, text_surface);
	SDL_FreeSurface(text_surface);
	TTF_SizeText(g_font, "Winner is: ", &pos.w, &pos.h);
	SDL_RenderCopy(g_main_render, text_texture, NULL, &pos);
	SDL_DestroyTexture(text_texture);
	return (winner);
}

void		push_winner_vis(t_vm *vm)
{
	SDL_Color	winner;
	SDL_Rect	pos;
	SDL_Texture	*text_texture;
	SDL_Surface	*text_surface;

	vm->vis_pause = 0;
	vm->vis_quit = 0;
	draw_arena(vm);
	push_info(vm);
	pos.x = SCREEN_WIDTH - INFORMATION_SIZE + OFFSET;
	pos.y = SCREEN_HEIGHT - 120;
	text_surface = NULL;
	text_texture = NULL;
	winner = winner_info(vm, text_texture, text_surface, pos);
	pos.x += pos.w + 120;
	text_surface = TTF_RenderText_Solid(g_font,
		vm->players[vm->last_alive - 1].header.prog_name, winner);
	text_texture = SDL_CreateTextureFromSurface(g_main_render, text_surface);
	SDL_FreeSurface(text_surface);
	TTF_SizeText(g_font, vm->players[vm->last_alive - 1].header.prog_name,
		&pos.w, &pos.h);
	SDL_RenderCopy(g_main_render, text_texture, NULL, &pos);
	SDL_DestroyTexture(text_texture);
	SDL_RenderPresent(g_main_render);
	key_pause_quite(vm);
}
