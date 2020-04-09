/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 16:22:33 by sscarecr          #+#    #+#             */
/*   Updated: 2020/04/09 17:55:58 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

void	init_arena(t_vm *vm)
{
	unsigned	i;
	int			step;

	step = MEM_SIZE / vm->num_players;
	i = 0;
	while (i < vm->num_players)
	{
		ft_memcpy(vm->arena + i * step, vm->players[i].code,
		vm->players[i].header.prog_size);
		vm->start = new_process(vm->start, ++vm->num_process,
		vm->players[i].num, i * step);
		vm->start->reg[0] = -(i + 1);
		++i;
	}
}

int		read_dir(int start, t_byte *arena)
{
	char	s[DIR_SIZE];
	int		i;

	if (start < 0)
		start += MEM_SIZE;
	start %= MEM_SIZE;
	if (start + DIR_SIZE < MEM_SIZE)
		return (*((int*)(arena + start)));
	i = -1;
	while (++i < DIR_SIZE)
		s[i] = arena[(start + i) % MEM_SIZE];
	return (*((int*)s));
}

int		read_ind(int start, t_byte *arena)
{
	char	s[IND_SIZE];
	int		i;

	if (start < 0)
		start += MEM_SIZE;
	start %= MEM_SIZE;
	if (start + IND_SIZE < MEM_SIZE)
		return (*((short*)(arena + start)));
	i = -1;
	while (++i < IND_SIZE)
		s[i] = arena[(start + i) % MEM_SIZE];
	return (*((short*)s));
}

void	write_bytes(int n, int start, t_byte *arena)
{
	t_byte	*s;
	int		i;

	if (start < 0)
		start += MEM_SIZE;
	start %= MEM_SIZE;
	if (start + DIR_SIZE < MEM_SIZE)
		*(int*)(arena + start) = n;
	else
	{
		s = (t_byte*)&n;
		i = -1;
		while (++i < REG_SIZE)
			arena[(start + i) % MEM_SIZE] = s[i];
	}
}
