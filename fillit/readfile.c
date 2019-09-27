#include <unistd.h>
#include <fcntl.h>
#include "fillit.h"

int		moveupleft(int n)
{
	static const int	legal[19] = {15, 23, 39, 51, 54, 71, 99, 113, 114, 116,
	275, 305, 306, 547, 561, 562, 785, 802, 4369};
	int					i;

	while (!(n & 15))
		n >>= 4;
	while (!(n & 4369))
		n >>= 1;
	i = 0;
	while (i < 19)
		if (n == legal[i++])
			return (n);
	return (-1);
}

int     get_figure(int fd)
{
    char    s[21];
    int     r;
    int     i;
    int     res;
/*
    if ((r = read(fd, s, 21)) < 20)
		return (r ? -1 : 0);
*/
	//test
	ft_strncpy(s, "###.\n..#.\n....\n....\n\n", 20);
	//ft_strncpy(s, "##..\n#...\n#...\n....\n\n", 20);
	//ft_strncpy(s, "....\n####\n....\n....\n\n", 20);
	r = 20;

    res = 0;
    i = 0;
    while (i < r)
    {
        if (i % 5 == 4 || i == 20)
        {
            if (s[i] != '\n')
                return (-1);
        }
        else if (s[i] == '#')
            res = res | (1 << (i - i / 5));
        else if (s[i] != '.')
            return (-1);
		++i;
    }
    //printf("ok");
    return (moveupleft(res));
}

int     *get_figures(char *s)
{
    int     fd;
    int     k;
    int     i;
    int     *res;

    if (!(res = (int*)malloc(sizeof(int) * 26)))
        exit(1);
    if ((fd = open(s, 0)) < 0)
        return (NULL);
    i = 0;
    /*while ((k = get_figure(fd)) > 0)
        res[i++] = k;
        */
	res[i++] = get_figure(fd);
	res[i] = 0;
    return (res);
}
