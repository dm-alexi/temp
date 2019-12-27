/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:27:12 by sscarecr          #+#    #+#             */
/*   Updated: 2019/12/27 21:27:13 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
