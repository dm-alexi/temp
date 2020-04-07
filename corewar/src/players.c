/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 16:30:35 by sscarecr          #+#    #+#             */
/*   Updated: 2020/04/08 01:25:39 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "corewar.h"

void	get_players(t_vm *vm, char **files)
{
	unsigned	i;
	int			fd;
	int			r;

	vm->players = (t_player*)malloc(sizeof(t_player) * vm->num_players);
	i = -1;
	while (++i < vm->num_players)
	{
		if ((fd = open(files[i], O_RDONLY)) < 0 ||
		(r = read(fd, &(vm->players + i)->header, sizeof(t_header))) < 0)
			sys_error(files[i]);
		if (r < (int)sizeof(t_header))
			error_ext("invalid file ", files[i]);
		if (vm->players[i].header.prog_size > CHAMP_MAX_SIZE)
			error_ext(files[i], " code size exceeds maximum value.");
		if (!(vm->players[i].code =
		(t_byte*)malloc(vm->players[i].header.prog_size)))
			sys_error(NULL);
		if ((r = read(fd, (vm->players + i)->code,
		vm->players[i].header.prog_size)) <
		(int)vm->players[i].header.prog_size)
			r < 0 ? sys_error(files[i]) : error_ext("invalid file ", files[i]);
		vm->players[i].num = i + 1;
		close(fd);
	}
}
