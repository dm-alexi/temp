#include "lem-in.h"

t_list	*new_node(char *line, t_command com)
{
	char	*s;
	t_node	node;

	if (!(s = ft_strrchr(line, ' ')))
        error();
    node.y = ft_atoi(s);
    *s = '\0';
    if (!(s = ft_strrchr(line, ' ')))
        error();
	node.x = ft_atoi(s);
	*s = '\0';
    if (!*line)
		error();
	node.name = ft_strdup(line);
	node.nodes = NULL;
	node.distance = com;
	free(line);
	return (ft_lstnew(&node, sizeof(t_node)));
}
