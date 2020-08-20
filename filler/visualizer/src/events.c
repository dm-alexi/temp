/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 22:26:36 by sscarecr          #+#    #+#             */
/*   Updated: 2020/08/20 22:49:43 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void	move(t_game *game, int n)
{
	if (n > 0)
		while (n-- && game->current != game->finish)
			game->current = game->current->next;
	else
		while (n++ && game->current != game->start)
			game->current = game->current->prev;
}

void		event_handler(t_game *game)
{
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE)
			game->vis_pause = !game->vis_pause;
		else if (event.type == SDL_QUIT ||
		(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
			game->vis_quit = 1;
		else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_UP
		&& game->delay > MIN_DELAY)
			game->delay -= 10 + 10 * (game->delay > INIT_DELAY);
		else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_DOWN
		&& game->delay < MAX_DELAY)
			game->delay += 10 + 10 * (game->delay >= INIT_DELAY);
		else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_HOME)
			game->current = game->start;
		else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_END)
			game->current = game->finish;
		else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_LEFT)
			move(game, -10);
		else if (event.type == SDL_KEYDOWN &&
		event.key.keysym.sym == SDLK_RIGHT)
			move(game, 10);
	}
}
