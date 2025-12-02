/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:40:37 by mobenhab          #+#    #+#             */
/*   Updated: 2025/12/02 14:19:11 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

# include <stdlib.h>
# include <unistd.h>

void	ft_memmove(char *buffer);

size_t	ft_strlen(const char *s);

char    *get_next_line(int fd);
char    *ft_strdup(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);

# endif