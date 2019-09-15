/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:54:58 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/15 20:41:34 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#include "libft.h"

t_file	*getfile(const int fd, t_file **files)
{
	t_file	*t;
	t_file	*tmp;

	t = *files;
	if (t && t->fd <= fd)
	{
		while (t->next && t->next->fd <= fd)
			t = t->next;
		if (t->fd == fd)
			return (t);
	}
	if (!(tmp = (t_file*)malloc(sizeof(t_file))) ||
		!(tmp->buf = (t_buf*)malloc(sizeof(t_buf))))
	{
		free(tmp);
		return (NULL);
	}
	tmp->next = !t || t->fd > fd ? t : t->next;
	tmp->buf->next = NULL;
	tmp->buf->len = 0;
	tmp->fd = fd;
	if (!t || t->fd > fd)
		return ((*files = tmp));
	return ((t->next = tmp));
}

void	delfile(const int fd, t_file **files)
{
	t_file	*t;
	t_file	*tmp;
	t_buf	*buf;

	tmp = NULL;
	t = *files;
	if (t->fd == fd)
		*files = t->next;
	while (t->fd != fd)
	{
		tmp = t;
		t = t->next;
	}
	if (tmp)
		tmp->next = t->next;
	while ((buf = t->buf))
	{
		t->buf = t->buf->next;
		free(buf);
	}
	free(t);
}

int		fillbuf(const int fd, t_buf *buf)
{
	int		len;
	char	*s;
	t_buf	*t;

	if (!buf->len && (buf->len = read(fd, buf->str, BUFF_SIZE)) <= 0)
		return (buf->len);
	len = 0;
	t = buf;
	while (!(s = (char*)ft_memchr(t->str, '\n', t->len)))
	{
		len += t->len;
		t->next = (t_buf*)malloc(sizeof(t_buf));
		t = t->next;
		t->next = NULL;
		if ((t->len = read(fd, t->str, BUFF_SIZE)) == -1)
			return (-1);
		else if (t->len == 0)
			break ;
	}
	if (s)
		len += s - t->str;
	return (len + 1);
}

int		readbuf(t_file *file, char **line)
{
	char	*s;
	t_buf	*t;
	t_buf	*tmp;
	int		len;

	t = file->buf;
	if ((len = fillbuf(file->fd, t)) <= 0)
		return (len);
	if (!(*line = (char*)malloc(len)))
		return (-1);
	s = *line;
	*(s + len - 1) = '\0';
	while ((tmp = t->next))
	{
		ft_memcpy(s, t->str, t->len);
		s += t->len;
		len -= t->len;
		free(t);
		t = tmp;
	}
	ft_memcpy(s, t->str, len - 1);
	t->len = t->len > len ? t->len - len : 0;
	ft_memcpy(t->str, t->str + len, t->len);
	file->buf = t;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_file	*files = NULL;
	t_file			*f;
	int				r;

	if (fd < 0)
		return (-1);
	f = getfile(fd, &files);
	if ((r = readbuf(f, line)) <= 0)
	{
		delfile(fd, &files);
		return (r);
	}
	return (1);
}
