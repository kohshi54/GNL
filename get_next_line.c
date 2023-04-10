#include "get_next_line.h"


char *get_next_line(int fd)
{
   char        buf[BUFFER_SIZE + 1];
   char        *line;
   static char *save;
   ssize_t     read_byte;
   size_t      byte_to_nl;
   char        *tmp;


   line = NULL;
   if (save)
   {
       byte_to_nl = ft_strchr_nl(save);
       if (byte_to_nl)
       {
           line = ft_strnjoin(line, save, byte_to_nl);
           tmp = save;
           save = ft_strdup(&save[byte_to_nl]);
           free(tmp);
           return (line);
       }
       else
       {
           tmp = ft_strnjoin(line, save, ft_strlen(save));
           free(line);
           line = tmp;
           free(save);
           save = NULL;
       }
   }
   while (1)
   {
       read_byte = read(fd, buf, BUFFER_SIZE);
       if (read_byte == 0)
           break ;
       else if (read_byte == -1)
           return (NULL);
       buf[read_byte] = '\0';
       byte_to_nl = ft_strchr_nl(buf);
       if (byte_to_nl)
       {
           save = ft_strdup(&buf[byte_to_nl]);
           tmp = ft_strnjoin(line, buf, byte_to_nl);
           free(line);
           line = tmp;
           return (line);
       }
       else
       {
           tmp = ft_strnjoin(line, buf, BUFFER_SIZE);
           free(line);
           line = tmp;
       }
   }
   return (line);
}