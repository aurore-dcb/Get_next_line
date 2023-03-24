#include "get_next_line.h"

char *ft_strcat(char *dst, char *src)
{
    // printf("stash dans strcat:\n%s|\n", dst);
    // printf("src (buf) : %s|\n", src);
    // printf("dst (stash) : %s|\n\n", dst);
    int i;
    int j;

    i = 0;
    j = 0;
    if (!dst || !src)
        return (NULL);
    while (dst[i])
        i++;
    // printf("i = %d\n", i);
    // printf("src (buf) : %s|\n", src);
    while (src[j])
    {
        dst[i] = src[j];
        // printf("dst[%d] : %c\n", i, dst[i]);
        i++;
        j++;
    }
    dst[i] = '\0';
    // printf("dst[%d] : %c\n", i, dst[i]);
    // i++;
    // printf("dst[%d] : %c\n", i, dst[i]);
    // printf("j = %d\n", j);
    // printf("stash fin strcat:\n%s|\n", dst);
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

    // printf("stash debut : %s|\n", stash);
    res = 1;
    while (is_new_line(stash) < 0 && res != 0)
    {
        res = read(fd, buf, BUFF_SIZE);
        // printf("stash : %s\n", stash);
        if (res != 0)
        {
            // if (res < BUFF_SIZE)
            // {
                
            // }
            // printf("res = %d\n", res);
            // printf("buf : %s\n", buf);
            // printf("stash : %s\n", stash);
            ft_strcat(stash, buf);
            clean_buf(buf);
            // printf("stash : %s\n", stash);
        }
    }
    if (res == -1)
        return (NULL);
    // printf("stash fin : %s|\n", stash);
    ligne = just_the_line(stash);
    modif_stash(stash);
    return (ligne);
}