/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 17:05:44 by asmall            #+#    #+#             */
/*   Updated: 2020/06/26 17:51:29 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	push_distribution(t_battlefield *arena, int y)
{
	int			colors[9];
	int			i;
	float		k;
	SDL_Rect	coor;

	k = 300 / (float)MEM_SIZE;
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

void	push_char_text(char *text, int y, SDL_Color color)
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

void	push_int_text(int data, char *info_text, int y)
{
	char		*number;
	char		*full_line;
	
	full_line = NULL;
	if (!(number = ft_itoa(data)) ||
	!(full_line = ft_strjoin(info_text, number)))
		sys_error(NULL);
	free(number);
	push_char_text(full_line, y, WHITE);
	free(full_line);
}

void		push_int_slash_data(int y, int data_1, int data_2, char *text)
{
	char	*tmp1;
	char	*tmp2;
	char	*full_line;

	tmp2 = NULL;
	full_line = NULL;
	if (!(tmp1 = ft_itoa(data_1)) ||
	!(tmp2 = ft_itoa(data_2)) ||
	!(full_line = (char*)ft_memalloc(ft_strlen(text)
	+ ft_strlen(tmp1) + ft_strlen(tmp2) + 2)))
		sys_error(NULL);
	ft_strcat(full_line, text);
	ft_strcat(full_line, tmp1);
	full_line[ft_strlen(full_line)] = '/';
	ft_strcat(full_line, tmp2);
	free(tmp1);
	free(tmp2);
	push_char_text(full_line, y, WHITE);
	free(full_line);
}

void	key_pause_quite(t_vm *vm)
{
	SDL_Event	event;

	while (!vm->vis_pause && !vm->vis_quit)
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN
				&& event.key.keysym.sym == SDLK_ESCAPE))
				vm->vis_quit = 1;
			if (event.type == SDL_KEYDOWN
				&& event.key.keysym.sym == SDLK_SPACE)
				vm->vis_pause = 1;
		}
}
