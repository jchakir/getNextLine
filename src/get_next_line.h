/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:21:31 by jchakir           #+#    #+#             */
/*   Updated: 2021/11/30 17:37:41 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int		ft_strlen(char *s);
int		ft_strlen_nl(char *line);
int		ft_gnl_strchr(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_read_nl(int fd, char *line);
char	*ft_get_nl(char *line);
char	*ft_gnl_trim(char *line);
char	*get_next_line(int fd);

#endif
