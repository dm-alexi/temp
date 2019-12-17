/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 23:32:16 by sscarecr          #+#    #+#             */
/*   Updated: 2019/12/16 22:51:02 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		count_elem(char *s)
{
	int		n;

	if (!s)
		return (0);
	n = 0;
	while (*s == ' ')
		++s;
	while (*s)
	{
		while (*s && *s != ' ')
			++s;
		++n;
		while (*s == ' ')
			++s;
	}
	return (n);
}
//todo: rewrite ft_lstdelone and ft_lstdel to get rid of this redundant function
static void		clear_list(t_list *t)
{
	t_list	*tmp;

	while (t)
	{
		tmp = t->next;
		free(t->content);
		free(t);
		t = tmp;
	}
}

static t_vertex	get_next_vertex(int y, int x, char **s)
{
	t_vertex	v;

    v.x = x;
    v.y = y;
    v.w = 1.0;
    v.z = ft_strtol(*s, s, 10);
    if ((!v.z && *(*s - 1) != '0') || (**s && **s != ',' && **s != ' '))
		error("invalid map.");
    if (*(*s++) == ',')
    {
    	v.color = ft_strtol(*s, s, 0);
    	if ((!v.color && *(*s - 1) != '0') || (**s && **s != ' '))
			error("invalid map.");
    }
    else
        v.color = 0xffffff;
	return (v);
}

static void		get_grid(t_list *t, t_map *map)
{
	int		i;
	int		j;
	char	*s;

	if (!(map->grid = (t_vertex *)malloc(sizeof(t_vertex) * map->length)))
		sys_error();
	i = map->rows - 1;
	while (i >= 0)
	{
		j = 0;
		s = t->content;
		while (j < map->columns)
		{
			map->grid[i * map->columns + j] = get_next_vertex(i, j, &s);
			++j;
		}
		if (count_elem(s))
			error("invalid map.");
		t = t->next;
		--i;
	}
}

t_map			*get_map(int fd)
{
	t_map	*map;
	char	*line;
	t_list	*t;
	t_list	*tmp;
	int		r;

	if (!(map = (t_map*)ft_memalloc(sizeof(t_map))))
		sys_error();
	t = NULL;
	while ((r = get_next_line(fd, &line)) != 0 && ++map->rows)
	{
		if (r < 0 || !(tmp = ft_lstnew(line, ft_strlen(line) + 1)))
			sys_error();
		ft_lstadd(&t, tmp);
		free(line);
	}
	if (!map->rows || !(map->columns = count_elem(t->content)))
		error("invalid map.");
	map->length = map->rows * map->columns;
	get_grid(t, map);
	clear_list(t);
	return (map);
}
