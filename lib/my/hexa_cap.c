/*
** EPITECH PROJECT, 2023
** hexa_cap
** File description:
** printf number in X with capital letter
*/

#include "my.h"
#include <stdio.h>

int hexa_capv2(unsigned int n, padding p)
{
    char tab[] = {"0123456789ABCDEF"};
    int rest = 0;

    if (n != 0) {
        rest = n % 16;
        hexa_capv2(n / 16, p);
        my_putchar(tab[rest], p);
    }
}

int hexa_cap(unsigned int n, padding p)
{
    char tab[] = {"0123456789ABCDEF"};
    int rest = 0;

    if (p.hash >= 1 && p.zero == 0) {
        my_putchar('0', p);
        my_putchar('X', p);
    }
    if (n != 0) {
        rest = n % 16;
        hexa_capv2(n / 16, p);
        my_putchar(tab[rest], p);
    }
    if (p.signe == 1)
        p.signe = pad(p);
}
