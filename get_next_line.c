/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:29:51 by mobenhab          #+#    #+#             */
/*   Updated: 2025/12/04 14:51:07 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*newline(char *line, char *buf, ssize_t	endl,ssize_t readbytes)
{
	char	*newline;
	int	lnewline;

	if (!line && !buf[0])
		return(NULL);
	lnewline = ft_strlen(line);
	if (endl == readbytes)
		lnewline += endl;
	else
		lnewline += endl + 1;
	newline = malloc(sizeof(char) * (lnewline + 1));
	if (!newline)
		return (freeline(line));
	newline[0] = '\0';
	if (line)
		ft_strlcat(newline, line, ft_strlen(line));
	if (endl == readbytes)
		ft_strlcat(newline, buf, endl);
	else
		ft_strlcat(newline, buf, endl + 1);
	free(line);
	return (newline);
}

void	newbuf(char *buf, ssize_t endl, ssize_t readbytes)
{
	ssize_t	i;

	i = 0;
	while (i < readbytes)
	{
		if (endl + 1 + i < readbytes)
			buf[i] = buf[endl + 1 + i];
		else
			buf[i] = '\0';
		i++;
	}
	
}

char	*freeline(char *line)
{
	if (line)
		free(line);
	return (NULL);
}


char	*get_next_line(int fd)
{
	static	char	buf[BUFFER_SIZE + 1];
	char	*line;
	ssize_t	readbytes;
	ssize_t	endl;
	int		stop;

	stop = 0;
	buf[BUFFER_SIZE] = '\0';
	if(fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	while (!stop)
	{
		readbytes = readline(buf, fd);
		if (readbytes < 0)
			return(freeline(line));
		endl = endline(buf);
		if (readbytes != endl || readbytes == 0)
			stop = 1;
		if (buf[0])
		{
			line = newline(line, buf, endl, readbytes);
			if(!line)
				return(NULL);
			newbuf(buf, endl, readbytes);
		}
	}
	return(line);
}

// #include <stdio.h>
// #include <fcntl.h>

// int	main()
// {
// 	int i = 0;
// 	char *str;
// 	int	fd = open("get_next_line.h", O_RDONLY);

// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	free(str);

// 	return (0);
// }