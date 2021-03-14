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
		printf("v %f %f %f\n",
		datas.vertex[datas.index[i]].x, datas.vertex[datas.index[i]].y, datas.vertex[datas.index[i]].z);
		printf("v %f %f %f\n",
		datas.vertex[datas.index[i+1]].x, datas.vertex[datas.index[i+1]].y, datas.vertex[datas.index[i+1]].z);
		printf("v %f %f %f\n",
		datas.vertex[datas.index[i+2]].x, datas.vertex[datas.index[i+2]].y, datas.vertex[datas.index[i+2]].z);
		i+=3;
	}
}