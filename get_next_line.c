/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeerewe <mkeerewe@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:36:50 by mkeerewe          #+#    #+#             */
/*   Updated: 2025/09/05 09:46:08 by mkeerewe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	char	*last_char;
	int		cnt;

	line = (char *) malloc(BUFFER_SIZE);
	if (line == (void *) 0)
		return (line);
	last_char = (char *) malloc(2 * sizeof(char));
	if (last_char == (void *) 0)
		return (last_char);
	last_char[0] = 'a';
	cnt = -2;
	while (cnt != 0 && cnt != -1 && last_char[0] != '\n')
	{
		cnt = read(fd, last_char, 1);
		last_char[1] = '\0';
		if (cnt != 0 && cnt != -1)
			ft_strlcat(line, last_char, BUFFER_SIZE);
	}
	return (line);
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	ft_putstr_fd(get_next_line(fd), 1);
	ft_putstr_fd(get_next_line(fd), 1);
	close(fd);
	return (0);
}
