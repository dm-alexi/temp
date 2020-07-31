/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:29:44 by sscarecr          #+#    #+#             */
/*   Updated: 2020/07/31 11:18:12 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** String size necessary to contain 64-bit signed integer
*/

#define MAXINTLEN	20

void	ft_putnbr(int n)
{
	char	s[MAXINTLEN];
	char	*t;

	t = s + MAXINTLEN - 1;
	if (n == 0)
		*t-- = '0';
	else if (n < 0)
	{
		write(1, "-", 1);
		*t-- = -(n % 10) + '0';
		n = -(n / 10);
	}
	while (n)
	{
		*t-- = n % 10 + '0';
		n /= 10;
	}
	write(1, t + 1, MAXINTLEN - 1 - (t - s));
}
