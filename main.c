#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
void error(int error_num);
void ft_putstr_fd(char *s, int fd);

int main(int argc, char *argv[])
{
	char *ret;
	if (argc < 2) error(1);
	for (int i = 1; i < argc; i++)
	{
    	int fd = open(argv[i], O_RDONLY);
    	if (fd == -1) error(2);
    	// char *ret = get_next_line(fd);
    	// if (ret == NULL) error(3);
		// ft_putstr_fd(ret, STDOUT_FILENO);
    	// ret = get_next_line(fd);
    	// if (ret == NULL) error(3);
		// ft_putstr_fd(ret, STDOUT_FILENO);
    	// ret = get_next_line(fd);
    	// if (ret == NULL) error(3);
		// ft_putstr_fd(ret, STDOUT_FILENO);
    	// // ret = get_next_line(fd);
    	// // if (ret == NULL) error(3);
		// // ft_putstr_fd(ret, STDOUT_FILENO);
		while ((ret = get_next_line(fd)))
			ft_putstr_fd(ret, STDOUT_FILENO);
		error(3);
	}
}

void error(int error_num)
{
	if (error_num == 1)
		write(STDOUT_FILENO, "PLEASE INPUT FILE", sizeof("PLEASE INPUT FILE"));
	else if (error_num == 2)
		write(STDOUT_FILENO, "ERROR OPENING FILE", sizeof("ERROR OPENIGN FILE"));
	else if (error_num == 3)
		write(STDOUT_FILENO, "EOF OR SOMETHING WENT WRONG WITH GNL", sizeof("EOF OR SOMETHING WENT WRONG WITH GNL"));
	exit(0);
}

void ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}