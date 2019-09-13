/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:54:58 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/12 17:50:42 by sscarecr         ###   ########.fr       */
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

    if (!buf->len)
        if ((r = read(file->fd, buf->str, BUFF_SIZE)) <= 0)
            return (r);
        else
            buf->len = r;
//make it iterative!!!
    if (!(s = ft_memchr(buf->str, '\n', buf->len)))
    {
        buf->next = (t_buf*)malloc(sizeof(t_buf));
        buf->next->len = 0;
        buf->next->next = NULL;
        if ((r = fillbuf(file, buf->next)) == -1)
            return (-1);
    }
    //printf("%d\n", s ? s - buf->str + 1 : buf->len + r);
    return (s ? s - buf->str + 1: buf->len + r);
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
	t_buf  *t;
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
