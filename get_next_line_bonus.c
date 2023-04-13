/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 22:14:23 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/04/14 01:28:24 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static size_t	my_read(int fd, char *buf, char *line)
{
	ssize_t	read_byte;

	read_byte = read(fd, buf, BUFFER_SIZE);
	if (read_byte == 0)
		return (0);
	else if (read_byte == -1)
	{
		free(line);
		return (0);
	}
	buf[read_byte] = '\0';
	return (read_byte);
}

static size_t	check_save(char **line, char **save)
{
	size_t	byte_to_nl;
	char	*tmp;

	byte_to_nl = ft_strchr_nl(*save);
	if (byte_to_nl)
	{
		*line = ft_strnjoin(*line, *save, byte_to_nl);
		tmp = *save;
		*save = ft_strdup(&(*save)[byte_to_nl]);
		free(tmp);
	}
	else
	{
		*line = ft_strnjoin(*line, *save, ft_strlen(*save));
		free(*save);
		*save = NULL;
	}
	return (byte_to_nl);
}

static size_t	check_buf(char **line, char **save, char *buf)
{
	size_t	byte_to_nl;
	char	*tmp;

	byte_to_nl = ft_strchr_nl(buf);
	if (byte_to_nl)
	{
		*save = ft_strdup(&buf[byte_to_nl]);
		tmp = ft_strnjoin(*line, buf, byte_to_nl);
		free(*line);
		*line = tmp;
	}
	else
	{
		tmp = ft_strnjoin(*line, buf, BUFFER_SIZE);
		free(*line);
		*line = tmp;
	}
	return (byte_to_nl);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	static char	*save[OPEN_MAX];

	line = NULL;
	if (save[fd])
		if (check_save(&line, &save[fd]))
			return (line);
	while (my_read(fd, buf, line))
		if (check_buf(&line, &save[fd], buf))
			return (line);
	return (line);
}
