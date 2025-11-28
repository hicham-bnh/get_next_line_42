/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:41:25 by mobenhab          #+#    #+#             */
/*   Updated: 2025/11/28 14:14:57 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	read_file(int fd, char *buffer)
{
	int	reader;

	reader = 1;
	reader = read(fd, buffer, BUFFER_SIZE);
	if (reader >= 0)
		buffer[reader] = '\0';
	else
		buffer[0] = '\0';
	return (reader);
}

char	*fill_line(char *buffer, char *line, int fd)
{
	int	reader;

	reader = 1;
	while (buffer[0] != '\n' && reader > 0)
	{
		if (ft_strlen(buffer))
		{
			line = ft_realloc(line, buffer[0]);
			if (!line)
				return (NULL);
			ft_memmove(buffer);
		}
		else
			reader = read_file(fd, buffer);
	}
	if (reader == 0 && ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_the_line(int fd, char *buffer)
{
	char	*line;

	line = malloc(1 * sizeof(char));
	if (!line)
		return (NULL);
	line[0] = '\0';
	line = fill_line(buffer, line, fd);
	if (!line)
		return (NULL);
	if (buffer[0] == '\n')
	{
		line = ft_realloc(line, '\n');
		if (!line)
			return (NULL);
		ft_memmove(buffer);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		buffer[0] = '\0';
		return (NULL);
	}
	line = get_the_line(fd, buffer);
	if (!line)
		return (NULL);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("get_next_line.h", O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	close(fd);
// }
