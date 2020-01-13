/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:31:00 by sscarecr          #+#    #+#             */
/*   Updated: 2020/01/13 22:13:02 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#define ESC 53

int		win_close(void *param)
{
	(void)param;
	exit(EXIT_SUCCESS);
}

int		key_handle(int key, void *param)
{
	if (key == ESC)
		win_close(param);
	if (param == NULL)
		ft_printf("%d ", key);
	return (0);
}
