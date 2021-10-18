/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.school-21.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:31:17 by sscarecr          #+#    #+#             */
/*   Updated: 2021/10/18 20:28:27 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# define MINSIZE	8
# define TINYSIZE	getpagesize()
# define SMALLSIZE	(64 * TINYSIZE)

# include <pthread.h>
# include <stdlib.h>

enum e_status 
{
	FREE, OCCUPIED
};

typedef struct s_area
{
	void			*start;
	size_t			size;
	e_status		status;
	struct s_area	*next;
} t_area;

typedef struct s_mempage
{
	t_area				*area;
	struct s_mempage	*next;
	void				*page;
} t_mempage;

t_mempage	*getmempage(size_t size);

#endif