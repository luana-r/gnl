/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:54:09 by lsouza-r          #+#    #+#             */
/*   Updated: 2024/02/03 18:00:58 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*line_to_return;
	char		*full_line;
	static char	*line_backup;

	if (!line_backup)
		line_backup = ft_strdup("");
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(line_backup);
		line_backup = NULL;
		return (NULL);
	}
	full_line = ft_read(line_backup, fd);
	line_to_return = ft_build_line(full_line);
	line_backup = get_line_after_bslash_n(full_line);
	free(full_line);
	if (*line_to_return == '\0' && *line_backup == '\0')
	{
		free(line_to_return);
		free(line_backup);
		line_backup = NULL;
		return (NULL);
	}
	return (line_to_return);
}

char	*ft_read(char *joined, int fd)
{
	char	*buffer;
	int		read_size;

	read_size = 1;
	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (read_size != 0 && ft_strchr(joined, '\n') == NULL)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		buffer[read_size] = '\0';
		joined = ft_strjoin(joined, buffer);
	}
	free(buffer);
	return (joined);
}

char	*ft_build_line(char *line)
{
	int		i;
	int		line_len;
	char	*new_line;

	i = 0;
	line_len = 0;
	while (line[line_len] != '\0' && line[line_len] != '\n')
		line_len++;
	if (line[line_len] == '\n')
		line_len += 1;
	new_line = (char *) malloc((line_len + 1) * sizeof(char));
	while (i < line_len)
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

char	*get_line_after_bslash_n(char *line)
{
	int		i;
	char	*new_line_begin;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i += 1;
	new_line_begin = ft_strdup(line + i);
	return (new_line_begin);
}
