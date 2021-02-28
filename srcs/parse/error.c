#include "scop.h"

void	error(const char* str)
{
	t_all   *all;

	all = singleton();
	free(all->datas->vertex);
	free(all->datas->mtl_link);
	free(all->datas->index);
	free(all);
	write(2, str, ft_strlen(str));
	exit (1);
}