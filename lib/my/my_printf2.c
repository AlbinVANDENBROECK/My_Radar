/*
** EPITECH PROJECT, 2023
** my_printf2.c
** File description:
** extension my_printf.c
*/

#include "my.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

void exceptions(const char *format, int *i, padding p)
{
    if (format[*i + 1] == 'l' || format[*i + 1] == 'h' ||
    format[*i + 1] == 'L')
        (*i)++;
    if (format[*i + 1] == 'l' || format[*i + 1] == 'h')
        (*i)++;
    my_putchar('%', p);
    if (p.taille != 0)
        my_put_nbr(p.taille, p);
}

int call2(const char *format, va_list ap, int *i, padding p)
{
    p.retu = 0;
    p.hash = 0;
    p.plus = 0;
    if (format[*i] == '%') {
        p.truee = blank(i, format, ap, p);
        p.plus = plus(i, format, ap, p);
        p.hash = hashtag(i, format, ap, p);
        p.zero = zeropad(i, format, ap, p);
        p.signe = signe(i, format, ap, p);
        p.hash = hashtag(i, format, ap, p);
        p.plus = plus(i, format, ap, p);
        p.taille = my_flag(i, format, p, 0);
        p.precision = my_point_precision(i, format, ap, p);
        p.retu = percent_stock(i, format, ap, p);
    } else {
        my_putchar(format[*i], p);
    }
    if (p.retu == 4)
        exceptions(format, i, p);
    p.retu = 0;
}

int my_precision(int *i, const char *format, va_list list, int t)
{
    if (t == 0) {
        t = t + format[*i + 2] - '0';
    } else {
        t = (t * 10) + format[*i + 1] - '0';
    }
    return t;
}

int my_len(int *i, const char *format, padding p, int taille)
{
    taille += format[*i + 1] - '0';
    (*i)++;
    if (format[*i + 1] - '0' >= 0 && format[*i + 1] - '0' <= 9) {
        taille = my_len(i, format, p, taille * 10);
    }
    return taille;
}

int my_point_precision(int *i, const char *format, va_list list, padding p)
{
    int t = 0;

    if (format[*i + 1] == '.') {
        p.precision = my_precision(i, format, list, t);
        (*i) += 2;
        if (format[*i + 1] - '0' >= 0 && format[*i + 1] - '0' <= 9) {
            p.precision = my_len(i, format, p, p.precision * 10);
        }
        t = 0;
    }
    return p.precision;
}
