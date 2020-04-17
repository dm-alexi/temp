/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 12:23:10 by sscarecr          #+#    #+#             */
/*   Updated: 2020/04/08 01:34:56 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft.h"

typedef struct	s_param
{
	char	all;
	char	recursive;
	char	reverse;
	char	longlist;
}				t_param;

void			sys_error(char *s);

t_list			*input(int ac, char **av, t_param *param);

#endif
