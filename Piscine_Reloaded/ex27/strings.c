/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:20:56 by sscarecr          #+#    #+#             */
/*   Updated: 2019/07/17 16:15:14 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
		ft_putchar('-');
	if (nb > 9)
		ft_putnbr(nb / 10);
	else if (nb < -9)
		ft_putnbr(-(nb / 10));
	if (nb < 0)
		ft_putchar((char)(-(nb % 10) + '0'));
	else
		ft_putchar((char)(nb % 10) + '0');
	return ;
}

int		ft_strlen(char *str)
{
	int		n;

	n = 0;
	while (*str++)
		++n;
	return (n);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	ft_puterr(char *str)
{
	write(2, str, ft_strlen(str));
}
