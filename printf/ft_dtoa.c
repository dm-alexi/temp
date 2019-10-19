/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 18:42:35 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/19 20:02:22 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_bigint.h"
#include "ft_printf.h"

void	ft_set_null(char *s, int prec, char spec)
{
	int		i;

	s[0] = '0';
	i = 1;
	if (prec && (spec == 'f' || spec == 'F' || spec == 'e' || spec == 'E'))
	{
		s[i++] = '.';
		ft_memset(s + 2, '0', prec);
		i += prec;
	}
	if (spec == 'e' || spec == 'E')
	{
		s[i++] = spec;
		s[i++] = '+';
		s[i++] = '0';
		s[i++] = '0';
	}
	s[i] = '\0';
}
/*
char	*ft_dtoa(double d, int prec, int *exp10, char spec)
{
	uint64_t	val;
	char		*s;
	int			i;

	if (!(s = (char*)malloc(prec + 4)))
		return (NULL);
	val = *(uint64_t*)&d;
	i = 0;
	if (val & 0x8000000000000000)
		s[i++] = '-';
	if (((val & 0x7ff0000000000000)) == 0x7ff0000000000000)
	{
		if (val & 0x000fffffffffffff)
			ft_strcpy(s + i, ft_isupper(spec) ? "NAN" : "nan");
		else
			ft_strcpy(s + i, ft_isupper(spec) ? "INF" : "inf");
	}
	else if (!(val & 0x7fffffffffffffff))
		ft_set_null(s + i, prec, spec);
	else
		ft_dtoa_format(s + i, d, prec, exp10);
	return (s);
}
*/