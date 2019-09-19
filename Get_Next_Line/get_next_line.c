/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:54:58 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/19 13:30:18 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

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

int		readbuf(const int fd, t_file *f, char **line)
{
	char	*s;
	t_buf	*tmp;
	int		len;

	if ((len = fillbuf(fd, f->arr[fd])) <= 0)
		return (len);
	if (!(*line = (char*)malloc(len)))
		return (-1);
	s = *line;
	*(s + len - 1) = '\0';
	while ((tmp = f->arr[fd]->next))
	{
		ft_memcpy(s, f->arr[fd]->str, f->arr[fd]->len);
		s += f->arr[fd]->len;
		len -= f->arr[fd]->len;
		free(f->arr[fd]);
		f->arr[fd] = tmp;
	}
	ft_memcpy(s, f->arr[fd]->str, len - 1);
	f->arr[fd]->len = f->arr[fd]->len > len ? f->arr[fd]->len - len : 0;
	ft_memcpy(f->arr[fd]->str, f->arr[fd]->str + len, f->arr[fd]->len);
	return (1);
}

void	delfile(int fd, t_file *f)
{
	t_buf	*t;
	t_buf	**tmp;

	while ((t = f->arr[fd]))
	{
		f->arr[fd] = f->arr[fd]->next;
		free(t);
	}
	if (fd == f->len - 1)
		while (fd >= 0 && !f->arr[fd])
			--fd;
	if (fd < 0)
	{
		free(f->arr);
		f->len = 0;
	}
	else if ((tmp = ft_realloc(f->arr, f->len * sizeof(t_buf*),
		(fd + 1) * sizeof(t_buf*))))
	{
		f->arr = tmp;
		f->len = fd + 1;
	}
}

int		expand(const int fd, t_file *f)
{
	size_t	size;
	t_buf	**tmp;

	size = (fd + 1) * sizeof(t_buf*);
	if (!(tmp = (t_buf**)ft_realloc(f->arr, f->len * sizeof(t_buf*), size)))
		return (1);
	ft_bzero(tmp + f->len, size - f->len * sizeof(t_buf*));
	f->arr = tmp;
	f->len = fd + 1;
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_file	f = {0, NULL};
	int				r;

	if (fd < 0 || !line || (fd >= f.len && expand(fd, &f)))
		return (-1);
	if (!f.arr[fd])
	{
		if (!(f.arr[fd] = (t_buf*)malloc(sizeof(t_buf))))
			return (-1);
		f.arr[fd]->next = NULL;
		f.arr[fd]->len = 0;
	}
	if ((r = readbuf(fd, &f, line)) <= 0)
	{
		delfile(fd, &f);
		return (r);
	}
	return (1);
}
