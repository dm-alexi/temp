/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:22:25 by sscarecr          #+#    #+#             */
/*   Updated: 2019/09/25 19:22:28 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int		main(int ac, char **av)
{
	int		sq;
	int		n;
	int     figures[] = {4369, 15, 71, 54, 51, 99, 547, 39, 4369, 15, 71, 54, 51, 99, 547, 39, 39};
	col		*col_arr;
	node	**res;

	n = 17;
	sq = ft_isqrt(4 * n);
    if (sq * sq < 4 * n)
        ++sq;
    col_arr = make_matrix(figures, n, sq);
    printf("matrix built\n");
	while (!(res = solve(col_arr, n)))
    {
        del_columns(col_arr, n + sq * sq);
        col_arr = make_matrix(figures, n, ++sq);
        printf("Next try: %d x %d\n", sq);
    }
	print_result(res, n, sq);
    del_columns(col_arr, n + sq * sq);
	/*
	int *t = get_figures("test1.txt");
	if (t)
		while (*t)
			printf("%d ", *t++);*/
/*
	FILE *f = fopen("test4", "w");
	fprintf(f, "##..\n.#..\n.#..\n....\n");
*/
    return 0;
}
