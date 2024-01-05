/*
** EPITECH PROJECT, 2023
** wrapper4.c
** File description:
** wrapper_4
*/

#include "my.h"

int my_p_ld(va_list list, padding p)
{
    long a = 0;
    int len;
    char m;

    a = va_arg(list, long int);
    len = my_len_nbr(a);
    p.tmp = p.taille - len;
    if (a < 0 && p.zero == 1) {
        my_putchar('-', p);
        a = -a;
    }
    if (p.signe == 0) {
        padv2(p);
        return my_ld(a, p);
    }
    my_p_ld2(p);
    return my_ld(a, p);
}

int my_p_lu(va_list list, padding p)
{
    unsigned long int a;
    int len;
    char m;

    a = va_arg(list, unsigned long int);
    len = my_len_nbr(a);
    p.tmp = p.taille - len;
    if (p.signe == 0) {
        pad(p);
        return my_lu(a, p);
    }
    return my_lu(a, p);
}

int my_p_lx(va_list list, padding p)
{
    unsigned long int a;
    int len;
    char m;

    a = va_arg(list, unsigned long int);
    len = hexa_len(a, 0);
    p.tmp = p.taille - len;
    if (p.hash >= 1 && p.zero != 0) {
        my_putchar('0', p);
        my_putchar('x', p);
    }
    if (p.signe == 0) {
        pad(p);
        return my_lx(a, p);
    }
    return my_lx(a, p);
}

int my_p_hd(va_list list, padding p)
{
    int a = 0;
    int len;
    char m;

    a = va_arg(list, int);
    len = my_len_nbr((short)a);
    p.tmp = p.taille - len;
    if (a < 0 && p.zero == 1) {
        my_putchar('-', p);
        a = -a;
    }
    if (p.signe == 0) {
        padv2(p);
        return my_hd(a, p);
    }
    my_p_hd2(p);
    return my_hd(a, p);
}

int my_p_hu(va_list list, padding p)
{
    unsigned int a;
    int len;

    a = va_arg(list, unsigned int);
    len = my_len_nbr((unsigned short)a);
    p.tmp = p.taille - len;
    if (p.signe == 0) {
        pad(p);
        return my_hu(a, p);
    }
    return my_hu(a, p);
}
