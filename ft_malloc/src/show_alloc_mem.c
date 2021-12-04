/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:14:52 by sscarecr          #+#    #+#             */
/*   Updated: 2021/10/24 18:15:41 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>
#include "ft_malloc.c"

#define ADDRESS_LENGTH	(sizeof(size_t) + 2)
#define SIZE_LENGTH		10

static void print_address(uintptr_t ptr)
{
	char 		str[ADDRESS_LENGTH] = "0x";
	char 		c;

	for (int i = ADDRESS_LENGTH - 1; i > 1; --i, ptr /= 16)
	{
		c = ptr % 16;
		str[i] = c + (c < 10 ? '0' : 'A' - 10);
	}
	write(STDOUT_FILENO, str, ADDRESS_LENGTH);
}

static void	print_size(int size)
{
	char	str[SIZE_LENGTH];
	int		i;

	for (i = SIZE_LENGTH - 1; size; --i, size /= 10)
		str[i] = size % 10 + '0';
	write(STDOUT_FILENO, str + i + 1, SIZE_LENGTH - i - 1);
	write(STDOUT_FILENO, " bytes\n", 7);
}

static int print_page(t_page *page)
{
	byte	*ptr;
	int		total = 0;
	
	print_address(page);
	write(STDOUT_FILENO, "\n", 1);
	for (t_area *area = (t_area*)((byte*)page + sizeof(t_page)); area; area = area->next)
		if (area->status == OCCUPIED)
		{
			ptr = ((byte*)area + sizeof(t_area));
			print_address(ptr);
			write(STDOUT_FILENO, " - ", 3);
			print_address(ptr + area->size);
			write(STDOUT_FILENO, " : ", 3);
			print_size(area->size);
			total += area->size;
		}
	return total;
}

static int print_big(t_big *big)
{
	byte	*ptr;
	
	print_address(big);
	write(STDOUT_FILENO, "\n", 1);
	ptr = ((byte*)big + sizeof(t_big));
	print_address(ptr);
	write(STDOUT_FILENO, " - ", 3);
	print_address(ptr + big->size);
	write(STDOUT_FILENO, " : ", 3);
	print_size(big->size);
	return big->size;
}

void show_alloc_mem(void)
{
	int	total = 0;

	for (t_page *page = g_pages.tiny; page; page = page->next)
	{
		write(STDOUT_FILENO, "TINY : ", 7);
		total += print_page(page);
	}
	for (t_page *page = g_pages.small; page; page = page->next)
	{
		write(STDOUT_FILENO, "SMALL : ", 8);
		total += print_page(page);
	}
	for (t_big *big = g_pages.big; big; big = big->next) 
	{
		write(STDOUT_FILENO, "LARGE : ", 8);
		total += print_big(big);
	}
	write(STDOUT_FILENO, "Total : ", 8);
	print_size(total);
}