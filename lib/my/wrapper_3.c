/*
** EPITECH PROJECT, 2023
** 3printf.c
** File description:
** wrapper
*/

#include "my.h"

int my_p_cape(va_list list, padding p)
{
    double risque;
    int len;
    int c = 0;
    double a = va_arg(list, double);

    risque = 0.0000000000000000000000000000000000000000000001 *
        0.00000000000000000000000000000000000000000000000000001;
    if (a <= risque)
        c += 1;
    len = 6 + p.precision + c;
    p.tmp = p.taille - len;
    if (a < 0 && p.zero == 1) {
        my_putchar('-', p);
        a = -a;
    }
    if (p.signe == 0) {
        padv2(p);
        return my_cape(a, p);
    }
    return my_cape(a, p);
}

int my_p_n(va_list list, padding p)
{
    return my_n(va_arg(list, int *), p);
}

int my_p_put_nbr2(padding p)
{
    if (p.plus == 1) {
        my_putchar('+', p);
        p.plus = 0;
        p.tmp--;
    }
}
