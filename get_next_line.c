#include "get_next_line.h"

static char	*extract_line(char **stash)
{
	char	*line;
	char	*rest;
	size_t	i = 0;

	if (!*stash || !**stash)
		return (NULL);
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	for (size_t j = 0; j <= i; j++)
		line[j] = (*stash)[j];
	line[i + ((*stash)[i] == '\n')] = '\0';
	if ((*stash)[i] == '\n')
		i++;
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
	return (extract_line(&stash));
}