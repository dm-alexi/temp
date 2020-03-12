/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:35:01 by sscarecr          #+#    #+#             */
/*   Updated: 2020/03/11 18:06:23 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H
# include "libft/libft.h"

# define RED 0xFF0000
# define BLUE 0x0000FF

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
	void		*mlx;
	void		*win;
	t_image		*image;
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
	t_field		*start;
	t_field		*finish;
	t_field		*current;
	char		*p1;
	char		*p2;
	t_screen	*screen;
}				t_game;

void			sys_error(void);
void			error(char *s);

#endif
