/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeerewe <mkeerewe@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 09:46:59 by mkeerewe          #+#    #+#             */
/*   Updated: 2025/09/07 13:07:01 by mkeerewe         ###   ########.fr       */
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
size_t	ft_strlen(const char *s);
void	ft_strcpy(char *dst, char *src);
void	ft_strncat(char *dst, char *src, size_t n);
char	*ft_realloc(char *ptr, size_t size);
char	*get_next_line(int fd);

#endif