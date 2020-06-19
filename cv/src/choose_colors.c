/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_colors_pt1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 17:04:28 by asmall            #+#    #+#             */
/*   Updated: 2020/06/20 00:21:00 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	choose_color(t_battlefield *cell, int i)
{
	static const int	colors_rgb[] = {0x00009b, 0x009b9b, 0x008000, 0x9b0000,
		0x800080, 0x9b9b00, 0xa9a9a9, 0x323232};
	
	cell->color = choose_color_char(i);
	cell->color_rgb = colors_rgb[i];
}

char	choose_color_char(int i)
{
	static const char	colors[] = "rygbpcel";
	
	return (i >= 0 && i < 8 ? colors[i] : 'n');
}

int		choose_reverse_color(t_battlefield *cell)
{
	static const int	colors_rgb[] = {0x00009b, 0x009b9b, 0x008000, 0x9b0000,
		0x800080, 0x9b9b00, 0xa9a9a9, 0x323232};
	static const char	colors[] = "rygbpcel";
	char				*s;
	
	if (!(s = ft_strchr(colors, cell->colors)))
		return (8);
	cell->color_rgb = colors_rgb[s - colors];
	return (s - colors);
}
