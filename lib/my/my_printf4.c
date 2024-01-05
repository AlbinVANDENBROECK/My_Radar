/*
** EPITECH PROJECT, 2023
** my_printf4
** File description:
** extension to printf
*/

#include "my.h"

int blank(int *i, const char *format, va_list list, padding p)
{
    if (format[*i + 1] == ' '){
        while (format[*i + 1] == ' ') {
            (*i)++;
        }
        my_putchar(' ', p);
        return 1;
    }
    return 0;
}

int plus(int *i, const char *format, va_list list, padding p)
{
    if (format[*i + 1] == '+') {
        p.plus = 1;
        (*i)++;
    }
    return p.plus;
}

int padv2(padding p)
{
    if (p.plus == 1 && p.zero == 1) {
        my_putchar('+', p);
        p.tmp--;
        p.plus = 0;
        pad(p);
        return 0;
    }
    if (p.plus == 1 && p.zero == 0) {
        p.tmp--;
        pad(p);
        my_putchar('+', p);
        p.plus = 0;
        return 0;
    }
    p.signe = pad(p);
    return p.signe;
}

int percent4(int *i, const char *format, va_list list, padding p)
{
    int y = 0;

    for (int j = 0; j < 19; j += 2) {
        if (format[*i + 1] == tab4[j] && format[*i + 2] == tab4[j + 1]) {
            func4[y](list, p);
            (*i) += 2;
            return 0;
        }
        y++;
    }
    return 1;
}

int percent_stock(int *i, const char *format, va_list list, padding p)
{
    p.retu += percent(i, format, list, p);
    if (p.retu == 0)
        return p.retu;
    p.retu += percent2(i, format, list, p);
    if (p.retu == 1)
        return p.retu;
    p.retu += percent3(i, format, list, p);
    if (p.retu == 2)
        return p.retu;
    p.retu += percent4(i, format, list, p);
    return p.retu;
}
