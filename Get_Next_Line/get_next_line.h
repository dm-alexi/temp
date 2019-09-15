/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:54:58 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/15 15:53:53 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 4

typedef struct s_buf
{
    int len;
    struct s_buf *next;
    char str[BUFF_SIZE];
} t_buf;

typedef struct s_file
{
    int fd;
    struct s_file *next;
    t_buf *buf;
} t_file;

int				get_next_line(const int fd, char **line);

#endif
