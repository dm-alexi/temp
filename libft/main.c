#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include "libft.h"

void plusone(char *s) { ++*s; }
void plusodd(unsigned int i, char *s) { *s += i % 2; }

int main()
{
	char *dest = (char *)malloc(sizeof(*dest) * 15);
	memset(dest, 'r', 14);
	int k = ft_strlcat(dest, "lorem ipsum dolor sit amet", 15);
	int l = strlcat(dest, "lorem ipsum dolor sit amet", 15);
	printf("%d %d", k , l);
    return 0;
}
