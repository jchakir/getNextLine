/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 00:33:19 by jchakir           #+#    #+#             */
/*   Updated: 2021/11/30 18:31:12 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_nl(int fd, char *line)
{
	char		buff[BUFFER_SIZE + 1];
	char		*str;
	ssize_t		rd_res;

	while (1)
	{
		rd_res = read(fd, buff, BUFFER_SIZE);
		buff[rd_res] = 0;
		if (rd_res == -1)
			return (NULL);
		if (! rd_res)
			return (line);
		str = ft_strjoin(line, buff);
		free(line);
		if (ft_gnl_strchr(buff, '\n'))
			break ;
		line = str;
	}
	return (str);
}

char	*ft_get_nl(char *line)
{
	char	*str;
	int		i;

	if (! line || ! *line)
	{
		free(line);
		return (NULL);
	}
	i = ft_strlen_nl(line);
	str = (char *)malloc(i + 1);
	if (! str)
	{
		free(line);
		return (NULL);
	}
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		str[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		str[i++] = '\n';
	str[i] = 0;
	return (str);
}

char	*ft_gnl_trim(char	*line)
{
	char	*str;
	int		j;
	int		i;

	if (! line || ! *line)
		return (NULL);
	i = ft_strlen_nl(line);
	j = 0;
	if (! line[i])
	{
		free(line);
		return (NULL);
	}
	str = (char *)malloc(ft_strlen(line + i) + 1);
	if (! str)
	{
		free(line);
		return (NULL);
	}
	while (line[i])
		str[j++] = line[i++];
	str[j] = 0;
	free(line);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*line[1024];
	char		*str;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (! ft_gnl_strchr(line[fd], '\n'))
		line[fd] = ft_read_nl(fd, line[fd]);
	str = ft_get_nl(line[fd]);
	line[fd] = ft_gnl_trim(line[fd]);
	return (str);
}
