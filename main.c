#include "get_next_line.h"

int main(int argc, char **argv)
{
    int fd;
    char *ligne;

    (void)argc;
    fd = open(argv[1], O_RDONLY);
    for (int i = 0; i < 5; i++)
    {
        ligne = get_next_line(fd);
        printf("resultat : %s",ligne);
        // free(ligne);
    }
    close(fd);
    return (0);
}