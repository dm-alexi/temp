/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:46:32 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/26 18:46:34 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"

typedef struct	s_map
{
	int		w;
	int		h;
	char	*field;
	char	mine;
	char	enemy;
}				t_map;

typedef struct	s_piece
{
	int		w;
	int		h;
	char	*field;
}				t_piece;

void			sys_error(void);
void			error(char *s);
void			get_player(t_map *map);
int				get_dim(t_map *map);
void			get_map(t_map *map);
void			get_piece(t_piece *piece);
void			solve(t_map map, t_piece piece);

#endif
