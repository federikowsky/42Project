/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 19:56:42 by fefilipp          #+#    #+#             */
/*   Updated: 2022/01/30 20:58:12 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_new_line(char *s)
{
	int		i;
	int		j;
	char	*nline;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	nline = (char *)malloc(sizeof(char) * (ft_strlen(s) - i + 1));
	if (!nline)
	{
		free(s);
		return (NULL);
	}
	i++;
	j = 0;
	while (s[i] != '\0')
		nline[j++] = s[i++];
	nline[j] = '\0';
	free(s);
	return (nline);
}

char	*ft_print_line(char *s)
{
	char	*res;
	int		i;

	i = 0;
	while (!s[i] && s[i] != '\n')
		i++;
	res = (char *)malloc(sizeof(char) * (i + 2));
	if (!res)
	{
		free(s);
		return (NULL);
	}
	i = 0;
	while (!s[i] && s[i] != '\n')
	{
		res[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	free(s);
	return (res);
}

char	*ft_read_line(char *s, int fd)
{
	char	*buf;
	int		n;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	n = 1;
	while (!ft_strchr(s, '\n') && n != 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1)
		{
			free(buf);
			free(s);
			return (NULL);
		}
		buf[n] = '\0';
		s = ft_strjoin(s, buf);
	}
	free(buf);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*str[256];
	char		*result;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > 256)
		return (NULL);
	if (!str[fd])
	{
		str[fd] = (char *)malloc(sizeof(char) * 1);
		str[fd][0] = '\0';
	}
	str[fd] = ft_read_line(str[fd], fd);
	if (!str[fd])
		return (NULL);
	result = ft_print_line(str[fd]);
	str[fd] = ft_new_line(str[fd]);
	return (result);
}
