/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:34:08 by mobenhab          #+#    #+#             */
/*   Updated: 2025/12/04 14:49:33 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_strlen(char *str)
{
	ssize_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

ssize_t	readline(char *buf, int fd)
{
	ssize_t	readbytes;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	if (buf[0])
		readbytes = ft_strlen(buf);
	else
	{
		readbytes = read(fd, buf, BUFFER_SIZE);
		if (readbytes < 0)
			return (-1);
	}
	return (readbytes);
}

ssize_t	endline(char *buf)
{
	ssize_t	i;

	i = 0;
	while (buf[i] != '\n' && buf[i])
		i++;
	return (i);
}

void	ft_strlcat(char *dst, char *src, int endl)
{
	int	i;
	int	ldst;

	i = 0;
	ldst = ft_strlen(dst);
	while (src[i] && i < endl)
	{
		dst[ldst + i] = src[i];
		i++;
	}
	dst[ldst + i] = '\0';
}
