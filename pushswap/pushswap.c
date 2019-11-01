#include "pushswap.h"

static int	i_swap(t_node **a, t_node **b, char c)
{
	if (c != 'a' && c != 'b' && c != 's')
		error();
	if (c == 'a' || c == 's')
		swap(*a);
	if (c == 'b' || c == 's')
		swap(*b);
	return (1);
}

static int	i_push(t_node **a, t_node **b, char c)
{
	if (c == 'a')
		push(a, b);
	else if (c == 'b')
		push(b, a);
	else
		error();
	return (1);
}

static int	i_rot(t_node **a, t_node **b, char c, int rev)
{
	if (c != 'a' && c != 'b' && c != 's')
		error();
	if (c == 'a' || c == 's')
		*a = rev ? (*a)->u : (*a)->d;
	if (c == 'b' || c == 's')
		*b = rev ? (*b)->u : (*b)->d;
	return (1);
}

int			get_com(int fd, t_node **a, t_node **b)
{
	int		r;
	char	s[4];

	s[3] = 0;
	if ((r = read(fd, b, 3)) < 0)
		a_error("Input error.\n");
	if (!r)
		return (0);
	if (r < 3 || (s[2] != '\n' && (read(fd, s + 3, 1) < 1 || s[3] !='\n')))
		return (-1);
	if (s[0] == 's' && s[2] == '\n')
		return (i_swap(a, b, s[1]));
	if (s[0] == 'p' && s[2] == '\n')
		return (i_push(a, b, s[1]));
	if (s[0] == 'r' && s[2] == '\n')
		return (i_rot(a, b, s[1], 0));
	if (s[0] == 'r' && s[1] == 'r' && s[3] == '\n')
		return (i_rot(a, b, s[2], 1));
	return (-1);
}

