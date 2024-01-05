/*
** EPITECH PROJECT, 2023
** wrapper_5.c
** File description:
** wrapper_5
*/

#include "my.h"

int my_p_hhu(va_list list, padding p)
{
    unsigned int a;
    int len;
    char m;

    a = va_arg(list, unsigned int);
    len = my_len_nbr((unsigned char) a);
    p.tmp = p.taille - len;
    if (p.signe == 0) {
        pad(p);
        return my_hhu(a, p);
    }
    return my_hhu(a, p);
}

int my_p_hhd(va_list list, padding p)
{
    int a;
    int len;
    char m;

    a = va_arg(list, int);
    len = my_len_nbr((signed char) a);
    p.tmp = p.taille - len;
    if (a < 0 && p.zero == 1) {
        my_putchar('-', p);
        a = -a;
    }
    if (p.signe == 0) {
        padv2(p);
        return my_hhd(a, p);
    }
    my_p_hhd2(p);
    return my_hhd(a, p);
}

int my_p_hhx(va_list list, padding p)
{
    unsigned int a;
    int len;
    char m;

    a = va_arg(list, unsigned int);
    len = hexa_len((unsigned char) a, 0);
    p.tmp = p.taille - len;
    if (p.hash >= 1 && p.zero != 0) {
        my_putchar('0', p);
        my_putchar('x', p);
    }
    if (p.signe == 0) {
        pad(p);
        return my_hhx(a, p);
    }
    return my_hhx(a, p);
}

int my_p_hho(va_list list, padding p)
{
    unsigned int a;
    int len;
    char m;

    a = va_arg(list, unsigned int);
    len = oct_len((unsigned char) a, 0);
    p.tmp = p.taille - len;
    if (p.hash >= 1 && p.zero != 0) {
        my_putchar('0', p);
        my_putchar('0', p);
    }
    if (p.signe == 0) {
        pad(p);
        return my_hho(a, p);
    }
    return my_hho(a, p);
}

int my_p_hhcapx(va_list list, padding p)
{
    unsigned int a;
    int len;
    char m;

    a = va_arg(list, unsigned int);
    len = hexa_len((unsigned char)a, 0);
    p.tmp = p.taille - len;
    if (p.hash >= 1 && p.zero != 0) {
        my_putchar('0', p);
        my_putchar('X', p);
    }
    if (p.signe == 0) {
        pad(p);
        return my_hhcapx(a, p);
    }
    return my_hhcapx(a, p);
}
