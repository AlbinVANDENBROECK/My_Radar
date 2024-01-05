/*
** EPITECH PROJECT, 2023
** my_strcat.c
** File description:
** Concatenats two strings
*/
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    char *origin = malloc(my_strlen(dest) + my_strlen(src) + 1);
    int i;
    int j;

    if (origin == NULL) {
        return NULL;
    }
    i = 0;
    while (dest[i] != '\0') {
        origin[i] = dest[i];
        i++;
    }
    j = 0;
    while (src[j] != '\0') {
        origin[i] = src[j];
        i++;
        j++;
    }
    origin[i] = '\0';
    return origin;
}
