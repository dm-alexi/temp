/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:54:58 by sscarecr          #+#    #+#             */
/*   Updated: 2020/11/29 11:58:24 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"

/*
** Fills the buffer by repeatedly reading BUFF_SIZE bytes from a given file,
** stops at encountering '\n'. Returns the size of a string needed to contain
** the resulting line, including the terminating '\0'. In case of a read() error
** returns -1. If the end of file is reached and no data is read, returns 0.
*/

static int		fillbuf(t_file *file)
{
	int		len;
	char	*s;
	t_buf	*buf;

	buf = file->buffer;
	if (!buf->len && (buf->start = buf->str) &&
	(buf->len = read(file->fd, buf->str, BUFF_SIZE)) <= 0)
		return (buf->len);
	len = 0;
	while (!(s = (char*)ft_memchr(buf->start, '\n', buf->len)))
	{
		len += buf->len;
		if (!(buf->next = (t_buf*)ft_memalloc(sizeof(t_buf))))
			return (-1);
		buf = buf->next;
		buf->start = buf->str;
		if ((buf->len = read(file->fd, buf->str, BUFF_SIZE)) < 0)
			return (-1);
		else if (buf->len == 0)
			break ;
	}
	if (s)
		len += s - buf->start;
	return (len + 1);
}

/*
** Calls fillbuf(), allocates memory for a line, copies the line and rearranges
** the buffer. If read() or malloc() error occurs, returns -1. If the buffer
** is empty and the end of file is reached, returns 0.
*/

static int		readbuf(t_file *file, char **line)
{
	char	*s;
	t_buf	*tmp;
	int		len;

	if ((len = fillbuf(file)) <= 0)
		return (len);
	if (!(*line = (char*)malloc(len)))
		return (-1);
	s = *line;
	*(s + len - 1) = '\0';
	while ((tmp = file->buffer->next))
	{
		ft_memcpy(s, file->buffer->start, file->buffer->len);
		s += file->buffer->len;
		len -= file->buffer->len;
		free(file->buffer);
		file->buffer = tmp;
	}
	ft_memcpy(s, file->buffer->start, len - 1);
	file->buffer->start += len;
	file->buffer->len = file->buffer->len > len ? file->buffer->len - len : 0;
	return (1);
}

/*
** Deletes a t_file corresponding to the given file descriptor.
*/

static void		delfile(const int fd, t_file **f)
{
	t_file	*tmp;
	t_file	*t;
	t_buf	*buf;
	int		k;

	k = fd % GNL_ARRAY_SIZE;
	if (f[k]->fd == fd && (t = f[k]))
		f[k] = f[k]->next;
	else
	{
		tmp = f[k];
		while (tmp->next->fd != fd)
			tmp = tmp->next;
		t = tmp->next;
		tmp->next = t->next;
	}
	while (t->buffer)
	{
		buf = t->buffer->next;
		free(t->buffer);
		t->buffer = buf;
	}
	free(t);
}

/*
** Searches and returns a t_file* corresponding to the given file descriptor,
** creates one if needed.
*/

static t_file	*get_file(const int fd, t_file **f)
{
	t_file	*tmp;
	t_file	*t;
	int		k;

	k = fd % GNL_ARRAY_SIZE;
	if (!f[k] || f[k]->fd > fd)
	{
		if (!(t = (t_file*)ft_memalloc(sizeof(t_file))))
			return (NULL);
		t->fd = fd;
		t->next = f[k];
		return (f[k] = t);
	}
	tmp = f[k];
	while (tmp->next && tmp->fd < fd)
		tmp = tmp->next;
	if (tmp->fd == fd)
		return (tmp);
	if (!(t = (t_file*)ft_memalloc(sizeof(t_file))))
		return (NULL);
	t->fd = fd;
	t->next = tmp->next;
	return (tmp->next = t);
}

int				get_next_line(const int fd, char **line)
{
	static t_file	*f[GNL_ARRAY_SIZE];
	t_file			*file;
	int				r;

	if (fd < 0 || !line || !(file = get_file(fd, f)))
		return (-1);
	if (!file->buffer && !(file->buffer = (t_buf*)ft_memalloc(sizeof(t_buf))))
	{
		delfile(fd, f);
		return (-1);
	}
	if ((r = readbuf(file, line)) <= 0)
		delfile(fd, f);
	return (r);
}
