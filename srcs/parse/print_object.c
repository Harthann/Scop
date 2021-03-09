#include "scop.h"
#include <stdio.h>
void	print_object(t_object datas)
{
	int i;

	i = 0;
	while (i < datas.vertex_count)
	{
		printf("v %f %f %f\n",
		datas.vertex[i].x, datas.vertex[i].y, datas.vertex[i].z);
		i++;
	}
	i = 0;
	while (i < datas.index_count)
	{
		printf("f %u %u %u\n",
		datas.index[i] + 1, datas.index[i + 1] + 1, datas.index[i + 2] + 1);
		i+=3;
	}
}