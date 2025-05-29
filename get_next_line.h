/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raulserr <raulserr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:53:34 by raulserr          #+#    #+#             */
/*   Updated: 2025/05/28 17:46:42 by raulserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char		*get_next_line(int fd);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(const char *s1);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *s);
void		*ft_memcpy(void *dst, const void *src, size_t n);

#endif