#ifndef FDF_H_INCLUDED
# define FDF_H_INCLUDED
# include "libft/libft.h"

typedef struct	s_map
{
	int		length;
	int		width;
	int		height;
	int		**grid;
}				t_map;

int		error(void);


#endif
