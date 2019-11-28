#include "fdf.h"

t_map	*get_map(int fd)
{
	t_map	*map;
	char	*line;
	int		r;

	if (!(map = (t_map*)malloc(sizeof(t_map))) || !(get_next_line(fd, &line)))
		error();
	while ((r = get_next_line(fd, &line)))
	{
		if (r < 0)
			error();

	}
}
