/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op4.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 16:29:59 by sscarecr          #+#    #+#             */
/*   Updated: 2020/04/10 15:54:04 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef _WIN32
# include <stdio.h>
#endif
#include <unistd.h>
#include "corewar.h"

void	aff(t_process *t, t_vm *vm, int *args)
{
	static char	s[] = "Aff :  \n";

	(void)vm;
	s[6] = t->reg[args[0] - 1];
	write(STDOUT_FILENO, s, 8);
}
