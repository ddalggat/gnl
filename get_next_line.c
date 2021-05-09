#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char		buff[10 + 1];
	int			cnt_byte;
	char		*mark;
	int			flag;
	static char	*tail;

	cnt_byte = 1;
	flag = 1;
	if (tail)
		*line = ft_strdup(tail);
	else
		*line = ft_calloc_V2(10 + 1);
	while (flag && cnt_byte)
	{
		if ((mark = ft_strchr(buff, '\n')))
		{
			*mark = '\0';
			flag = 0;
			tail = ft_strdup(++mark);
		}
		buff[cnt_byte] = '\0';
		*line = ft_strjoin(*line, buff);	
		cnt_byte = read(fd, buff, 10);
	}
	return (0);
}

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("text.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	return (0);
}
