/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 23:01:05 by sscarecr          #+#    #+#             */
/*   Updated: 2020/03/11 23:01:07 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	clear(t_queue **q)
{
	t_queue	*t;

	while (*q)
	{
		t = (*q)->next;
		free(*q);
		(*q) = t;
	}
	return (1);
}

static int	add(t_queue **q, t_queue **last, int n)
{
	if (!*q)
	{
		if (!(*q = (t_queue*)malloc(sizeof(t_queue))))
			return (sys_error());
		*last = *q;
	}
	else
	{
		if (!((*last)->next = (t_queue*)malloc(sizeof(t_queue))))
			return (sys_error());
		*last = (*last)->next;
	}
	(*last)->next = NULL;
	(*last)->num = n;
	return (0);
}

static int	process(t_queue **q, t_queue **last, t_map *map)
{
	t_queue	*t;
	int		i;

	i = (*q)->num;
	if (i / map->w > 0 && map->arr[i - map->w] > map->arr[i] + 1 &&
	(map->arr[i - map->w] = map->arr[i] + 1) && add(q, last, i - map->w))
		return (1);
	if (i / map->w < map->h - 1 && map->arr[i + map->w] > map->arr[i] + 1 &&
	(map->arr[i + map->w] = map->arr[i] + 1) && add(q, last, i + map->w))
		return (1);
	if (i % map->w > 0 && map->arr[i - 1] > map->arr[i] + 1 &&
	(map->arr[i - 1] = map->arr[i] + 1) && add(q, last, i - 1))
		return (1);
	if (i % map->w < map->w - 1 && map->arr[i + 1] > map->arr[i] + 1 &&
	(map->arr[i + 1] = map->arr[i] + 1) && add(q, last, i + 1))
		return (1);
	t = *q;
	*q = (*q)->next;
	free(t);
	return (0);
}

int			setup(t_map *map)
{
	t_queue	*q;
	t_queue	*last;
	int		i;

	i = -1;
	q = NULL;
	while (++i < map->h * map->w)
		if (map->field[i] == '.')
			map->arr[i] = map->h * map->w;
		else if (!(map->arr[i] =
		(ft_toupper(map->field[i]) == map->enemy ? 0 : -1)) &&
		add(&q, &last, i) && clear(&q))
			return (1);
	while (q)
		if (process(&q, &last, map) && clear(&q))
			return (1);
	return (0);
}
