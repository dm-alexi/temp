/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 17:05:44 by asmall            #+#    #+#             */
/*   Updated: 2020/06/29 16:18:20 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static void	draw_data(int data, char *info_text, int y)
{
	char		*number;
	char		*full_line;

	full_line = NULL;
	if (!(number = ft_itoa(data)) ||
	!(full_line = ft_strjoin(info_text, number)))
		sys_error(NULL);
	free(number);
	draw_text(full_line, y, WHITE);
	free(full_line);
}

static void	draw_double_data(int y, int data_1, int data_2, char *text)
{
	char	*tmp1;
	char	*tmp2;
	char	*full_line;

	tmp2 = NULL;
	full_line = NULL;
	if (!(tmp1 = ft_itoa(data_1)) ||
	!(tmp2 = ft_itoa(data_2)) ||
	!(full_line = (char*)ft_memalloc(ft_strlen(text)
	+ ft_strlen(tmp1) + ft_strlen(tmp2) + 2)))
		sys_error(NULL);
	ft_strcat(full_line, text);
	ft_strcat(full_line, tmp1);
	full_line[ft_strlen(full_line)] = '/';
	ft_strcat(full_line, tmp2);
	free(tmp1);
	free(tmp2);
	draw_text(full_line, y, WHITE);
	free(full_line);
}

static void	draw_players(t_vm *vm, int pos)
{
	int			i;
	SDL_Color	color;

	i = 0;
	while (i < vm->num_players)
	{
		draw_data(i + 1, "Player # ", pos);
		color.r = g_colors[i] & 0xff;
		color.g = g_colors[i] >> 8 & 0xff;
		color.b = g_colors[i] >> 16 & 0xff;
		draw_text(vm->players[i].header.prog_name, pos + 20, color);
		draw_data(vm->players[i].last_alive, "Last alive: ", pos + 40);
		draw_data(vm->players[i].lives_in_current_period,
			"Lives in current period : ", pos + 60);
		draw_data(vm->players[i].num_cursors,
			"Number of processes: ", pos + 80);
		pos += 110;
		++i;
	}
}

static void	draw_winner(t_vm *vm, int y)
{
	SDL_Color	color;
	char		*full_line;

	if (!(full_line =
	ft_strjoin(vm->players[vm->winner - 1].header.prog_name, " won!")))
		sys_error(NULL);
	color.r = g_colors[vm->winner - 1] & 0xff;
	color.g = g_colors[vm->winner - 1] >> 8 & 0xff;
	color.b = g_colors[vm->winner - 1] >> 16 & 0xff;
	draw_text(full_line, y, color);
	free(full_line);
}

void		draw_menu(t_vm *vm)
{
	if (vm->winner < 0)
		draw_text(vm->vis_pause ? "***Pause***" : "***Running***", 20, WHITE);
	else
		draw_winner(vm, 20);
	draw_data(vm->num_process, "Total processes: ", 40);
	draw_data(vm->cycle, "Current cycle: ", 60);
	draw_data(vm->cycles_to_die, "Cycles to die: ", 90);
	draw_data(CYCLE_DELTA, "Cycle delta: ", 110);
	draw_double_data(130, vm->live_calls, NBR_LIVE, "NBR_live: ");
	draw_double_data(150, vm->checks, MAX_CHECKS, "MAX_checks: ");
	draw_players(vm, 180);
	draw_text("Live breakdown:", SCREEN_HEIGHT - 80, WHITE);
	push_live_breakdown(vm, SCREEN_HEIGHT - 60);
	draw_text("Arena distribution:", SCREEN_HEIGHT - 40, WHITE);
	push_distribution(vm->arena, SCREEN_HEIGHT - 20);
}
