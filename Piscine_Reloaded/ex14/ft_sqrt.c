/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 22:44:52 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/04 22:45:31 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int		x;
	int		y;

	if (nb <= 0)
		return (0);
	x = nb;
	y = x / 2 + x % 2;
	while (y < x)
	{
		x = y;
		y = (x + nb / x) / 2;
	}
	return (x * x == nb ? x : 0);
}
