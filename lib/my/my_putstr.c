/*
** EPITECH PROJECT, 2023
** my_putstr.c
** File description:
** Function wich display, one-by-one the char of a string
*/

#include "my.h"

int my_putstr(char const *str, padding p)
{
    while (*str != '\0') {
        my_putchar(*str, p);
        str++;
    }
    if (p.signe == 1)
        p.signe = pad(p);
    return 0;
}
