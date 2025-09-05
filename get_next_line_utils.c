/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeerewe <mkeerewe@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:23:30 by mkeerewe          #+#    #+#             */
/*   Updated: 2025/09/04 19:17:12 by mkeerewe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
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

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	i;
	size_t	j;

	len_src = ft_strlen(src);
	if (dstsize == 0)
		return (len_src);
	len_dst = ft_strlen(dst);
	i = 0;
	j = 0;
	if (len_dst > dstsize)
		return (len_src + dstsize);
	while (dst[i] != '\0')
		i++;
	while (src[j] != '\0' && i + j < dstsize - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	while (i + j < dstsize)
		dst[i + j++] = '\0';
	return (len_dst + len_src);
}

