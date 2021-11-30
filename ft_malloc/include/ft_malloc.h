/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.school-21.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:31:17 by sscarecr          #+#    #+#             */
/*   Updated: 2021/11/30 21:21:46 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# define MINSIZE		sizeof(size_t)
# define MAXTINYSIZE	(getpagesize() / 4)
# define TINYTABLE		(getpagesize() * 32)
# define MAXSMALLSIZE	(getpagesize() * 16)
# define SMALLTABLE		(MAXSMALLSIZE * 128)
# define VACANT			0
# define OCCUPIED		1

# include <pthread.h>
# include <string.h>

typedef	unsigned char	byte;

typedef struct s_area
{
	struct s_area	*prev;
	struct s_area	*next;
	int				size;
	int				status;
} t_area;

typedef struct s_bigarea
{
	struct s_bigarea	*prev;
	struct s_bigarea	*next;
	size_t				size;
} t_big;

typedef struct s_page
{
	struct s_page	*prev;
	struct s_page	*next;
} t_page;

typedef struct s_pages
{
	t_page	*tiny;
	t_page	*small;
	t_big	*big;
} t_pages;

extern pthread_mutex_t	g_mutex;
extern t_pages			g_pages;

t_page	*get_page(t_page **first, size_t size);
void	free_big(t_big *big);
void	*malloc(size_t size);
void	free(void *ptr);
void	show_alloc_mem(void);
void	ft_memcpy(void *dst, void *src, size_t num);

#endif