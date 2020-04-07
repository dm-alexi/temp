/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 16:30:27 by sscarecr          #+#    #+#             */
/*   Updated: 2020/04/08 01:13:25 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef _WIN32
# include <stdio.h>
#endif
#include <unistd.h>
#include "libft.h"
#include "corewar.h"

void	introduce(t_vm *vm)
{
	unsigned	i;

	ft_printf("Introducing contestants...\n");
	i = 0;
	while (i < vm->num_players)
	{
		ft_printf("* Player %d, weighing %u t_bytes, \"%s\" (\"%s\") !\n",
		i + 1, vm->players[i].header.prog_size, vm->players[i].header.prog_name,
		vm->players[i].header.comment);
		++i;
	}
}

void	declare_alive(t_vm *vm, unsigned player_num)
{
	ft_printf("A process shows that player %u (%s) is alive", player_num,
	vm->players[player_num - 1].header.prog_name);
}

void	declare_winner(t_vm *vm)
{
	ft_printf("Player %u (%s) won\n", vm->last_alive,
	vm->players[vm->last_alive - 1].header.prog_name);
}

void	dump(t_vm *vm)
{
	t_byte	*t;
	char	*s;
	char	*str;
	int		size;

	t = vm->arena;
	size = MEM_SIZE * 2 + MEM_SIZE / vm->dump_len +
	(MEM_SIZE % vm->dump_len > 0);
	if (!(str = (char*)malloc(size)))
		sys_error(NULL);
	s = str;
	while (t - vm->arena < MEM_SIZE)
	{
		*s++ = (*t / 16 > 9 ? *t / 16 - 10 + 'a' : *t / 16 + '0');
		*s++ = (*t % 16 > 9 ? *t / 16 - 10 + 'a' : *t / 16 + '0');
		if (!((++t - vm->arena) % vm->dump_len))
			*s++ = '\n';
	}
	if (MEM_SIZE % vm->dump_len > 0)
		*s = '\n';
	write(STDOUT_FILENO, str, size);
}
