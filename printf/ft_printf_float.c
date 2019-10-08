/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:22:02 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/06 15:39:04 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <stddef.h>
#include <stdint.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft/libft.h"

static unsigned int		*ftoa(double d, char **s)
{
	int		    arr[37];
    int         order;
    int64_t     significand;

    significand = 1;
    //order =
    return 0;
}

void	ft_printf_float(t_format *format, va_list *va, int *n)
{
    double		d;

	d = (double)va_arg(*va, double);

}
