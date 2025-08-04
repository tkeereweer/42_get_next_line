#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	int				read_cnt;
	char			*curr_line;
	char			*curr_ptr;
	unsigned int	len;

	curr_line = (char *) malloc(BUFFER_SIZE);
	if (curr_line == (void *) 0)
		return (curr_line);
	curr_line[0] = 'a';
	curr_ptr = curr_line;
	len = 0;
	while (curr_line[len] != '\n' || curr_line[len] != '\0')
	{
		read_cnt = read(fd, curr_ptr, 1);
		if (read_cnt == -1)
		{
			free(curr_line);
			return ((void *) 0);
		}
		curr_ptr++;
		len++;
	}
	curr_line[len + 1] = '\0';
	return (curr_line);
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return (0);
}
