/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeerewe <mkeerewe@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:13:12 by mkeerewe          #+#    #+#             */
/*   Updated: 2025/09/07 12:40:46 by mkeerewe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == (void *) 0)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s != (void *) 0)
		write(fd, s, ft_strlen(s));
}

// void	ft_strncpy(char *dst, char *src, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	while (src[i] != '\0' && i < n)
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	dst[i] = '\0';
// }

void	ft_strcpy(char *dst, char *src)
{
	size_t	i;

	i = 0;
	if (src == (void *) 0)
		return ;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

void	ft_strncat(char *dst, char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (src == (void *) 0)
		return ;
	while (dst[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
}

char	*ft_realloc(char *ptr, size_t size)
{
	char	*out;
	
	out = (char *) malloc(size);
	if (out == (void *) 0)
		return (out);
	ft_strcpy(out, ptr);
	if (ptr != (void *) 0)
		free(ptr);
	return (out);
}

int	eol_found(char *line)
{
	int	i;

	i = 0;
	if (line == (void *) 0)
		return (-1);
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	char		*out;
	static char	*line;
	int			cnt;

	if (fd < 0)
		return ((void *) 0);
	out = (char *) malloc(1);
	if (out == (void *) 0)
		return (out);
	line = ft_realloc(line, BUFFER_SIZE + 1);
	if (line == (void *) 0)
		return (line);
	cnt = -2;
	while (cnt != 0 && cnt != -1)
	{
		if (eol_found(line) != -1)
		{
			out = ft_realloc(out, ft_strlen(out) + ft_strlen(line) + 1);
			if (out == (void *) 0)
				return (out);
			ft_strncat(out, line, eol_found(line) + 1);
			ft_strcpy(line, &line[eol_found(line) + 1]);
			return out;
		}
		out = ft_realloc(out, ft_strlen(out) + ft_strlen(line) + 1);
		if (out == (void *) 0)
			return (out);
		ft_strncat(out, line, ft_strlen(line));
		cnt = read(fd, line, BUFFER_SIZE);
		line[cnt] = '\0';
	}
	if (ft_strlen(out) == 0)
		return ((void *) 0);
	return (out);
}

// int	main(void)
// {
// 	int	fd;

// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (1);
// 	ft_putstr_fd(get_next_line(fd), 1);
// 	ft_putstr_fd(get_next_line(fd), 1);
// 	close(fd);
// 	return (0);
// }
