#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
void error(int error_num);
#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc < 2) error(1);
	for (int i = 1; i < argc; i++)
	{
    	int fd = open(argv[i], O_RDONLY);
    	if (fd == -1) error(2);
    	char *ret = get_next_line(fd);
    	if (ret == NULL) error(3);
    	write(STDOUT_FILENO, ret, sizeof(char *));
	}
}

void error(int error_num)
{
   if (error_num == 1)
       write(STDOUT_FILENO, "PLEASE INPUT FILE", sizeof("PLEASE INPUT FILE"));
   else if (error_num == 2)
       write(STDOUT_FILENO, "ERROR OPENING FILE", sizeof("ERROR OPENIGN FILE"));
   else if (error_num == 3)
       write(STDOUT_FILENO, "SOMETHING WENT WRONG WITH GNL", sizeof("SOMETHING WENT WRONG WITH GNL"));
   exit(0);
}

