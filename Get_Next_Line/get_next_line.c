/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:54:58 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/14 17:20:03 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#include "libft.h"

t_file  *getfile(const int fd, t_file **files)
{
    t_file *t;
    t_file *tmp;

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

int fillbuf(t_file *file, t_buf *buf)
{
    int r;
    char *s;
	t_buf *t;

    if (!buf->len)
        if ((r = read(file->fd, buf->str, BUFF_SIZE)) <= 0)
		{
            return (r);
		}
        else
		{
			buf->len = r;
		}
	t = buf;
    while (!(s = ft_memchr(t->str, '\n', t->len)))
    {
        t->next = (t_buf*)malloc(sizeof(t_buf));
        t->next->next = NULL;
        if ((t->next->len = read(file->fd, buf->str, BUFF_SIZE)) == -1)
            return (-1);
		else if (t->next->len == 0)
			break;
		r += t->next->len;
		t = t->next;
    }
    return (r + 1);
}

int readbuf(t_file *file, char **line)
{
    char *s;
    t_buf *t;
    t_buf *tmp;
    int len;

    if ((len = fillbuf(file, (t = file->buf))) <= 0)
        return (len);
    if (!(*line = (char*)malloc(len)))
        return (-1);
    s = *line;
    while ((tmp = t->next))
    {
        ft_memcpy(s, t->str, t->len);
        s += t->len;
        len -= t->len;
        free(t);
        t = tmp;
    }
    ft_memcpy(s, t->str, len - 1);
    *(s + len - 1) = '\0';
    t->len = t->len > len ? t->len - len : 0;
    if (t->len)
        ft_memcpy(t->str, t->str + len, t->len);
    file->buf = t;
    //printf("%d\n", file->buf->len);
    return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_file	*files = NULL;
	t_file *f;
//	t_buf  *t;
	int r;

    f = getfile(fd, &files);
    if ((r = readbuf(f, line)) <= 0)
    {
        /*
        while (t = f->buf)
        {
            free(f->buf);
            f->buf = t->next;
        }*/
        //free file
        return (r);
    }
    /*
    for (t_file *k = files; k; k = k->next)
        printf("%d ", k->fd);
    printf("\n");*/
    return 1;
}
