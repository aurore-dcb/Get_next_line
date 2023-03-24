#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFF_SIZE
# define BUFF_SIZE 8
#endif

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
void modif_stash(char *stash);
int is_new_line(char *line);
char *just_the_line(char str[]);
#endif