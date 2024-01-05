/*
** EPITECH PROJECT, 2023
** my_printf5.c
** File description:
** extension my_printf.c
*/

#include "my.h"

int hashtag(int *i, const char *format, va_list list, padding p)
{
    if (format[*i + 1] == '#') {
        (*i)++;
        p.hash += 1;
    }
    return p.hash;
}
