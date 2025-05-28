/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raulserr <raulserr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:01:09 by raulserr          #+#    #+#             */
/*   Updated: 2025/05/28 17:46:39 by raulserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char **stash)
{
	char	*line;
	char	*rest;
	size_t	i;

	if (!*stash || !**stash)
		return (NULL);
	i = 0;
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	if ((*stash)[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, *stash, i);
	line[i] = '\0';
	rest = ft_strdup(*stash + i);
	free(*stash);
	*stash = rest;
	return (line);
}

static int	read_and_stash(int fd, char **stash)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes;

	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes <= 0)
		return (bytes);
	buffer[bytes] = '\0';
	*stash = ft_strjoin(*stash, buffer);
	return (bytes);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	int			bytes;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes > 0)
		bytes = read_and_stash(fd, &stash);
	if (bytes < 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = extract_line(&stash);
	if (!line || !*line)
	{
		free(line);
		line = NULL;
		free(stash);
		stash = NULL;
	}
	return (line);
}
