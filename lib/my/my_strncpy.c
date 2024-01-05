/*
** EPITECH PROJECT, 2023
** my_strncpy.c
** File description:
** Function that copies n characters from a string into another
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; i < n; i++) {
        *dest = *src;
        dest++;
        src++;
    }
    if (n > my_strlen(src)) {
        *dest = '\0';
    }
    return dest;
}
