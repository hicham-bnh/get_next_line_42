/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobenhab <mobenhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:39:59 by mobenhab          #+#    #+#             */
/*   Updated: 2025/11/28 14:17:27 by mobenhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_memmove(char *buf)
{
	size_t	i;

	i = 0;
	while (buf[i + 1])
	{
		buf[i] = buf[i + 1];
		i++;
	}
	buf[i] = '\0';
}

char	*ft_strcpy(char *dest, char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_realloc(char *str, char c)
{
	char	*res;
	size_t	len;

	res = ft_strdup(str);
	if (!res)
	{
		free(str);
		return (NULL);
	}
	len = ft_strlen(res);
	free(str);
	str = malloc(sizeof(char) * (len + 2));
	if (!str)
	{
		free(res);
		return (NULL);
	}
	str = ft_strcpy(str, res);
	free(res);
	str[len] = c;
	str[len + 1] = '\0';
	return (str);
}

char	*ft_strdup(const char *s)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!tmp)
		return (NULL);
	while (s[i])
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
