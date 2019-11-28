/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 23:32:18 by sscarecr          #+#    #+#             */
/*   Updated: 2019/11/28 23:32:18 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"

void	sys_error(void)
{
	perror("Error");
	exit(1);
}

void	error(char *s)
{
	write(2, "Error: ", 7);
	write(2, s, ft_strlen(s));
	exit(1);
}
