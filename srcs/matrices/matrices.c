#include "matrix.h"

#include <math.h>

#define TO_DEGREE 0.01745329251f

static t_mat   identityMatrice(void)
{
	t_mat   mat;

	mat.r1[0] = 1;
	mat.r1[1] = 0;
	mat.r1[2] = 0;
	mat.r1[3] = 0;

	mat.r2[0] = 0;
	mat.r2[1] = 1;
	mat.r2[2] = 0;
	mat.r2[3] = 0;
	
	mat.r3[0] = 0;
	mat.r3[1] = 0;
	mat.r3[2] = 1;
	mat.r3[3] = 0;
	
	mat.r4[0] = 0;
	mat.r4[1] = 0;
	mat.r4[2] = 0;
	mat.r4[3] = 1;
	return (mat);
}

static t_mat   translationMatrice(float t[3])
{
	t_mat   mat;

	mat = identityMatrice();
	if (t)
	{
		mat.r4[0] = t[0];
		mat.r4[1] = t[1];
		mat.r4[2] = t[2];
	}
	else
	{
		mat.r4[0] = 1.0f;
		mat.r4[1] = 1.0f;
		mat.r4[2] = 1.0f;
	}
	return (mat);
}

static t_mat   scaleMatrice(float t[3])
{
	t_mat   mat;

	mat = identityMatrice();
	if (t)
	{
		mat.r1[0] = t[0];
		mat.r2[1] = t[1];
		mat.r3[2] = t[2];
	}
	else
	{
		mat.r4[0] = 1.0f;
		mat.r4[1] = 1.0f;
		mat.r4[2] = 1.0f;
	}
	return (mat);
}

static t_mat   rotationMatrice(float t[3], float angle)
{
	t_mat mat;
	float ca;	// cos(angle)
	float sa;	// sin(angle)
	float omca;	// 1 - cos(angle)

	mat = identityMatrice();
	ca = cos(angle * TO_DEGREE);
	sa = sin(angle * TO_DEGREE);
	omca = 1.0f - ca;

	mat.r1[0] = t[0] * t[0] * omca + ca;
	mat.r1[1] = t[0] * t[1] * omca + t[2] * sa;
	mat.r1[2] = t[0] * t[2] * omca - t[1] * sa;
	
	mat.r2[0] = t[0] * t[1] * omca - t[2] * sa;
	mat.r2[1] = t[1] * t[1] * omca + ca;
	mat.r2[2] = t[1] * t[2] * omca + t[0] * sa;

	mat.r3[0] = t[0] * t[2] * omca + t[1] * sa;
	mat.r3[1] = t[1] * t[2] * omca - t[0] * sa;
	mat.r3[2] = t[2] * t[2] * omca + ca;
	return (mat);
}

t_mat   createMatrice(int type, float v[3], float angle)
{
	if (type == M_IDENTITY)
		return (identityMatrice());
	if (type == M_TRANSLATE)
		return (translationMatrice(v));
	if (type == M_SCALE)
		return (scaleMatrice(v));
	if (type == M_ROTATE)
		return (rotationMatrice(v, angle));
}

void	printMatrices(t_mat mat)
{
	printf ("%f %f %f %f\n", mat.r1[0], mat.r2[0], mat.r3[0], mat.r4[0]);
	printf ("%f %f %f %f\n", mat.r1[1], mat.r2[1], mat.r3[1], mat.r4[1]);
	printf ("%f %f %f %f\n", mat.r1[2], mat.r2[2], mat.r3[2], mat.r4[2]);
	printf ("%f %f %f %f\n", mat.r1[3], mat.r2[3], mat.r3[3], mat.r4[3]);


}