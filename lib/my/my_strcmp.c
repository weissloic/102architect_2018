/*
** EPITECH PROJECT, 2018
** strcmp.c
** File description:
** compare 2 string
*/

#include "../../include/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int rslt = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        while (s1[i] == s2[i])
            i++;
    }
    rslt = s1[i] - s2[i];
    if (rslt < 0)
        return (-1);
    if (rslt > 0)
        return (1);
    return (0);
}
