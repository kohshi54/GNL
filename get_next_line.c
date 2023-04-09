#include "get_next_line.h"
char *ft_strcpy(char *dst, const char *src);

char *get_next_line(int fd)
{
	char buf[BUFFER_SIZE + 1];
	char *line;

	int ret = read(fd, buf, BUFFER_SIZE);
	if (ret == 0)
	{
		write(STDOUT_FILENO, "EOF", sizeof("EOF"));
		return (NULL);
	}
	else if (ret == -1)
	{
		write(STDERR_FILENO, "ERROR READING", sizeof("ERROR READING"));
		return (NULL);
	}
	buf[ret] = '\0';
	line = malloc(sizeof(char) * (ret + 1));
	if (!line)
	{
		write(STDERR_FILENO, "MALLOC ERROR", sizeof("MALLOC ERROR"));
		return (NULL);
	}
	ft_strcpy(line, buf);
	return (line);
}

char *ft_strcpy(char *dst, const char *src)
{
	char *head;

	head = dst;
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return (head);
}