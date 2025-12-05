/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 00:44:44 by mobenhab          #+#    #+#             */
/*   Updated: 2025/12/05 01:07:53 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	ft_bzero(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
	{
		str[i] = 0;
		i++;
	}
}

static void	ft_clean(char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] != '\n' && str[i] != 0)
		i++;
	if (str[i] == '\n')
		i++;
	j = 0;
	while (str[i + j])
	{
		str[j] = str[i + j];
		j++;
	}
	str[j] = 0;
}

static char	*ft_rd(int fd, int rd, char *ln, char bf[OPEN_MAX][BUFFER_SIZE + 1])
{
	while (rd && ft_check_line(ln) == 0)
	{
		rd = read(fd, bf[fd], BUFFER_SIZE);
		if (rd < 0)
		{
			ft_bzero(bf[fd]);
			free(ln);
			return (NULL);
		}
		bf[fd][rd] = 0;
		ln = ft_strjoin(ln, bf[fd]);
		if (!ln)
			return (NULL);
	}
	return (ln);
}

char	*get_next_line(int fd)
{
	static char	buffer[OPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			read_byte;

	read_byte = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdup(buffer[fd]);
	if (!line)
		return (NULL);
	line = ft_rd(fd, read_byte, line, buffer);
	if (!line)
		return (NULL);
	ft_clean(buffer[fd]);
	if (line[0] == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
