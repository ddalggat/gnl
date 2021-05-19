#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include	<stdio.h>
# include	<fcntl.h>
# include	<stdlib.h>
# include	<unistd.h>

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_calloc_V2(int count);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);

#endif