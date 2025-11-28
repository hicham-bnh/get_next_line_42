/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:41:51 by mobenhab          #+#    #+#             */
/*   Updated: 2025/11/28 14:11:34 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

char	*get_next_line(int fd);
size_t	ft_strlen(char const *s);
char	*ft_substr(char const *s, size_t start, int len);
char	*ft_strcpy(char *dest, char *src);
void	ft_memmove(char *buf);
char	*ft_realloc(char *str, char c);
char	*ft_strdup(const char *s);
int		read_file(int fd, char *buffer);
char	*fill_line(char *buffer, char *line, int fd);
char	*get_the_line(int fd, char *buffer);

#endif