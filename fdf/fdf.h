/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 23:32:20 by sscarecr          #+#    #+#             */
/*   Updated: 2019/12/01 16:28:42 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H_INCLUDED
# define FDF_H_INCLUDED
# include "libft/libft.h"
# define WIDTH 900
# define HEIGHT 1080
# define STEP 10

typedef struct	s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
}				t_point;

typedef struct	s_dot
{
	int		x;
	int		y;
	
}				t_dot;

typedef struct	s_image
{
	void	*img;
	int		bpp;
	int		width;
	int		endian;
	int		height;
	char 	*s;
}				t_image;

typedef struct	s_map
{
	int		length;
	int		width;
	int		height;
	int		**grid;
	t_point		*points;
	
}				t_map;

void			sys_error(void);
void			error(char *s);
t_map			*get_map(int fd);
void			window(char *file);
int				key_handle(int key, void *param);
t_image			*new_image(void *mlx, int width, int height);
void			image_put_pixel(t_image *image, int x, int y, int color);
void			image_draw_line(t_image *image, t_dot *a, t_dot *b);
#endif
