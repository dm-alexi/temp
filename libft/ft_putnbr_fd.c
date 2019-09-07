/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:40:16 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/05 21:41:07 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	s[10];
	char	*t;

	t = s + 9;
	*t-- = '\0';
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
	write(fd, t + 1, 9 - (t - s));
}