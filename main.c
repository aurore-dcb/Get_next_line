#include "get_next_line.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    int fd;
    char *ligne;

    if (argc == 1)
        fd = 1;
    else if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        if (fd == - 1)
            return(0);
    }
    else
        return (0);
    ligne = "ok";
    while (ligne != NULL)
    {
        ligne = get_next_line(fd);
        if (ligne != NULL)
        {
            printf("resultat : %s\n", ligne);
            free(ligne);
        }
    }
    close(fd);
    return (0);
}
