/*
** EPITECH PROJECT, 2023
** 1printf.c
** File description:
** wrapper
*/

#include "my.h"

int my_p_putchar(va_list list, padding p)
{
    int a = 0;
    int len = 1;
    char m;

    a = va_arg(list, int);
    p.tmp = p.taille - len;
    if (p.signe == 0) {
        pad(p);
        return my_putchar((char)a, p);
    }
    return my_putcharv2((char) a, p);
}

int my_p_put_nbr(va_list list, padding p)
{
    int a = 0;
    int len;
    char m;

    a = va_arg(list, int);
    len = my_len_nbr(a);
    p.tmp = p.taille - len;
    if (a < 0)
        p.plus = 0;
    if (a < 0 && p.zero == 1) {
        my_putchar('-', p);
        a = -a;
    }
    if (p.signe == 0) {
        padv2(p);
        return my_put_nbrpad(a, p);
    }
    my_p_put_nbr2(p);
    return my_put_nbrpad(a, p);
}

int my_p_putstr(va_list list, padding p)
{
    char const *a;
    int len;
    char m;

    a = va_arg(list, char const *);
    len = my_strlen(a);
    p.tmp = p.taille - len;
    if (p.signe == 0) {
        pad(p);
        return my_putstr(a, p);
    }
    return my_putstr(a, p);
}

int my_p_hexa(va_list list, padding p)
{
    unsigned int a;
    int len;
    char m;

    a = va_arg(list, unsigned int);
    len = hexa_len(a, 0);
    p.tmp = p.taille - len;
    if (p.hash >= 1 && p.zero != 0) {
        my_putchar('0', p);
        my_putchar('x', p);
    }
    if (p.signe == 0) {
        pad(p);
        return hexa(a, p);
    }
    return hexa(a, p);
}

int my_p_hexa_cap(va_list list, padding p)
{
    unsigned int a;
    int len;
    char m;

    a = va_arg(list, unsigned int);
    len = hexa_len(a, 0);
    p.tmp = p.taille - len;
    if (p.hash >= 1 && p.zero != 0) {
        my_putchar('0', p);
        my_putchar('X', p);
    }
    if (p.signe == 0) {
        pad(p);
        return hexa_cap(a, p);
    }
    return hexa_cap(a, p);
}
