#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 8
# define FD_SIZE 4096

#include <unistd.h>
#include <stdlib.h>
//read
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
//open
#include <fcntl.h>

#include <stdio.h>
/*fonctions autorisées : read, malloc, free*/

char *get_next_line(int fd);
#endif