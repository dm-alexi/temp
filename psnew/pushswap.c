/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:46:02 by sscarecr          #+#    #+#             */
/*   Updated: 2019/11/12 22:17:27 by sscarecr         ###   ########.fr       */
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
		if ((fd = (flags.filename ?
		open(flags.filename, O_WRONLY | O_CREAT) : 1)) < 0)
			file_error(flags.filename);
		sort(&t);
		//print_log(&t);
		//show_stacks(&t);
		print_result(&t, fd);
		clear_stacks(&t);
		if (fd > 0)
			close(fd);
	}
	return (0);
}
