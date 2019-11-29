/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 23:32:20 by sscarecr          #+#    #+#             */
/*   Updated: 2019/11/29 20:45:51 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H_INCLUDED
# define FDF_H_INCLUDED
# include "libft/libft.h"
# define WIDTH 900
# define HEIGHT 1080

typedef struct	s_point
{
	int		x;
	int		y;
	int		z;
}				t_point;

typedef struct	s_map
{
	int		length;
	int		width;
	int		height;
	int		**grid;
}				t_map;

void			sys_error(void);
void			error(char *s);
t_map			*get_map(int fd);
void			window(char *file);
int				key_handle(int key, void *param);
void    image_draw_line(char *image, t_point *a, t_point *b, int color);
#endif
