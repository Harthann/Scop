#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "scop.h"
int		get_next_line(int fd, char **line)
{
	char	*buffer;
	int		buff;

	if (!(buffer = malloc(2)))
		return (-1);
	buffer[1] = 0;
	buff = 1;
	while (buff >= 0 && *buffer != '\n')
	{
		buff = read(fd, buffer, 1);
		if (!*line && buff == 0)
			break ;
		if (*line == NULL && *buffer != '\n')
			*line = ft_strdup(buffer);
		else if (*buffer != '\n' && buff)
			*line = ft_strjoin_free(*line, buffer, 1);
		if (!buff)
			*buffer = 0;
	}
	if (*line == NULL && buff == 1)
		*line = ft_strdup("");
	free(buffer);
	return (buff);
}