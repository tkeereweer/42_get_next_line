/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeerewe <mkeerewe@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 09:46:59 by mkeerewe          #+#    #+#             */
/*   Updated: 2025/09/06 18:03:23 by mkeerewe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

void	ft_putstr_fd(char *s, int fd);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
char	*get_next_line(int fd);

#endif