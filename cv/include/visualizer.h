/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 14:10:35 by asmall            #+#    #+#             */
/*   Updated: 2020/06/29 18:40:20 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# if __APPLE__
#  include "SDL.h"
#  include "SDL_ttf.h"
# else
#  include <SDL2/SDL.h>
#  include <SDL2/SDL_ttf.h>
# endif

# include "corewar.h"
# include "libft.h"

/*
** Visualizations screen parameters must be adjusted manually if MEM_SIZE value
** is to be changed.
** Arena width and height are in cells.
*/

# define SCREEN_WIDTH 1311
# define SCREEN_HEIGHT 705
# define SCREEN_FPS 244
# define SCREEN_TICKS_PER_FRAME 1000 / SCREEN_FPS
# define INFORMATION_SIZE 350
# define OFFSET 25
# define ARENA_WIDTH 64
# define ARENA_HEIGHT 64
# define BAR_WIDTH 300
# define BAR_HEIGHT 15
# define WHITE (SDL_Color){255, 255, 255, 255}

SDL_Window		*g_main_window;
SDL_Renderer	*g_main_render;
TTF_Font		*g_font;
extern const int	g_colors[];

void			init_visualizer(t_vm *vm);
void			visualize(t_vm *vm);
void			event_handler(t_vm *vm);
void			finish_visualization(t_vm *vm);

void			draw_menu(t_vm *vm);
void			draw_text(char *text, int y, SDL_Color color);
void			draw_live_bar(t_vm *vm, int y);
void			draw_distribution(t_battlefield *arena, int y);

#endif
