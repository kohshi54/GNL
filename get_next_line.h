#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


#include <stdlib.h>
#include <unistd.h>

char    *get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *s1);
size_t	ft_strchr_nl(const char *s);
char    *ft_strnjoin(char const *s1, char const *s2, size_t n);

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif


#endif
