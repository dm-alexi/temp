#include "pushswap.h"
#include "libft/libft.h"

static void		i_swap(t_node **a, t_node **b, char c)
{
	if (c != 'a' && c != 'b' && c != 's')
		error();
	if (c == 'a' || c == 's')
		swap(*a);
	if (c == 'b' || c == 's')
		swap(*b);
}

static void		i_push(t_node **a, t_node **b, char c)
{
	if (c == 'a')
		add(a, pop(b));
	else if (c == 'b')
		add(b, pop(a));
	else
		error();
}

static void		i_rot(t_node **a, t_node **b, char c, int rev)
{
	if (c != 'a' && c != 'b' && c != 's')
		error();
	if (c == 'a' || c == 's')
		*a = rev ? (*a)->u : (*a)->d;
	if (c == 'b' || c == 's')
		*b = rev ? (*b)->u : (*b)->d;
}

char	*exec(t_node **a, t_node **b, char *s)
{
	int		len;

	len = ft_strlen(s);
	if (len == 2 && s[0] == 's')
		i_swap(a, b, s[1]);
	else if (len == 2 && s[0] == 'p')
		i_push(a, b, s[1]);
	else if (len == 2 && s[0] == 'r')
		i_rot(a, b, s[1], 0);
	else if (len == 3 && s[0] == 'r' && s[1] == 'r')
		i_rot(a, b, s[2], 1);
	return (s);
}

int				get_com(int fd, t_node **a, t_node **b)
{
	int		r;
	int		len;
	char	*s;

	if ((r = get_next_line(fd, &s)) < 0)
		a_error("Input error.\n");
	if (!r)
		return (0);
	len = ft_strlen(s);
	if (len == 2 && s[0] == 's')
		i_swap(a, b, s[1]);
	else if (len == 2 && s[0] == 'p')
		i_push(a, b, s[1]);
	else if (len == 2 && s[0] == 'r')
		i_rot(a, b, s[1], 0);
	else if (len == 3 && s[0] == 'r' && s[1] == 'r')
		i_rot(a, b, s[2], 1);
	else
		error();
	free(s);
	return (1);
}

