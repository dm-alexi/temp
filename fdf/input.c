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

static void		free_arr(char **arr)
{
	char	**tmp;

	tmp = arr;
	while (*tmp)
		free(*tmp++);
	free(arr);
}

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

static int		*get_line(t_list *t, int *n)
{
	char	**arr;
	char	*tmp;
	int		*res;
	int		i;

	if (!t || !t->content)
		error("invalid map");
	arr = ft_strsplit(t->content, ' ');
	*n = 0;
	while (arr[*n])
		++*n;
	if (!(res = (int*)malloc(sizeof(int) * *n)))
		sys_error();
	i = 0;
	while (i < *n)
	{
		res[i] = ft_strtol(arr[i], &tmp, 10);
		if ((!res[i] && *(tmp - 1) != '0') || *tmp)
			error("invalid map.");
		++i;
	}
	free_arr(arr);
	return (res);
}

static void		get_grid(t_list *t, t_map *map)
{
	int		i;
	int		n;

	if (!(map->grid = (t_vertex *)malloc(sizeof(t_vertex) * map->length)))
		sys_error();
	i = (map->rows - 1) * map->columns;
	(map->grid)[i] = get_line(t, &(map->length));
	t = t->next;
	if (!map->length)
		error("invalid map.");
	while (--i >= 0)
	{
		(map->grid)[i] = get_line(t, &n);
		if (n != map->length)
			error("invalid map.");
		t = t->next;
	}
}

t_map			*get_map(int fd)
{
	t_map	*map;
	char	*line;
	t_list	*t;
	int		r;

	if (!(map = (t_map*)ft_memalloc(sizeof(t_map))))
		sys_error();
	t = NULL;
	while ((r = get_next_line(fd, &line)) != 0 && ++map->rows)
	{
		if (r < 0)
			sys_error();
		ft_lstadd(&t, ft_lstnew(line, ft_strlen(line) + 1));
		free(line);
	}
	if (!map->rows || !(map->columns = count_elem(t->content)))
		error("invalid map.");
	map->length = map->rows * map->columns;
	get_grid(t, map);
	clear_list(t);
	return (map);
}
