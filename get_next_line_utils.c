#include "get_next_line.h"

void modif_stash(char *stash)
{
    int i = 0;
    int j = 0;

    while (stash[i] && stash[i] != '\n')
    {
        stash[i] = '\0';
        i++;
    }
    if (stash[i] == '\n')
    {
        stash[i++] = '\0';
        while (stash[i])
        {
            stash[j] = stash[i];
            j++;
            i++;
        }
        stash[j] = '\0';
    }
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

char *just_the_line(char str[])
{
    int i;
    char *res;

    i = 0;
    if (str[0] == '\0')
        return (NULL);
    while (str[i] && str[i] != '\n')
        i++;
    if (is_new_line(str) >= 0)
    {
        // printf("test1");
        res = malloc(sizeof(char) * (i + 2));
    }
    else
    {
        // printf("test2");
        res = malloc(sizeof(char) * (i + 1));
    }
    if (!res)
        return (NULL);
    i = 0;
    while (str[i] && str[i] != '\n')
    {
        res[i] = str[i];
        i++;
    }
    if (str[i] == '\n')
        res[i++] = '\n';
    res[i] = '\0';
    return (res);
}