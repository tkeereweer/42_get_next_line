/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeerewe <mkeerewe@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:23:30 by mkeerewe          #+#    #+#             */
/*   Updated: 2025/09/06 15:58:48 by mkeerewe         ###   ########.fr       */
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

static void	ft_move(char *str_dst, char *str_src, int i_len)
{
	int	i;

	if (str_dst <= str_src)
	{
		i = 0;
		while (i < i_len)
		{
			str_dst[i] = str_src[i];
			i++;
		}
	}
	else
	{
		i = i_len - 1;
		while (i >= 0)
		{
			str_dst[i] = str_src[i];
			i--;
		}
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i_len;
	char	*str_dst;
	char	*str_src;

	if (src == (void *) 0 && dst == (void *) 0)
		return (dst);
	i_len = (int) len;
	str_dst = (char *) dst;
	str_src = (char *) src;
	ft_move(str_dst, str_src, i_len);
	return (dst);
}

