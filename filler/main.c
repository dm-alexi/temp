#include "filler.h"

int main(void)
{
	t_map	map;
	t_piece	piece;

	map.field = NULL;
	piece.field = NULL;
	get_player(&map);
	while (get_dim(&map))
	{
        get_map(&map);
        get_piece(&piece);
        solve(map, piece);
		free(piece.field);
		piece.field = NULL;
	}
	free(map.field);
    return 0;
}
