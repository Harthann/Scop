#include "matrix.h"

t_vector	add_vector(t_vector a, t_vector b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return (a);
}

t_vector	sub_vector(t_vector a, t_vector b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return (a);
}

t_vector	scale_vector(t_vector a, float x)
{
	a.x *= x;
	a.y *= x;
	a.z *= x;
	return (a);
}

t_vector	norm_vector(t_vector a)
{
	float len;

	len = sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
	a.x /= len;
	a.y /= len;
	a.z /= len;
	return (a);
}


t_vector	cross_product(t_vector a, t_vector b)
{
	t_vector c;

	c.x = a.y * b.z - a.z * b.y;
	c.y = a.z * b.x - a.x * b.z;
	c.z = a.x * b.y - a.y * b.x;
	return (c);
}