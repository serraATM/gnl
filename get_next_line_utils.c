#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	size_t len = ft_strlen(s1);
	char *copy = malloc(len + 1);
	if (!copy)
		return (NULL);
	for (size_t i = 0; i < len; i++)
		copy[i] = s1[i];
	copy[len] = '\0';
	return (copy);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t len1 = ft_strlen(s1);
	size_t len2 = ft_strlen(s2);
	char *res = malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);
	for (size_t i = 0; i < len1; i++)
		res[i] = s1[i];
	for (size_t i = 0; i < len2; i++)
		res[len1 + i] = s2[i];
	res[len1 + len2] = '\0';
	free(s1);
	return (res);
}