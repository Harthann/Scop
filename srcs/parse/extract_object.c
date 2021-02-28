#include "scop.h"

#include <fcntl.h>
#include <stdio.h>

void	add_index(const char* line, uint **index, int *index_count)
{
	int	 offset;
	int	 i;

	*index = ft_ralloc(*index, *index_count * sizeof(uint),
						sizeof(uint) * (3 + *index_count));
	offset = 2;
	i = *index_count - 1;
	*index_count += 3;
	while (++i < *index_count)
	{
		(*index)[i] = ft_atoi(line + offset) - 1;
		while (line[offset] && line[offset] >= '0' && line[offset] <= '9')
			++offset;
		if (line[offset] != '\0' && line[offset] != ' ')
			error("Object extraction error\n");
		++offset;
	}
}

void	add_vertex(const char* line, float **vertex, int *vertex_count)
{
	int	 offset;
	int	 err;
	int	 i;

	*vertex = ft_ralloc(*vertex, *vertex_count * sizeof(float),
							sizeof(float) * (4 + *vertex_count));
	i = *vertex_count - 1;
	offset = 2;
	err = 0;
	*vertex_count += 3;
	while (++i < *vertex_count)
	{
		(*vertex)[i] = ft_strfloat(line, &offset, &err);
		if (line[offset])
			++offset;
		else
			break ;
		if (err)
			error("Object extraction error\n");
	}
	(*vertex)[*vertex_count] = 1;
	++*vertex_count;
}

void	extract_object(const char* path, t_object *obj)
{
	int	 fd;
	int	 ret;
	char	*line;

	ret = 1;
	fd = open(path, O_RDONLY);
	if (fd > 0)
	{
		while (ret)
		{
			line = NULL;
			ret = get_next_line(fd, &line);
			if (ret == 0)
				break ;
			if (line && line[0] == 'v')
				add_vertex(line, &obj->vertex, &obj->vertex_count);
			if (line && line[0] == 'f')
				add_index(line, &obj->index, &obj->index_count);
			free(line);
			// else if (!ft_strncmp(line, "mtllib", 6))
			//	 obj->mtl_link = line;
		}
	}
}
