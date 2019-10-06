/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:19:30 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/06 15:39:02 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_format
{
	int		width;
	int		precision;
	char	flags;
	char	length;
	char	specifier;
}				t_format;

int				ft_printf(const char *format, ...);
void			ft_printf_string(t_format *format, va_list *va, int *n);
void			ft_printf_char(t_format *format, va_list *va, int *n);
void			ft_printf_int(t_format *format, va_list *va, int *n);
void			ft_printf_strfill(int fd, char c, int n);

#endif
