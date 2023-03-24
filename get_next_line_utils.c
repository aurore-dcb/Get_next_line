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