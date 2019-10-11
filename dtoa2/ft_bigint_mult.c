#include "ft_bigint.h"

void	ft_bigint_mult_int(t_bigint *res, const t_bigint *a, const uint32_t b)
{
    int			i;
    uint64_t	product;
    uint64_t	carry;

    i = 0;
    carry = 0;
    res->len = 1;
    res->arr[0] = 0;
    if (b)
	{
		while (i < a->len)
		{
			product = carry + (uint64_t)a->arr[i] * b;
			res->arr[i++] = product % 1000000000;
			carry = product / 1000000000;
		}
		while (carry)
		{
			res->arr[i++] = carry % 1000000000;
			carry /= 1000000000;
		}
		res->len = i;
	}
}

void	ft_bigint_mult(t_bigint *res, const t_bigint *a, const t_bigint *b)
{
    int			i;
    int			j;
    t_bigint	tmp;

    if (a->len <= b->len)
    {
    	i = 0;
		res->len = 1;
		res->arr[0] = 0;
		while (i < a->len)
		{
			ft_bigint_mult_int(&tmp, b, a->arr[i]);
			j = tmp.len;
			while (--j >= 0)
				tmp.arr[j + i] = tmp.arr[j];
			while (++j < i)
				tmp.arr[j] = 0;
			tmp.len += i;
			ft_bigint_sum(res, res, &tmp);
			++i;
		}
    }
    else
		ft_bigint_mult(res, b, a);
}
