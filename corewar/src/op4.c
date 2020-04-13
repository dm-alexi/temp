/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op4.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 16:29:59 by sscarecr          #+#    #+#             */
/*   Updated: 2020/04/13 18:58:39 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

void	aff(t_process *t, t_vm *vm, t_byte *argtypes, int *args)
{
	(void)argtypes;
	ft_printf("Aff : %c\n", (char)t->reg[args[0] - 1]);
	if (vm->verbosity & OPERATIONS)
		ft_printf("r%d\n", args[0]);
}
