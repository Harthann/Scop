#include "matrix.h"

#include "libft.h"

t_mat	multMat(float m1[16], float m2[16])
{
	t_mat ret;
	float *r;
	int i;
	int j;

	i = 0;
	r = &ret.r1[0];
	ft_bzero(r, sizeof(float) * 16);
	while (i < 16)
	{
		j = 0;
		while (j < 4)
		{
			r[i] += m1[i % 4 + 4 * j] * m2[i / 4 * 4 + j];
			++j;
		}
		++i;
	}
	return (ret);
}

t_mat	scaleMat(float scalar, t_mat m)
{
	int i;
	float *mat;

	mat = &m.r1[0];
	i = -1;
	while (++i < 16)
		mat[i] *= scalar;
	return (m);
}