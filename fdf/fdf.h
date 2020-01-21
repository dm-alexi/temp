/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 23:32:20 by sscarecr          #+#    #+#             */
/*   Updated: 2020/01/21 20:54:42 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# define WIDTH 1920
# define HEIGHT 1080
# define STEP 10
# define INVALID "Invalid map."

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

typedef struct	s_map
{
	int			length;
	int			columns;
	int			rows;
	int			z_min;
	int			z_max;
	int			m[16];
	void		*mlx;
	void		*win;
	t_image		*image;
	t_vertex	*grid;
}				t_map;

void			sys_error(void);
void			error(char *s);
t_map			*get_map(int fd);
void			fdf_init(char *file, t_map *map);
int				key_handle(int key, void *param);
int				win_close(void *param);
t_image			*new_image(void *mlx, int width, int height);
void			image_put_pixel(t_image *image, int x, int y, int color);
void			image_draw_line(t_image *image, t_vertex *a, t_vertex *b);
void			map_matrix_init(t_map *map);
void			show_matrix(double m[16]);
//void			image_clear(t_image *image);

double			*mult(double a[16], double b[16], double c[16]);
t_vertex		*transform(t_vertex *v, double m[16], t_vertex *out);
double			*identity(void);
double			*scale(int r);
double			*translation(double x, double y, double z);
double			*rotation(double ax, double ay, double az);
double			*projection(double fov, double ratio, double near, double far);
#endif
