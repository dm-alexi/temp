/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 16:30:27 by sscarecr          #+#    #+#             */
/*   Updated: 2020/04/12 16:07:14 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef _WIN32
# include <stdio.h>
#endif
#include <unistd.h>
#include "libft.h"
#include "corewar.h"

void		introduce(t_vm *vm)
{
	unsigned	i;

	ft_printf("Introducing contestants...\n");
	i = 0;
	while (i < vm->num_players)
	{
		ft_printf("* Player %d, weighing %u bytes, \"%s\" (\"%s\") !\n",
		i + 1, vm->players[i].header.prog_size, vm->players[i].header.prog_name,
		vm->players[i].header.comment);
		++i;
	}
}

void		declare_winner(t_vm *vm)
{
	ft_printf("Contestant %u, \"%s\", has won !\n", vm->last_alive,
	vm->players[vm->last_alive - 1].header.prog_name);
}

void		print_operation(t_process *cur, t_byte *argtypes, int *args)
{
	int	i;

	ft_printf("p%5u | %s", cur->num, g_tab[cur->op].name);
	i = -1;
	while (++i < g_tab[cur->op].argnum)
		ft_printf(argtypes[i] == REG_CODE ? " r%d" : " %d", args[i]);
	ft_printf("\n");
}

static char	*addr_conv(int n)
{
	static char	addr[10] = "0x0000 : ";
	t_byte		lb;
	t_byte		rb;

	rb = n % 256;
	lb = n / 256;
	addr[2] = (lb / 16 > 9 ? lb / 16 - 10 + 'a' : lb / 16 + '0');
	addr[3] = (lb % 16 > 9 ? lb % 16 - 10 + 'a' : lb % 16 + '0');
	addr[4] = (rb / 16 > 9 ? rb / 16 - 10 + 'a' : rb / 16 + '0');
	addr[5] = (rb % 16 > 9 ? rb % 16 - 10 + 'a' : rb % 16 + '0');
	return (addr);
}

int			dump(t_vm *vm)
{
	t_byte	*t;
	char	*s;
	char	*str;

	t = vm->arena;
	if (!(str =
	(char*)malloc(3 * MEM_SIZE + 10 * (MEM_SIZE / vm->dump_len + 1))))
		sys_error(NULL);
	s = str;
	while (t - vm->arena < MEM_SIZE)
	{
		if (!((t - vm->arena) % vm->dump_len))
		{
			ft_memcpy(s, addr_conv(t - vm->arena), 9);
			s += 9;
		}
		*s++ = (*t / 16 > 9 ? *t / 16 - 10 + 'a' : *t / 16 + '0');
		*s++ = (*t % 16 > 9 ? *t % 16 - 10 + 'a' : *t % 16 + '0');
		*s++ = ' ';
		if (!((++t - vm->arena) % vm->dump_len) || t - vm->arena == MEM_SIZE)
			*s++ = '\n';
	}
	write(STDOUT_FILENO, str, s - str);
	free(str);
	return (0);
}
