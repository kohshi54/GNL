#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

char *get_next_line(int fd);
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#endif
