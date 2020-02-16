/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 15:52:09 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/16 19:32:35 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# define WIDTH 1920
# define HEIGHT 1080

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

typedef struct  s_screen
{
    void    *mlx;
    void    *win;
    t_image *image;
}               t_screen;

void	        sys_error(void);

int				win_close(void *param);
int				key_handle(int key, void *param);

void            init(void *(void *), char *name);
t_image		    *new_image(void *mlx, int width, int height);
void            *mandelbrot(void *param);
void            *julia(void *param);
#endif