/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer_help_pt2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 18:02:09 by asmall            #+#    #+#             */
/*   Updated: 2020/06/21 12:24:11 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void			set_sdl_color(SDL_Color *color, int i)
{
	static const int	colors[] = {0x00009b, 0x009b9b, 0x008000, 0x9b0000,
		0x800080, 0x9b9b00, 0xa9a9a9, 0x323232, 0x6f6f6f};

	color->r = colors[i] & 0xff;
	color->g = colors[i] >> 8 & 0xff;
	color->b = colors[i] >> 16 & 0xff;
}

void			live_players(t_vm *vm, SDL_FRect coor, int sum)
{
	unsigned	i;
	float		k;

	i = -1;
	while (++i < vm->num_players)
		sum += vm->players[i].lives_in_current_period;
	k = 300 / (float)sum;
	i = -1;
	while (++i < vm->num_players)
	{
		coor.w = vm->players[i].lives_in_current_period * k;
		set_render_draw_color(choose_color(i));
		SDL_RenderFillRectF(g_main_render, &coor);
		coor.x += coor.w;
	}
}
