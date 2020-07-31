/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:40:16 by sscarecr          #+#    #+#             */
/*   Updated: 2020/07/31 11:18:01 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** String size necessary to contain 64-bit signed integer
*/

#define MAXINTLEN	20

void	ft_putnbr_fd(int n, int fd)
{
	char	s[MAXINTLEN];
	char	*t;

	t = s + MAXINTLEN - 1;
	if (n == 0)
		*t-- = '0';
	else if (n < 0)
	{
		write(fd, "-", 1);
		*t-- = -(n % 10) + '0';
		n = -(n / 10);
	}
	while (n)
	{
		*t-- = n % 10 + '0';
		n /= 10;
	}
	write(fd, t + 1, MAXINTLEN - 1 - (t - s));
}
