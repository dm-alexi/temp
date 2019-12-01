/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 23:32:16 by sscarecr          #+#    #+#             */
/*   Updated: 2019/12/01 14:32:11 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

	if (!(map->grid = (int**)malloc(sizeof(int*) * map->width)))
		sys_error();
	i = map->width - 1;
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

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		sys_error();
	ft_bzero(map, sizeof(t_map));
	t = NULL;
	while ((r = get_next_line(fd, &line)) != 0 && ++map->width)
	{
		if (r < 0)
			sys_error();
		ft_lstadd(&t, ft_lstnew(line, ft_strlen(line) + 1));
		free(line);
	}
	if (!map->width)
		error("invalid map.");
	get_grid(t, map);
	clear_list(t);
	return (map);
}
