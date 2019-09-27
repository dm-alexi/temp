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
#include <stdlib.h>
#include "fillit.h"

int		main(int ac, char **av)
{
	int		sq;
	int		n;
	col		*col_arr;
	int		**rows;
	node	**res;

	n = 3;
	sq = 4;
    col_arr = make_columns(n, sq);
    /*
    for (int i = 0; i <= n + sq * sq; ++i)
		printf("%s ", col_arr[i].name);*/
	rows = get_rows(1, n, 51, sq);
	add_row(col_arr, rows);
	clear_rows(rows);
	rows = get_rows(2, n, 785, sq);
	add_row(col_arr, rows);
	clear_rows(rows);
	rows = get_rows(3, n, 306, sq);
	add_row(col_arr, rows);
	clear_rows(rows);
	/*
	for (int **r = rows; *r; ++r)
	{
		for (int i = 0; i < 5; ++i)
			printf("%3d ", (*r)[i]);
		printf("\n");
	}*/
	res = solve(col_arr, n);
	/*
	for (int i = 0; i < n; ++i)
	{
		for (node *j = res[i]->r; j != res[i]; j = j->r)
			printf("%3ld ", j->column - col_arr);
		printf("\n");
	}*/
	print_result(res, n, sq, col_arr);

	int *t = get_figures("test1.txt");
	while (*t)
		printf("%d ", *t++);
/*
	FILE *f = fopen("test4", "w");
	fprintf(f, "##..\n.#..\n.#..\n....\n");
*/
    return 0;
}
