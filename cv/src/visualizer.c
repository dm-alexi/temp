/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 17:06:18 by asmall            #+#    #+#             */
/*   Updated: 2020/06/26 21:45:29 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

const int	g_colors[MAX_COLORS] = {0x00009b, 0x009b9b, 0x008000, 0x9b0000,
	0x800080, 0x9b9b00, 0xa9a9a9, 0x323232, 0x6f6f6f};

static void	draw_arena(t_vm *vm)
{
	SDL_Rect	cell;
	int			i;

	cell.w = (SCREEN_WIDTH - INFORMATION_SIZE) / ARENA_WIDTH - 1;
	cell.h = SCREEN_HEIGHT / ARENA_HEIGHT - 1;
	i = -1;
	while (++i < MEM_SIZE)
	{
		cell.y = i / ARENA_WIDTH * (cell.h + 1) + 1;
		cell.x = i % ARENA_WIDTH * (cell.w + 1) + 1;
		SDL_SetRenderDrawColor(g_main_render,
			(vm->arena[i].color & 0xff) + vm->arena[i].write_cycles,
			(vm->arena[i].color >> 8 & 0xff) + vm->arena[i].write_cycles,
			(vm->arena[i].color >> 16 & 0xff) + vm->arena[i].write_cycles, 255);
		SDL_RenderFillRect(g_main_render, &cell);
		SDL_SetRenderDrawColor(g_main_render, 255, 255, 255, 255);
		if (vm->arena[i].cursors)
			SDL_RenderDrawRect(g_main_render, &cell);
		if (!vm->vis_pause && vm->arena[i].write_cycles)
			vm->arena[i].write_cycles--;
	}
}

void		visualize(t_vm *vm)
{
	SDL_SetRenderDrawColor(g_main_render, 0, 0, 0, 255);
	SDL_RenderClear(g_main_render);
	draw_arena(vm);
	draw_menu(vm);
	SDL_RenderPresent(g_main_render);
}
