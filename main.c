#include "get_next_line.h"

int main(int argc, char **argv)
{
    int fd;
    char *ligne;

    (void)argc;
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
    for (int i = 0; i < 9; i++)
    {
        ligne = get_next_line(fd);
        printf("resultat : %s",ligne);
        free(ligne);
    }
    close(fd);
    return (0);
}