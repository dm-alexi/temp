#include "ft_bigint.h"

int		bigIntCmp(const t_bigInt *a, const t_bigInt *b)
{
	int		i;

	if (a->len != b->len)
		return (a->len - b->len);
	i = a->len - 1;
	while (i >= 0)
	{
		if (a->arr[i] != b->arr[i])
			return (a->arr[i] - b->arr[i]);
		++i;
	}
	return (0);
}

void	bigIntSum(t_bigInt *res, const t_bigInt *a, const t_bigInt *b)
{
	uint64_t	carry;
	uint64_t	sum;
	int			i;

	if (a->len < b->len)
	{
		bigIntSum(res, b, a);
		return;
	}
	carry = 0;
	i = 0;
	while (i < b->len)
	{
		sum = carry + (uint64_t)a->arr[i] + (uint64_t)b->arr[i];
		res->arr[i++] = sum & 0xffffffff;
		carry = sum >> 32;
	}
	while (i < a->len)
	{
		sum = carry + (uint64_t)a->arr[i];
		res->arr[i++] = sum & 0xffffffff;
		carry = sum >> 32;
	}
	res->arr[i] = carry;
	res->len = carry ? i + 1 : i;
}

