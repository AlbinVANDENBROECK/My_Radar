/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** projet
*/

#include "my.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int percent(int *i, const char *format, va_list list, padding p)
{
    int y = 0;

    if (format[*i + 1] == '%') {
        my_putchar('%', p);
        (*i)++;
        return 0;
    }
    for (int j = 0; j < 13; j++) {
        if (format[*i + 1] == tab[j]) {
            func[j](list, p);
            (*i)++;
            return 0;
        }
    }
    return 1;
}

int percent2(int *i, const char *format, va_list list, padding p)
{
    int y = 0;

    for (int j = 0; j < 19; j += 2) {
        if (format[*i + 1] == tab2[j] && format[*i + 2] == tab2[j + 1]) {
            func2[y](list, p);
            (*i) += 2;
            return 0;
        }
        y++;
    }
    return 1;
}

int percent3(int *i, const char *format, va_list list, padding p)
{
    int y = 0;

    for (int j = 0; j < 28; j += 3) {
        if (format[*i + 1] == tab3[j] && format[*i + 2] == tab3[j + 1] &&
            format[*i + 3] == tab3[j + 2]) {
            func3[y](list, p);
            (*i) += 3;
            return 0;
        }
        y++;
    }
    return 1;
}

int call(const char *format, va_list ap, padding p)
{
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && format[i + 1] == '\0') {
            my_putchar('%', p);
            return 0;
        }
        p.precision = 6;
        call2(format, ap, &i, p);
    }
}

int my_printf(const char *format, ...)
{
    padding p;
    va_list ap;
    int compt_value = 0;

    p.compt = &compt_value;
    va_start(ap, format);
    call(format, ap, p);
    va_end(ap);
    return *(p.compt);
}
