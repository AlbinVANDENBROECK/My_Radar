/*
** EPITECH PROJECT, 2023
** 2printf.c
** File description:
** wrapper
*/

#include "my.h"

int my_p_point2(padding p)
{
    if (p.plus == 1) {
        my_putchar('+', p);
        p.plus = 0;
        p.tmp--;
    }
}

double my_p_putfloat2(padding p, double a)
{
    if (a < 0 && p.zero == 1) {
        my_putchar('-', p);
        a = -a;
    }
    return a;
}

int my_p_e2(padding p, double a)
{
    if (p.plus == 1) {
        my_putchar('+', p);
        p.plus = 0;
        p.tmp--;
    }
}

double my_p_e3(padding p, double a)
{
    if (a < 0 && p.zero == 1) {
        my_putchar('-', p);
        a = -a;
    }
    return a;
}

double my_p_cape2(padding p)
{
    if (p.plus == 1) {
        my_putchar('+', p);
        p.plus = 0;
        p.tmp--;
    }
}
