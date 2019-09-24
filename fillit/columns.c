#include "fillit.h"
#include "libft/libft.h"

static void set_name(char *s, int sq, int pos)
{
	s[0] = pos / sq / 10 + '0';
	s[1] = pos / sq % 10 + '1';
	s[2] = pos % sq / 10 + '0';
	s[3] = pos % sq % 10 + '1';
}

col		*make_columns(int n, int sq)
{
	col		*arr;
	int		i;

	if (!(arr = (col*)ft_memalloc(sizeof(col) * (sq * sq + n + 1))))
		return (NULL);
	i = 0;
    while (++i <= n)
	{
		arr[i].name[0] = 'A' + i - 1;
        arr[i].head.u = &(arr[i].head);
        arr[i].head.d = &(arr[i].head);
        arr[i].prev = arr + i - 1;
        arr[i - 1].next = arr + i;
	}
	arr[--i].next = arr;
	arr[0].prev = arr + i;
	while (++i <= n + sq * sq)
	{
		arr[i].head.u = &(arr[i].head);
        arr[i].head.d = &(arr[i].head);
        arr[i].prev = arr + i;
        arr[i].next = arr + i;
        set_name(arr[i].name, sq, i - n - 1);
	}
	return (arr);
}
