/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 23:32:20 by sscarecr          #+#    #+#             */
/*   Updated: 2020/01/26 20:06:37 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# define WIDTH 1920
# define HEIGHT 1080
# define STEP 10
# define INVALID "Invalid map."
# define MIDCOLOR 0xFFFFFF
# define MINCOLOR 0x0000FF
# define MAXCOLOR 0xFF0000

typedef struct	s_vertex
{
	int		x;
	int		y;
	int		z;
	int		w;
	int		color;
}				t_vertex;

typedef struct	s_image
{
	void	*img;
	int		bpp;
	int		sizeline;
	int		width;
	int		height;
	int		endian;
	char	*s;
}				t_image;

typedef struct	s_matrix
{
	double	initial[16];
	double	result[16];
	double	scale;
	double	rotate[3];
	double	move[3];
}				t_matrix;

typedef struct	s_map
{
	int			length;
	int			columns;
	int			rows;
	int			z_min;
	int			z_max;
	t_matrix	matrix;
	void		*mlx;
	void		*win;
	t_image		*image;
	t_vertex	*grid;
	t_vertex 	*show;
}				t_map;

void			sys_error(void);
void			error(char *s);
t_map			*get_map(int fd);
void			fdf_init(char *file, t_map *map);
int				key_handle(int key, void *param);
int				win_close(void *param);
t_image			*new_image(void *mlx, int width, int height);
void			image_draw_line(t_image *image, t_vertex *a, t_vertex *b);
void			show_matrix(double m[16]);

double			*mult(double a[16], double b[16], double c[16]);
t_vertex		*transform(t_vertex *v, double m[16], t_vertex *out);
void			matrix_init(t_map *map);
void			matrix_result(t_map *map);
double			*projection(double fov, double ratio, double near, double far);

void			ft_menu(t_map *map);
int				gradient_check(t_vertex *a, t_vertex *b, int steps, int i);
int				gradient(int start, int finish, double k);

int red (int color);
int green (int color);
int blue (int color);

#endif
