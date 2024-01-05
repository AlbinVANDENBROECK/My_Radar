/*
** EPITECH PROJECT, 2023
** wrapper_5.c
** File description:
** wrapper_5
*/

#include "my.h"

int my_p_hx(va_list list, padding p)
{
    unsigned int a;
    int len;
    char m;

    a = va_arg(list, unsigned int);
    len = hexa_len((unsigned short) a, 0);
    p.tmp = p.taille - len;
    if (p.hash >= 1 && p.zero != 0) {
        my_putchar('0', p);
        my_putchar('x', p);
    }
    if (p.signe == 0) {
        pad(p);
        return my_hx(a, p);
    }
    return my_hx(a, p);
}

int my_p_lo(va_list list, padding p)
{
    unsigned long int a;
    int len;
    char m;

    a = va_arg(list, unsigned long int);
    len = oct_len(a, 0);
    p.tmp = p.taille - len;
    if (p.hash >= 1 && p.zero != 0) {
        my_putchar('0', p);
        my_putchar('0', p);
    }
    if (p.signe == 0) {
        pad(p);
        return my_lo(a, p);
    }
    return my_lo(a, p);
}

int my_p_lcapx(va_list list, padding p)
{
    unsigned long int a;
    int len;
    char m;

    a = va_arg(list, unsigned long int);
    len = hexa_len(a, 0);
    p.tmp = p.taille - len;
    if (p.hash >= 1 && p.zero != 0) {
        my_putchar('0', p);
        my_putchar('X', p);
    }
    if (p.signe == 0) {
        pad(p);
        return my_lcapx(a, p);
    }
    return my_lcapx(a, p);
}

int my_p_ho(va_list list, padding p)
{
    unsigned int a;
    int len;
    char m;

    a = va_arg(list, unsigned int);
    len = oct_len((unsigned short) a, 0);
    p.tmp = p.taille - len;
    if (p.hash >= 1 && p.zero != 0) {
        my_putchar('0', p);
        my_putchar('0', p);
    }
    if (p.signe == 0) {
        pad(p);
        return my_ho(a, p);
    }
    return my_ho(a, p);
}

int my_p_hcapx(va_list list, padding p)
{
    unsigned int a;
    int len;
    char m;

    a = va_arg(list, unsigned int);
    len = hexa_len((unsigned short) a, 0);
    p.tmp = p.taille - len;
    if (p.hash >= 1 && p.zero != 0) {
        my_putchar('0', p);
        my_putchar('X', p);
    }
    if (p.signe == 0) {
        pad(p);
        return my_hcapx(a, p);
    }
    return my_hcapx(a, p);
}
