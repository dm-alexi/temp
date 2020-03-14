/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:35:01 by sscarecr          #+#    #+#             */
/*   Updated: 2020/03/14 19:46:47 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H
# include "libft.h"

# define RED 0xFF0000
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF
# define GREY 0x808080
# define BLACK 0x000000

# define BORDER 10
# define MENU_WIDTH 400
# define HEIGHT 1200
# define WIDTH 1600
# define TABLE_WIDTH 1200
# define MIN_CELL 12

typedef struct	s_image
{
	void	*img;
	int		bpp;
	int		sizeline;
	int		width;
	int		height;
	int		endian;
	char	*map;
}				t_image;

typedef struct	s_screen
{
	int		play;
	void	*mlx;
	void	*win;
	t_image	*image;
}				t_screen;

typedef struct	s_field
{
	char			*table;
	struct s_field	*prev;
	struct s_field	*next;
}				t_field;

typedef struct	s_game
{
	int			w;
	int			h;
	int			cell;
	int			score1;
	int			score2;
	t_field		*start;
	t_field		*finish;
	t_field		*current;
	char		*p1;
	char		*p2;
	char		*title;
	t_screen	*screen;
}				t_game;

void			sys_error(void);
void			error(char *s);
void			input(int fd, t_game *game);
void			init_visual(t_game *game);
int				win_close(void *param);
int				key_handle(int key, void *param);
void			draw(t_game *game);

#endif
