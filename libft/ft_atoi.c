/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:11:50 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/15 13:14:40 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Due to the task restrictions we don't have access to limits.h,
** so we assume sizeof(int) == 4 && sizeof(long) == 8
** as it agrees with our current UNIX environment.
** Also, errno is not changed in case of overflow, for the same reason.
*/

static int			is_valid(char c, int base)
{
	return (base <= 10 ? ft_isdigit(c) && c - '0' < base :
		ft_isdigit(c) || (ft_isalpha(c) && c - 'A' + 10 < base));
}

static long int		ft_strtol_process(const char *nptr, char **endptr,
						int base, int neg)
{
	static const long int	longmax = 9223372036854775807;
	static const long int	longmin = 0x8000000000000000;
	long int				n;
	char					c;

	n = 0;
	while (is_valid((c = ft_toupper(*nptr)), base))
	{
		c = ft_isdigit(c) ? c - '0' : c - 'A' + 10;
		if (n > (longmax - c) / base)
		{
			n = neg ? longmin : longmax;
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

static long int		ft_strtol_static(const char *nptr, char **endptr, int base)
{
	int		neg;

	if (base < 0 || base == 1 || base > 36)
		return (0);
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n' ||
	*nptr == '\v' || *nptr == '\f' || *nptr == '\r')
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

int					ft_atoi(const char *str)
{
	return ((int)ft_strtol_static(str, (char **)NULL, 10));
}
