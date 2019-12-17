#include <math.h>
#include "fdf.h"

double *mult(double a[4][4], double b[4][4], double c[4][4])
{
	int		i;
	int		j;
	int		k;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			c[i][j] = 0.0;
            k = -1;
            while (++k < 4)
				c[i][j] += a[i][k] * b[k][j];
		}
	}
	return ((double*)c);
}

t_vertex *transform(t_vertex *v, double m[4][4], t_vertex *out)
{
	out->x = v->x * m[0][0] + v->y * m[0][1] + v->z * m[0][2] + v->w * m[0][3];
	out->y = v->x * m[1][0] + v->y * m[1][1] + v->z * m[1][2] + v->w * m[1][3];
	out->z = v->x * m[2][0] + v->y * m[2][1] + v->z * m[2][2] + v->w * m[2][3];
	out->w = v->x * m[3][0] + v->y * m[3][1] + v->z * m[3][2] + v->w * m[3][3];
	out->color = v->color;
	return (out);
}

double *projection(double fov, double ratio, double near, double far)
{
	static double m[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0};

	m[0] = 1.0 / (tan(fov / 2) * ratio);
	m[5] = 1.0 / tan(fov / 2);
	m[10] = (near + far) / (near - far);
	m[11] = 2 * far * near / (near - far);
	return (m);
}
