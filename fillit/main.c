/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:22:25 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/30 23:05:37 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fillit.h"

int		main(int ac, char **av)
{
	int		sq;
	int		n;
	int		*figures;
	t_col	*col_arr;
	t_node	**res;

	if (ac != 2)
		ft_putstr("usage: fillit source_file\n");
	else if ((figures = get_figures(av[1], &n)))
	{
		sq = ft_isqrt(4 * n);
		if (sq * sq < 4 * n)
			++sq;
		col_arr = make_matrix(figures, n, sq);
		while (!(res = solve(col_arr, n)))
		{
			del_columns(col_arr, n + sq * sq);
			col_arr = make_matrix(figures, n, ++sq);
		}
		print_result(res, n, sq);
		del_columns(col_arr, n + sq * sq);
	}
	else
		ft_putstr("error\n");
	return (0);
}
