/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 23:32:18 by sscarecr          #+#    #+#             */
/*   Updated: 2019/11/29 19:34:30 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"

void	sys_error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

void	error(char *s)
{
	write(2, "Error: ", 7);
	write(2, s, ft_strlen(s));
	exit(EXIT_FAILURE);
}
