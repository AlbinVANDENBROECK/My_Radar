/*
** EPITECH PROJECT, 2023
** organized
** File description:
** my_strdup.c
*/

#include "my.h"

char *my_strdup(const char *src)
{
    char *dest;

    if (!src)
        return NULL;
    dest = malloc(sizeof(char) * my_strlen(src) + 1);
    if (!dest)
        return NULL;
    my_strcpy(dest, src);
    return dest;
}
