/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:41:25 by aducobu           #+#    #+#             */
/*   Updated: 2023/05/14 13:51:26 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int main(int argc, char **argv)
{
    int fd;
    int fd1;
    int fd2;
    int fd3;
    char *ligne1;
    char *ligne2;
    char *ligne3;
    
    ligne1 = "ok";
    ligne2 = "ok";
    ligne3 = "ok";
    if (argc == 1)
    {
        fd = 1;
        while (ligne1 != NULL)
        {
            ligne1 = get_next_line(fd);
            if (ligne1 != NULL)
            {
                printf("resultat : %s\n", ligne1);
                free(ligne1);
            }
        }
        close(fd);
    }
    else if (argc == 4)
    {
        printf("3 fichiers\n");
        fd1 = open(argv[1], O_RDONLY);
        if (fd1 == -1)
            return (0);
        fd2 = open(argv[2], O_RDONLY);
        if (fd2 == -1)
            return (0);
        fd3 = open(argv[3], O_RDONLY);
        if (fd3 == -1)
            return (0);
        while (ligne1 || ligne2 || ligne3)
        {
            if (!ligne1)
                close(fd1);
            else
            {
                ligne1 = get_next_line(fd1);
                if (ligne1 != NULL)
                {
                    printf("1 : %s\n", ligne1);
                    free(ligne1);
                }
            }
            if (!ligne2)
                close(fd2);
            else
            {
                ligne2 = get_next_line(fd2);
                if (ligne2 != NULL)
                {
                    printf("2 : %s\n", ligne2);
                    free(ligne2);
                }
            }
            if (!ligne3)
                close(fd3);
            else
            {
                ligne3 = get_next_line(fd3);
                if (ligne3 != NULL)
                {
                    printf("3 : %s\n", ligne3);
                    free(ligne3);
                }
            }
        }
    }
    return (0);
}