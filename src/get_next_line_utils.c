/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 00:33:07 by jchakir           #+#    #+#             */
/*   Updated: 2021/11/30 17:39:38 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	if (! s)
		return (0);
	while (*s++)
		len++;
	return (len);
}

int	ft_strlen_nl(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	return (i);
}

int	ft_gnl_strchr(char *s, char c)
{
	if (! s || ! c)
		return (0);
	while (*s && *s != c)
		s++;
	if (*s == c)
		return (1);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	char	*save_str;

	if (! s1)
		s1 = "";
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (! str)
		return (NULL);
	save_str = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = 0;
	return (save_str);
}
