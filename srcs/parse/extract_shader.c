#include "scop.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_append(char *s1, char *s2, int length)
{
	char	*ret;
	int	str_length;
	int	i;

	if (!length)
		return (s1);
	str_length = 0;
	if (s1)
		str_length = ft_strlen(s1);
	ret = malloc(sizeof(char) * (length + str_length + 1));
	if (!ret)
		return (s1);
	i = 0;
	while (s1 && s1[i])
	{
		ret[i] = s1[i];
		++i;
	}
	while (s2 && s2[i - str_length])
	{
		ret[i] = s2[i - str_length];
		++i;
	}
	ret[i] = 0;
	free(s1);
	return (ret);
}

char	*extract_shader(const char* path)
{
	int	fd;
	char	buffer[4096];
	int	ret;
	char	*shader;

	shader = NULL;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	ret = 1;
	while(ret)
	{
		ret = read(fd, buffer, 4095);
		buffer[ret] = 0;
		shader = ft_append(shader, buffer, ret);
	}
	return (shader);
}
