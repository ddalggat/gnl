#include "get_next_line_bonus.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	new_tail(char *mark, char *mark2, char **tail, int fd)
{
	if (mark)
	{
		*mark = '\0';
		mark2 = tail[fd];
		tail[fd] = ft_strdup(++mark);
		free(mark2);
	}
}

char	*ft_check_tail(char **tail, char	**line, int fd)
{
	char	*mark;

	mark = NULL;
	if (tail[fd])
	{
		mark = ft_strchr(tail[fd], '\n');
		if (mark)
		{
			*mark = '\0';
			*line = tail[fd];
			tail[fd] = ft_strdup(++mark);
		}
		else
		{
			*line = tail[fd];
			tail[fd] = 0;
		}
	}
	else
		*line = ft_calloc_V2(1);
	return (mark);
}

int	read_line(char **line, char **tail, char *buff, int fd)
{
	int		cnt_byte;
	char	*mark;
	char	*mark2;

	cnt_byte = 1;
	mark = ft_check_tail(tail, line, fd);
	while (mark == NULL && cnt_byte)
	{
		cnt_byte = read(fd, buff, BUFFER_SIZE);
		buff[cnt_byte] = '\0';
		mark = ft_strchr(buff, '\n');
		new_tail(mark, mark2, tail, fd);
		mark2 = *line;
		*line = ft_strjoin(*line, buff);
		free(mark2);
	}
	free(buff);
	if (tail[fd] || cnt_byte)
		return (1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*tail[1024];

	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (-1);
	if (read(fd, buff, 0) == -1)
	{
		free(buff);
		return (-1);
	}
	if (read_line(line, &tail[fd], buff, fd))
		return (1);
	return (0);
}
