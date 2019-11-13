/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:52:15 by sscarecr          #+#    #+#             */
/*   Updated: 2019/11/12 22:19:10 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "pushswap.h"

int		main(int ac, char **av)
{
	int			n;
	int			fd;
	t_flags		flags;
	t_stack		t;

	if (ac > 1 && (n = get_flags(ac, av, &flags)) > 0)
	{
		ft_bzero(&t, sizeof(t));
		t.a = get_args(n, av + ac - n, &n);
		t.a_count = n;
		//show_stacks(&t);
		if ((fd = (flags.filename ? open(flags.filename, O_RDONLY) : 0)) < 0)
			file_error(flags.filename);
		while (get_com(fd, &t))
			;
		write(1, sorted(t.a) && !t.b_count ? "OK\n" : "KO\n", 3);
		//show_stacks(&t);
		clear_stacks(&t);
	}
	return (0);
}
