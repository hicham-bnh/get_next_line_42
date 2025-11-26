/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:41:25 by mobenhab          #+#    #+#             */
/*   Updated: 2025/11/26 12:05:35 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

size_t ft_strlen(char const *s)
{
	size_t i;
	i = 0;
	while (s[i])
	i++;
	return (i);
}

char *ft_substr(char const *s,unsigned int start, size_t len)
{
	size_t len_s;
	size_t i;
	char *tmp;
	len_s = ft_strlen(s);
	if (len_s < start)
	len = 0;
	if (len > len_s - start)
	len = len_s - start;
	tmp = malloc(sizeof(char) * (len + 1));
	if (!tmp)
	return (NULL);
	i = 0;
	while (i < len)
	{
		tmp [i] = s[start];
		i++;
		start++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_strcpy(char *stash, char *buf, size_t *count)
{
	size_t	i;

	i = 0;
	stash = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!stash)
		return (NULL);
	while (buf[i] && buf[i] != '\n')
	{
		stash[i] = buf[i];
		i++;
	}
	stash[i] = '\0';
	return (stash);
}

int	ft_strchr(char c)
{
	if (c == '\n')
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	static char	*buf;
	int			bytes;
	size_t count;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	bytes = read(fd, buf, BUFFER_SIZE);
	if (bytes <= 0)
		return (NULL);
	stash = ft_strcpy(stash, buf, &count);
	buf = ft_substr(buf, count, ft_strlen(stash));
	return (stash);
}
// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("get_next_line.c", O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	close(fd);
// }
