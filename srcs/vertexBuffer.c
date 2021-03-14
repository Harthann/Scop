#include "scop.h"
#include <stdio.h>

void	generate_buffer(t_object datas, int size, unsigned int *buffer)
{
	glGenBuffers(1, buffer);
	glBindBuffer(GL_ARRAY_BUFFER, *buffer);
	glBufferData(GL_ARRAY_BUFFER, datas.vertex_count * sizeof(t_vector),
				datas.vertex,  GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, size, GL_FLOAT, GL_FALSE, size * 2 * sizeof(float), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, size, GL_FLOAT, GL_FALSE, size * 2 * sizeof(float), sizeof(float) * size);
	printf("Generate buffer : {%d}\nVertext count : {%d}\nConsider size : {%d}\n", *buffer, datas.vertex_count, size);
}

void	generate_index(t_object datas, unsigned int *ibo)
{
	glGenBuffers(1, ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, datas.index_count * sizeof(unsigned int),
				datas.index,  GL_STATIC_DRAW);
}
