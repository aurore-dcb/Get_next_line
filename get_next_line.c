#include "get_next_line.h"

char *ft_strcat(char *dst, char *src)
{
    // printf("stash dans strcat:\n%s|\n", dst);
    int i;
    int j;

    i = 0;
    j = 0;
    if (!dst || !src)
        return (NULL);
    while (dst[i])
        i++;
    while (src[j])
        dst[i++] = src[j++];
    return (dst);   
}

int is_new_line(char *line)
{
    int i;

    i = 0;
    if (!line)
        return (-1);
    while (line[i])
    {
        if (line[i] == '\n')
            return (i);
        i++;
    }
    return (-1);
}

char *clean_stash(char *stash)
{
    int i;
    int j;
    int compteur;
    char *res;

    i = 0;
    j = 0;
    compteur = 0;
    if (!stash)
        return (NULL);
    while (stash[i] && stash[i++] != '\n')
        j++;
    while (stash[i])
        compteur++;
    res = malloc(sizeof(char) * (compteur + 1));
    if (!res)
        return (NULL);
    i = 0;
    while (i < compteur)
    {
        res[i] = stash[j];
        i++;
        j++;
    }
    res[i] = '\0';
    return (res);
}

char *just_the_line(char str[])
{
    int i;
    char *res;
    // int len;

    i = 0;
    // len = 0;
    // while (str[i] && str[i] == 'A')
    // {
    //     printf("ya A\n");
    //     i++;
    // }
    while (str[i] && str[i++] != '\n')
        i++;
    res = malloc(sizeof(char) * (i + 1));
    if (!res)
        return (NULL);
    i = 0;
    while (str[i] && str[i] != '\n')
    {
        res[i] = str[i];
        i++;
    }
    res[i++] = '\n';
    res[i++] = '\0';
    return (res);
}

char *get_next_line(int fd)
{
    // printf("buf size : %d\n", BUFF_SIZE);
    static char stash[FD_SIZE];
    // printf("stash debut : %s.\n", stash);
    char buf[BUFF_SIZE + 1];
    int res;

    int i = 0;
    while (stash[i] && stash[i] != '\n')
    {
        // printf("test");
        stash[i] = 'A';
        i++;
    }
    // printf("TEST :.%c.\n", stash[i]);
    stash[i] = 'A';
    // while (stash[i])
    // {
    //     printf("test");
    //     // stash[i] = '\0';
    //     i++;
    // }
    // printf("\n");

    res = 1;
    // printf("stash[0] : %c.\n", stash[0]);
    // printf("stash inter : %s.\n", stash);
    while (is_new_line(stash) < 0 && res != 0)
    {
        res = read(fd, buf, BUFF_SIZE);
        // printf("BUF:\n%s|\n", buf);
        if (res != 0)
            ft_strcat(stash, buf);
        // printf("1res = %d\n", res);
        // printf("2stash : %s..\n", stash);
    }
    // buf[taille_buf] = '\0';
    if (res == -1)
    {
        write(1, "erreur pendant la lecture du fichier.\n", 38);
        return (NULL);
    }
    // printf("stash avant return:\n%s|\n", stash);
    //FAIRE LE MENAGE
    
    // stash = clean_stash(stash);
    return (just_the_line(stash));
    // return (stash);
}