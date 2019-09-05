#include <stdlib.h>
#include "libft.h"

static char	*ft_slow_strstr(const char *s1, const char *s2, size_t n)
{
	int		i;
	char	*s;

	s = (char*)s1;
	while ((size_t)(s - s1) <= n)
	{
		i = 0;
		while (*(s2 + i) && *(s2 + i) == *(s + i))
			++i;
		if (*(s2 + i) == '\0')
			return (s);
		++s;
	}
	return (0);
}

static size_t *prefix(const char *s, size_t n)
{
    size_t	*p;
    size_t	i;
    size_t	k;

    if (!(p = (size_t*)malloc(sizeof(size_t) * n)))
		return (NULL);
    i = 1;
    p[0] = 0;
    while (i < n)
    {
		k = p[i - 1];
		while (k > 0 && s[i] != s[k])
			k = p[k - 1];
		if (s[i] == s[k])
			++k;
		p[i++] = k;
    }
    return (p);
}

char    *ft_strstr(const char *s1, const char *s2)
{
    size_t	*p;
    size_t	i;
	size_t	j;
	size_t	n1;
	size_t	n2;

	n1 = ft_strlen(s1);
	n2 = ft_strlen(s2);
	if (n2 > n1)
		return (NULL);
	if (!(p = prefix(s2, n2)))
	return (ft_slow_strstr(s1, s2, n1 - n2));
		i = 0;
	j = 0;
	while (i < n1)
	{
		while (j > 0 && s1[i] != s2[j])
			j = p[j - 1];
		if (s1[i] == s2[j])
			++j;
		if (j == n2)
			return ((char*)s1 + i - n2 + 1);
		++i;
	}
    return (NULL);
}
