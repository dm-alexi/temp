/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:46:32 by sscarecr          #+#    #+#             */
/*   Updated: 2020/03/15 22:20:42 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct	s_map
{
	int		w;
	int		h;
	char	*field;
	int		*arr;
	char	mine;
	char	enemy;
}				t_map;

typedef struct	s_piece
{
	int		w;
	int		h;
	char	*field;
}				t_piece;

typedef struct	s_queue
{
	int				num;
	struct s_queue	*next;
}				t_queue;

int				sys_error(void);
int				error(char *s);
int				get_player(t_map *map);
int				get_dim(t_map *map);
int				get_map(t_map *map);
int				setup(t_map *map);
int				get_piece(t_piece *piece);
void			solve(t_map map, t_piece piece);

#endif
