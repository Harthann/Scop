#include "scop.h"

t_mat	createProjection(void)
{
	t_mat proj;
	float n = 2.0f;
	float f = -100.0f;

	proj.r1[0] = 1 / (tan(55.0f * RATIO));
	proj.r1[1] = 0;
	proj.r1[2] = 0;
	proj.r1[3] = 0;

	proj.r2[0] = 0;
	proj.r2[1] = proj.r1[0];
	proj.r2[2] = 0;
	proj.r2[3] = 0;

	proj.r3[0] = 0;
	proj.r3[1] = 0;
	proj.r3[2] = -(f / (f - n));
	proj.r3[3] = -(f * n / (f - n));

	proj.r4[0] = 0;
	proj.r4[1] = 0;
	proj.r4[2] = -1;
	proj.r4[3] = 0;
	proj = createMatrice(M_IDENTITY, NULL, 0);
	return (proj);
}

t_mat	createView(void)
{
	t_mat view;
	t_vector pos = {.x = 0, .y = 0, .z = 2};
	t_vector lookat = {.x = 0, .y = 0, .z = -1};
	t_vector up = {.x = 0, .y = 1, .z = 0};
	t_vector tmp;
	t_vector tmp2;

	view = createMatrice(M_IDENTITY, NULL, 0);
	tmp = norm_vector(sub_vector(pos, lookat));
	view.r3[0] = tmp.x; view.r3[1] = tmp.y; view.r3[2] = tmp.z;
	tmp2 = cross_product(up, tmp);
	view.r1[0] = tmp2.x; view.r1[1] = tmp2.y; view.r1[2] = tmp2.z;
	tmp = cross_product(tmp, tmp2);
	view.r2[0] = tmp.x; view.r2[1] = tmp.y; view.r2[2] = tmp.z;
	view = multMat(&view.r1[0], &createMatrice(M_TRANSLATE, &pos.x, 0).r1[0]);
	view = createMatrice(M_IDENTITY, NULL, 0);
	return (view);
}