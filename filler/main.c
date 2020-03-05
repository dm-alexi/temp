/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:46:54 by sscarecr          #+#    #+#             */
/*   Updated: 2020/02/26 18:47:50 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	main(void)
{
	t_map	map;
	t_piece	piece;
	int		found;

	map.field = NULL;
	piece.field = NULL;
	found = 1;
	get_player(&map);
	while (found && get_dim(&map))
	{
		get_map(&map);
		get_piece(&piece);
		found = solve(map, piece);
		free(piece.field);
		piece.field = NULL;
	}
	free(map.field);
	return (0);
}
