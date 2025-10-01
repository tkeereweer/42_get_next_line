/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_read_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeerewe <mkeerewe@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:04:12 by mkeerewe          #+#    #+#             */
/*   Updated: 2025/10/01 11:25:22 by mkeerewe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int		fd;
	char	*line;
	char	c;

	c = 'a';
	line = &c;
	if (argc == 1)
	{
		while (line != (void *) 0)
		{
			line = get_next_line(0);
			printf("%s", line);
		}
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	get_next_line(-1);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	while (line != (void *) 0)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=2 get_next_line_utils.c get_next_line.c test_files/tests.c -o test_gnl