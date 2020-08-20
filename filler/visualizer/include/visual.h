/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 18:41:19 by sscarecr          #+#    #+#             */
/*   Updated: 2020/08/21 00:22:08 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include "libft.h"

# if __APPLE__
#  include "SDL.h"
#  include "SDL_ttf.h"
# else
#  include <SDL2/SDL.h>
#  include <SDL2/SDL_ttf.h>
# endif

# define MENU_WIDTH		400
# define HEIGHT			800
# define OFFSET			20
# define MIN_CELL		5
# define FONT_SIZE		15
# define FONT			"resource/InputMono-Regular.ttf"

# define INIT_DELAY		100
# define MAX_DELAY		200
# define MIN_DELAY		50

# define GREY			0x6f6f6f
# define RED			0x0000f0
# define BLUE			0xf00000

typedef struct	s_field
{
	char			*table;
	struct s_field	*prev;
	struct s_field	*next;
}				t_field;

typedef struct	s_game
{
	int				w;
	int				h;
	int				cell;
	int				score1;
	int				score2;
	t_field			*start;
	t_field			*finish;
	t_field			*current;
	char			*p1;
	char			*p2;
	char			*title;
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	TTF_Font		*font;
	t_byte			vis_quit;
	t_byte			vis_pause;
	int				width;
	int				height;
	int				delay;
}				t_game;

void			sys_error(void);
void			error(const char *s);
void			error2(const char *s, const char *t);
void			input(int fd, t_game *game);
void			visualization(t_game *game);
void			draw_menu(t_game *game);
void			event_handler(t_game *game);
void			delete_game(t_game *game);

#endif
