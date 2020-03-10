#include "filler.h"

static void	add(t_queue **q, t_queue **last, int n)
{
	if (!*q)
	{
		if (!(*q = (t_queue*)malloc(sizeof(t_queue))))
			sys_error();
		*last = *q;
	}
	else
	{
		if (!((*last)->next = (t_queue*)malloc(sizeof(t_queue))))
			sys_error();
		*last = (*last)->next;
	}
	(*last)->next = NULL;
	(*last)->num = n;
}

static void	process(t_queue **q, t_queue **last, t_map *map)
{
	t_queue	*t;
	int		i;

	i = (*q)->num;
	if (i / map->w > 0 && map->arr[i - map->w] > map->arr[i] + 1 &&
	(map->arr[i - map->w] = map->arr[i] + 1))
		add(q, last, i - map->w);
	if (i / map->w < map->h - 1 && map->arr[i + map->w] > map->arr[i] + 1 &&
	(map->arr[i + map->w] = map->arr[i] + 1))
		add(q, last, i + map->w);
	if (i % map->w > 0 && map->arr[i - 1] > map->arr[i] + 1 &&
	(map->arr[i - 1] = map->arr[i] + 1))
		add(q, last, i - 1);
	if (i % map->w < map->w - 1 && map->arr[i + 1] > map->arr[i] + 1 &&
	(map->arr[i + 1] = map->arr[i] + 1))
		add(q, last, i + 1);
	t = *q;
	*q = (*q)->next;
	free(t);
}

void		setup(t_map *map)
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
		(ft_toupper(map->field[i]) == map->enemy ? 0 : -1)))
			add(&q, &last, i);
	while (q)
		process(&q, &last, map);
}
