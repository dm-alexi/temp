#include <unistd.h>
#include "pushswap.h"

void	add_prev(t_list **last, char *s, size_t size)
{
	t_list	*t;

	if (!(t = ft_lstnew(s, size)))
		a_error("Error: memory allocation failed.\n");
	t->next = *last;
	*last = t;
}

void	print_list(int fd, t_list *t)
{
	while (t)
	{
		write(fd, t->content, t->content_size);
		write(fd, "\n", 1);
		t = t->next;
	}
}
