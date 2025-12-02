/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:40:46 by mobenhab          #+#    #+#             */
/*   Updated: 2025/12/02 14:28:23 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dup;

	i = 0;
	dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*join;
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j] && s2[j] != '\n')
	{
		join[i + j] = s2[j];
		j++;
	}
	join[i + j] = '\0';
	return (join);
}

void	ft_memmove(char *buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i + 1])
	{
		buffer[i] = buffer[i + 1];
		i++;
	}
	buffer[i] = '\0';
}
