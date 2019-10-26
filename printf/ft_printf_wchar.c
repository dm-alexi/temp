/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_wchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:46:22 by sscarecr          #+#    #+#             */
/*   Updated: 2019/10/26 16:47:36 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

void printbin(void *p, int n);

void	pw()
{
	wchar_t		c = 0x00e282ac;
	int n;
	char s[4] = {0};
	printbin(&c, 1);
	n = write(1, "\xe2\x82\xac", 3);
	printf("\n%d\n", n);
	n = printf("\xe2\x82\xac");
	printf("\n%d\n", n);
	s[0] = c & 0x000000ff;
	s[1] = (c & 0x0000ff00) >> 8;
	s[2] = (c & 0x00ff0000) >> 16;
	s[3] = (c & 0xff000000) >> 24;
	//write(1, s, 3);
	printbin("\xe2\x82\xac", 1);
	printf("---\n");
	printbin(s, 1);
}