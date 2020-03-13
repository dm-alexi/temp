#include "visual.h"

void	delete_game(t_game *game)
{
	t_field	*t;

	while (game->start)
	{
		t = game->start->next;
		free(game->start->table);
		free(game->start);
		game->start = t;
	}
	free(game->p1);
	free(game->p2);
}
