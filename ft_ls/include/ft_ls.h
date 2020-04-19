/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 12:23:10 by sscarecr          #+#    #+#             */
/*   Updated: 2020/04/20 01:35:21 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft.h"

# define ALMOST_ALL		1
# define ALL			2
# define HUMAN			1
# define HUMAN_SI		2
# define NO_SORT		1
# define SORT_SIZE		2
# define SORT_MOD_TIME	4

/*
** all: 1 - almost all (-A); 2 - all (-a)
** human: 1 - powers of 1024 (-h); 2 - powers of 1000 (--si)
** longlist: 1 - all (-l); 2 - no owner (-g); 4 - no group (-o)
** sort: 0 name; 1 - no sort (-U); 2 - size (-S); 4 - modification time (-t);
*/

typedef struct	s_param
{
	char	all;
	//char	author;
	char	directory;
	char	f;
	char	human;
	char	longlist;
	char	reverse;
	char	recursive;
	char	sort;
}				t_param;

void			sys_error(char *s);
void			error(char *s);
void			error2(char *s, char *t);
void			error3(char *s, char c);

t_list			*input(int ac, char **av, t_param *param);

#endif
