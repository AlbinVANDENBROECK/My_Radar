/*
** EPITECH PROJECT, 2023
** point
** File description:
** Reproduce %p to display pointer adress
*/

#include <stdio.h>
#include "my.h"

long point2(long n, padding p)
{
    char tab[] = {"0123456789abcdef"};
    long rest = 0;

    if (n != 0) {
        rest = n % 16;
        point2(n / 16, p);
        my_putchar(tab[rest], p);
    }
}

int point(long n, padding p)
{
    my_putchar('0', p);
    my_putchar('x', p);
    point2(n, p);
    if (p.signe == 1)
        p.signe = pad(p);
}
