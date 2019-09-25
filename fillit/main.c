#include <stdio.h>
#include <stdlib.h>
#include "fillit.h"

int main()
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
	rows = get_rows(1, n, 7, sq);
	add_row(col_arr, rows);
	clear_rows(rows);
	rows = get_rows(2, n, 14, sq);
	add_row(col_arr, rows);
	clear_rows(rows);
	rows = get_rows(3, n, 9, sq);
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
	for (int i = 0; i < n; ++i)
	{
		for (node *j = res[i]->r; j != res[i]; j = j->r)
			printf("%3d ", j->column - col_arr);
		printf("\n");
	}


    return 0;
}
