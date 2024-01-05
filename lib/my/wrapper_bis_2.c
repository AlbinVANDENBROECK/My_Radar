/*
** EPITECH PROJECT, 2023
** 2printf.c
** File description:
** wrapper
*/

#include "my.h"

long my_p_ld2(padding p)
{
    if (p.plus == 1) {
        my_putchar('+', p);
        p.plus = 0;
        p.tmp--;
    }
}

int my_p_hd2(padding p)
{
    if (p.plus == 1) {
        my_putchar('+', p);
        p.plus = 0;
        p.tmp--;
    }
}

int my_p_hhd2(padding p)
{
    if (p.plus == 1) {
        my_putchar('+', p);
        p.plus = 0;
        p.tmp--;
    }
}
