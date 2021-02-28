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
	all->buffer_id = ft_calloc(sizeof(unsigned int), 1);
	all->index_id = ft_calloc(sizeof(unsigned int), 1);
	return all;
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
	else
		gen_sqr(&all->datas, 100);
	render_loop(all);

	glfwTerminate();
	return 0;
}
