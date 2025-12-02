/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:40:41 by mobenhab          #+#    #+#             */
/*   Updated: 2025/12/02 14:53:46 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

// char	*fill_line(char *buffer, char *line, int fd)
// {
// 	if (line[0] == '\0')
// 	{
// 		line = ft_strdup(buffer);
// 		if (!line)
// 			return (NULL);
// 	}
// 	else
// 		line = ft_strjoin(line, buffer);
// 	if (!line)
// 		return (NULL);
// }

// char	*get_the_line(int fd, char *buffer)
// {
// 	char	*line;

// 	line = malloc(sizeof(char) * 1);
// 	if (!line)
// 		return (NULL);
// 	line[0] = '\0';
// 	line = fill_line(buffer, line, fd);
// }

int	ft_read(int fd, char *buffer)
{
	int	reader;

	reader = read(fd, buffer, BUFFER_SIZE);
	if (reader < 1)
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!read(fd, buffer, BUFFER_SIZE))
		return (NULL);
	line = ft_strdup(buffer);
	// printf("%s", line);
	ft_memmove(buffer);
	// printf("%s", buffer);
	while (ft_read(fd, buffer))
	{
        line = ft_strjoin(line , buffer);
		// printf("%s", line);
        ft_memmove(buffer);
	}
    line[BUFFER_SIZE + 1] = '\n';
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("get_next_line.h", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	close(fd);
}
