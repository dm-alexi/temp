/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 22:43:57 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/12 16:59:57 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define LONGMAX (~0UL >> 1)
#define LONGMIN ((~0UL >> 1) + 1)

static int			is_valid(char c, int base)
{
	return (base <= 10 ? ft_isdigit(c) && c - '0' < base :
			ft_isdigit(c) || (ft_isalpha(c) && c - 'A' + 10 < base));
}

static long int		ft_strtol_process(const char *nptr, char **endptr,
		int base, int neg)
{
	long int				n;
	char					c;

	n = 0;
	while (is_valid((c = ft_toupper(*nptr)), base))
	{
		c = ft_isdigit(c) ? c - '0' : c - 'A' + 10;
		if (n > (LONGMAX - c) / base)
		{
			n = neg ? LONGMIN : LONGMAX;
			break ;
		}
		n = n * base + c;
		++nptr;
	}
	if (endptr)
	{
		while (is_valid(ft_toupper(*nptr), base))
			++nptr;
		*endptr = (char*)nptr;
	}
	return (neg ? -n : n);
}

long int			ft_strtol(const char *nptr, char **endptr, int base)
{
	int		neg;

	if (base < 0 || base == 1 || base > 36)
		return (0);
	while (ft_isspace(*nptr))
		++nptr;
	if (*nptr == '+' || *nptr == '-')
		neg = (*nptr++ == '-');
	else
		neg = 0;
	if ((!base || base == 16) && *nptr == '0' && ft_toupper(*(nptr + 1)) == 'X')
		return (ft_strtol_process(nptr + 2, endptr, 16, neg));
	if (!base && *nptr == '0')
		return (ft_strtol_process(nptr + 1, endptr, 8, neg));
	return (ft_strtol_process(nptr, endptr, base == 0 ? 10 : base, neg));
}
