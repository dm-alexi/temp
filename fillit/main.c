#include <stdio.h>
#include <stdlib.h>
#include "fillit.h"

int main()
{
	int		sq;
	int		n;
	col		*col_arr;
	int		**rows;

	n = 3;
	sq = 4;
    col_arr = make_columns(n, sq);
    /*
    for (int i = 0; i <= n + sq * sq; ++i)
		printf("%s ", col_arr[i].name);*/
	rows = get_rows(1, 7, sq);
	add_row(col_arr, rows, n);
	clear_rows(rows);
	rows = get_rows(2, 14, sq);
	add_row(col_arr, rows, n);
	clear_rows(rows);
	rows = get_rows(3, 9, sq);
	add_row(col_arr, rows, n);
	clear_rows(rows);
/*
	for (int **r = rows; *r; ++r)
	{
		for (int i = 0; i < 5; ++i)
			printf("%3d ", (*r)[i]);
		printf("\n");
	}*/


    return 0;
}
