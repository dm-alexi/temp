/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:31:17 by sscarecr          #+#    #+#             */
/*   Updated: 2021/10/19 21:47:28 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# define MINSIZE	8
# define TINYSIZE	getpagesize()
# define SMALLSIZE	(64 * (TINYSIZE))

# include <pthread.h>
# include <stdlib.h>

typedef struct s_area
{
	struct s_area	*next;
	size_t			size;
} t_area;

typedef struct s_mempage
{
	struct s_mempage	*next;
	t_area				*vacant;
	t_area				*occupied;
} t_mempage;

typedef struct s_pages
{
	t_mempage	*tiny;
	t_mempage	*small;
} t_pages;

extern pthread_mutex_t	g_mutex;
extern t_pages			g_pages;

t_mempage	*getmempage(size_t size);

#endif