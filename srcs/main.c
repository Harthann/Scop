#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "scop.h"
#define GLEW_STATIC 1

t_all	*singleton()
{
	static t_all *all = NULL;
	if (all)
		return (all);
	all = (t_all*)ft_calloc(sizeof(t_all), 1);
	all->datas.buffer_id = ft_calloc(sizeof(unsigned int), 1);
	all->datas.index_id = ft_calloc(sizeof(unsigned int), 1);
	return all;
}

void	print_vertices_normal(t_object datas)
{
	t_vector normal;
	for (int i = 0; i < datas.index_count; i += 3)\
	{
		// normal = cross_product(sub_vector(datas.vertex[datas.index[i + 1] * 2 + 2], datas.vertex[datas.index[i] * 2]),
		// 						sub_vector(datas.vertex[datas.index[i + 2] * 2 + ], datas.vertex[datas.index[i + 1] * 2 + 2]));
		printf("Normal is : {%f} {%f} {%f}\n", normal.x, normal.y, normal.z);
	}
}

int main(int ac, char **av)
{
	t_all *all;

	all = singleton();
	if (!all)
		return (1);

	all->window = setWindowContext(all);
	if (!all->window)
	{
		glfwTerminate();
		return (-1);
	}
	if (ac == 2)
		extract_object(av[1], &all->datas);
	print_vertices_normal(all->datas);
	render_loop(all);
	glfwTerminate();
	return 0;
}
