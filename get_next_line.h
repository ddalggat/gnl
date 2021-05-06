#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

// # define BUFFER_SIZE;

char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_calloc_V2(int count);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(char *s, int n); 

#endif 