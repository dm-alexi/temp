#ifdef _WIN32
# include <stdio.h>
#else
# include <unistd.h>
#endif
#include "visual.h"

static int get_player(char *line)
{
	int		r;

	while ((r = get_next_line(STDIN_FILENO, &line)) > 0 &&
	!ft_strnequ(line, "Plateau ", 8))
	{
		if (ft_strnequ(line, "$$$ exec p", 10))
			return (1);
		free(line);
	}
	if (r <= 0)
		r ? sys_error() : error("players not launched\n");
	return (0);
}

void	input(t_game *game)
{
	char	*line;
	char	*t;
	int		r;

	if (!get_player(line))
		error("players not launched\n");
	t = ft_strchr(line, '[');
	game->p1 = ft_strsub(line, t - line + 1, ft_strrchr(line, '.') - t);
	free(line);
	if (get_player(line) && (t = ft_strchr(line, '[')))
	{
		game->p2 = ft_strsub(line, t - line + 1, ft_strrchr(line, '.') - t);
		free(line);
		if ((r = get_next_line(STDIN_FILENO, &line)) <= 0)
			r ? sys_error() : error("map not received\n");
	}
	else
		game->p2 = NULL;
	if (!ft_strnequ(line, "Plateau ", 8) ||
	(game->h = ft_strtol(line + 8, &t, 10)) <= 0 ||
	(game->w = ft_atoi(t)) <= 0)
		error("invalid map\n");
	free(line);
}
