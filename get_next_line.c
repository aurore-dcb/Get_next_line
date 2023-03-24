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
    if (stash[i] == '\n')
        i++;
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

    i = 0;
    if (!str[0])
        return (NULL);
    while (str[i] && str[i] != '\n')
        i++;
    res = malloc(sizeof(char) * (i + 2));
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

void clean_buf(char *buf)
{
    int i;

    i = 0;
    if (buf)
    {
        while (buf[i])
            buf[i++] = '\0';
    }
}

char *get_next_line(int fd)
{
    static char stash[FD_SIZE];
    char buf[BUFF_SIZE + 1];
    int res;
    char *ligne;

    // printf("stash debut : %s.\n", stash);
    res = 1;
    while (is_new_line(stash) < 0 && res != 0)
    {
        res = read(fd, buf, BUFF_SIZE);
        if (res != 0)
        {
            // if (res < BUFF_SIZE)
            // {
                
            // }
            ft_strcat(stash, buf);
            // printf("buf : %s\n", buf);
            clean_buf(buf);
            // printf("stash : %s\n", stash);
        }
    }
    if (res == -1)
    {
        write(1, "erreur pendant la lecture du fichier.\n", 38);
        return (NULL);
    }
    // printf("stash : |%s|\n", stash);
    ligne = just_the_line(stash);
    // printf("ligne : |%s|\n", ligne);
    modif_stash(stash);
    return (ligne);
}