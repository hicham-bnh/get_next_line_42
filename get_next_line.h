/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:28:13 by mobenhab          #+#    #+#             */
/*   Updated: 2025/12/04 14:49:59 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

ssize_t	ft_strlen(char *str);
void	ft_strlcat(char *dst, char *src, int endl);
char	*get_next_line(int fd);
ssize_t	readline(char *buf, int fd);
int	veriffd(char *buf, int fd);
char	*freeline(char *line);
void	newbuf(char *buf, ssize_t endl, ssize_t readbytes);
char	*newline(char *line, char *buf, ssize_t	endl,ssize_t readbytes);
ssize_t	endline(char *buf);
#endif