/*
** EPITECH PROJECT, 2023
** wrapper_2.c
** File description:
** wrapper
*/

#include "my.h"

int my_p_oct(va_list list, padding p)
{
    unsigned int a;
    int len;
    char m;

    a = va_arg(list, unsigned int);
    len = oct_len(a, 0);
    p.tmp = p.taille - len;
    if (p.hash >= 1 && p.zero != 0) {
        my_putchar('0', p);
        my_putchar('0', p);
    }
    if (p.signe == 0) {
        pad(p);
        return oct(a, p);
    }
    return oct(a, p);
}

int my_p_put_unbr(va_list list, padding p)
{
    unsigned int a;
    int len;
    char m;

    a = va_arg(list, unsigned int);
    len = my_len_nbr(a);
    p.tmp = p.taille - len;
    if (p.signe == 0) {
        pad(p);
        return my_put_unbr(a, p);
    }
    return my_put_unbr(a, p);
}

int my_p_point(va_list list, padding p)
{
    long a;
    int len;
    char m;

    a = va_arg(list, long);
    len = point_len(a, 0);
    p.tmp = p.taille - len;
    if (a < 0) {
        my_putchar('-', p);
        a = -a;
    }
    if (p.signe == 0) {
        padv2(p);
        return point(a, p);
    }
    my_p_point2(p);
    return point(a, p);
}

int my_p_putfloat(va_list list, padding p)
{
    double a;
    int len;
    char m;

    a = va_arg(list, double);
    len = my_len_nbr(a) + p.precision + 1;
    p.tmp = p.taille - len;
    a = my_p_putfloat2(p, a);
    if (p.signe == 0) {
        padv2(p);
        return my_put_float(a, p);
    }
    if (p.plus == 1) {
        my_putchar('+', p);
        p.plus = 0;
        p.tmp--;
    }
    return my_put_floatpad(a, p);
}

int my_p_e(va_list list, padding p)
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
    a = my_p_e3(p, a);
    if (p.signe == 0) {
        padv2(p);
        return my_e(a, p);
    }
    my_p_e2(p, a);
    return my_e(a, p);
}
