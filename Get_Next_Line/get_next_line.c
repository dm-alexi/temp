/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:54:58 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/15 16:39:16 by sscarecr         ###   ########.fr       */
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
    int len;
    char *s;
	t_buf *t;

    if (!buf->len)
	{
		if ((len = read(file->fd, buf->str, BUFF_SIZE)) <= 0)
			return (len);
        else buf->len = len;
	}
	len = 0;
	t = buf;
//	printf("(%d)\n", len);
    while (!(s = (char*)ft_memchr(t->str, '\n', t->len)))
    {
//		printf("%s", t->str);
		len += t->len;
        t->next = (t_buf*)malloc(sizeof(t_buf));
		t = t->next;
        t->next = NULL;
        if ((t->len = read(file->fd, t->str, BUFF_SIZE)) == -1)
            return (-1);
		else if (t->len == 0)
			break;
//		printf("(%d)\n", len);
    }
	if (s)
		len += s - t->str;
//	printf("\n--%d\n", s - t->str);
    return (len + 1);
}

int readbuf(t_file *file, char **line)
{
    char *s;
    t_buf *t;
    t_buf *tmp;
    int len;

	t = file->buf;
    if ((len = fillbuf(file, t)) <= 0)
        return (len);
    if (!(*line = (char*)malloc(len)))
        return (-1);
	s = *line;
	s[len-1] = '\0';
    while ((tmp = t->next))
    {
        ft_memcpy(s, t->str, t->len);
        s += t->len;
        len -= t->len;
        free(t);
        t = tmp;
    }
    ft_memcpy(s, t->str, len - 1);
//    *(s + len - 1) = '\0';
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

    if (fd < 0)
		return (-1);
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
