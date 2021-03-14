#ifndef MATRIX_H
#define MATRIX_H

typedef struct s_mat
{
	float r1[4];
	float r2[4];
	float r3[4];
	float r4[4];
} t_mat;

typedef struct s_vector
{
	float x;
	float y;
	float z;
} t_vector;


#define M_IDENTITY  1
#define M_ROTATE	2
#define M_TRANSLATE 3
#define M_SCALE	 4
#define M_ORTHO	 5

t_mat   createMatrice(int type, float *v, float angle);
void	printMatrices(t_mat mat);
t_mat	multMat(float m1[16], float m2[16]);
t_mat	scaleMat(float scalar, t_mat m);

t_vector	cross_product(t_vector a, t_vector b);
t_vector	norm_vector(t_vector a);
t_vector	scale_vector(t_vector a, float x);
t_vector	sub_vector(t_vector a, t_vector b);
t_vector	add_vector(t_vector a, t_vector b);

#endif