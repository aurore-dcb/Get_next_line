#include "get_next_line.h"

char *ft_strcat(char *dst, char *src)
{
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
    dst[i] = '\0';
    return (dst);   
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

    res = 1;
    while (is_new_line(stash) < 0 && res != 0)
    {
        res = read(fd, buf, BUFF_SIZE);
        buf[res] = '\0';
        if (res == -1)
            return (NULL);
        if (res != 0)
        {
            ft_strcat(stash, buf);
            clean_buf(buf);
        }
    }
    if (res == -1)
        return (NULL);
    ligne = just_the_line(stash);
    modif_stash(stash);
    return (ligne);
}