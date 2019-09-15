/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:11:50 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/12 13:42:08 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		ft_atoi(char *str)
{
	return ((int)ft_strtol(str, (char **)NULL, 10));
}