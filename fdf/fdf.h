/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 23:32:20 by sscarecr          #+#    #+#             */
/*   Updated: 2019/11/28 23:32:20 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H_INCLUDED
# define FDF_H_INCLUDED
# include "libft/libft.h"

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
#endif
