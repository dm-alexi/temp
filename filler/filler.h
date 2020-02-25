#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"

typedef struct	s_map
{
	int		w;
	int		h;
	char	*field;
	char	sign;
}				t_map;

void			sys_error(void);
void			error(char *s);
char			get_player(void);
int				get_dim(t_map *map);

#endif
