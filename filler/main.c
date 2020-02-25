#include "filler.h"

int main(void)
{
	t_map	map;

	map.sign = get_player();
	map.field = NULL;
	while (get_dim(&map))
	{

	}
	free(map.field);
    return 0;
}
