/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:31:00 by sscarecr          #+#    #+#             */
/*   Updated: 2019/11/29 19:42:34 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#define ESC 53

int		key_handle(int key, void *param)
{
	if (key == ESC)
		exit(EXIT_SUCCESS);
	if (param == NULL)
		ft_printf("%d ", key);
	return (0);
}
