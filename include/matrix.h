#ifndef MATRIX_H
#define MATRIX_H

typedef struct s_mat
{
	float r1[4];
	float r2[4];
	float r3[4];
	float r4[4];
} t_mat;

#define M_IDENTITY  1
#define M_ROTATE	2
#define M_TRANSLATE 3
#define M_SCALE	 4
#define M_ORTHO	 5

t_mat   createMatrice(int type, float *v, float angle);
void	printMatrices(t_mat mat);
t_mat	multMat(float m1[16], float m2[16]);

#endif