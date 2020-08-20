/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 20:48:01 by sscarecr          #+#    #+#             */
/*   Updated: 2020/08/20 22:40:36 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	draw_arena(t_game *game)
{
	SDL_Rect	cell;
	int			i;
	int			j;
	int			color;

	cell.w = game->cell;
	cell.h = game->cell;
	i = -1;
	while (++i < game->h)
	{
		j = -1;
		cell.y = i * (cell.h + 1) + 1;
		while (++j < game->w)
		{
			cell.x = j * (cell.w + 1) + 1;
			color = GREY;
			if (game->current->table[i * game->w + j] != '.')
				color = (ft_toupper(game->current->table[i * game->w + j])
				== 'X' ? RED : BLUE);
			SDL_SetRenderDrawColor(game->renderer, color & 0xff,
				color >> 8 & 0xff, color >> 16 & 0xff, 255);
			SDL_RenderFillRect(game->renderer, &cell);
			SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, 255);
		}
	}
}
