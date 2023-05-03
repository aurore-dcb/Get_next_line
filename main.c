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
            printf("resultat : %s",ligne);
            free(ligne);
        }
    }
    close(fd);
    return (0);
}

//tests bonus
// int main()
// {
//     int fd1, fd2;
//     char *ligne;

//     ligne = "ok";
//     fd1 = open("test.txt", O_RDONLY);
//     printf("fd = %d\n", fd1);
//     ligne = get_next_line(fd1);
//     if (ligne != NULL)
//     {
//         printf("resultat : %s",ligne);
//         free(ligne);
//     }
//     fd2 = open("test2.txt", O_RDONLY);
//     printf("fd = %d\n", fd2);
//     ligne = get_next_line(fd2);
//     if (ligne != NULL)
//     {
//         printf("resultat : %s",ligne);
//         free(ligne);
//     }
//     close(fd1);
//     close(fd2);
//     return (0);
// }