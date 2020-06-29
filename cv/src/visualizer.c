/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 17:06:18 by asmall            #+#    #+#             */
/*   Updated: 2020/06/29 18:38:58 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

const int	g_colors[MAX_PLAYERS + 1] = {0x00009b, 0x009b9b, 0x008000, 0x9b0000,
	0x6f6f6f};

void	init_visualizer(t_vm *vm)
{
	(void)vm; // check later
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		error2("SDL could not initialize. SDL error: ", SDL_GetError());
	if (!(g_main_window = SDL_CreateWindow("Corewar", SDL_WINDOWPOS_UNDEFINED,
	SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN)))
		error2("SDL could not create window. SDL error: ", SDL_GetError());
	if (!(g_main_render = SDL_CreateRenderer(g_main_window, -1,
	SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
		error2("SDL could not create renderer. SDL error: ", SDL_GetError());
	if (TTF_Init() < 0)
		error2("SDL_ttf could not initialize. SDL error: ", TTF_GetError());
	if (!(g_font = TTF_OpenFont("resource/InputMono-Regular.ttf", 15)))
		error(TTF_GetError());
}

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

void	event_handler(t_vm *vm)
{
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE)
			vm->vis_pause = !vm->vis_pause;
		else if (event.type == SDL_QUIT ||
		(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
			vm->vis_quit = 1;
	}
}

void	finish_visualization(t_vm *vm)
{
	visualize(vm);
	while (!vm->vis_quit && !vm->vis_pause)
		event_handler(vm);
	TTF_CloseFont(g_font);
	TTF_Quit();
	SDL_DestroyRenderer(g_main_render);
	SDL_DestroyWindow(g_main_window);
	SDL_Quit();
}
