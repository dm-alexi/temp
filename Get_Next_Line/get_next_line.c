/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:54:58 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/11 21:38:08 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "libft.h"

int		getbuf(char **line, t_buf *buf, size_t *slen)
{
	char	*s;
	size_t	n;
	int		finished;

	if (!buf->len)
		return (0);
	finished = 0;
	s = buf->str;
	while ((size_t)(s - buf->str) < buf->len && *s != '\n')
		++s;
	n = s - buf->str;
	if (!(n + 1) || !(*line = (char*)realloc(*line, *slen + n + 1)))
		return (-1);
	ft_memcpy(*line + *slen, buf->str, n);
	*slen += n;
	*(*line + *slen) = '\0';
	if (n < buf->len)
		finished = (++n == buf->len);
	ft_memcpy(buf->str, buf->str + n, buf->len - n);
	buf->len -= n;
	return (finished || buf->len);
}

int		get_next_line(const int fd, char **line)
{
	static t_buf	buf = {0, {0}};
	size_t			slen;
	int				r;

	if (!line)
		return (-1);
	*line = NULL;
	slen = 0;
	if (!buf.len)
	{
		if ((r = read(fd, &(buf.str), BUFF_SIZE)) <= 0)
			return (r);
		buf.len = r;
	}
	while (!(r = getbuf(line, &buf, &slen)))
	{
		r = read(fd, &(buf.str), BUFF_SIZE);
		if (r <= 0)
			break ;
		buf.len = r;
	}
	if (r == -1)
	{
		free(*line);
		return (-1);
	}
	return (1);
}
