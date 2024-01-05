/*
** EPITECH PROJECT, 2023
** hexa.c
** File description:
** print hexa
*/

#include "my.h"
#include <stdio.h>

int hexav2(unsigned int n, padding p)
{
    char tab[] = {"0123456789abcdef"};
    int rest = 0;

    if (n != 0) {
        rest = n % 16;
        hexav2(n / 16, p);
        my_putchar(tab[rest], p);
    }
}

int hexa(unsigned int n, padding p)
{
    char tab[] = {"0123456789abcdef"};
    int rest = 0;

    if (p.hash >= 1 && p.zero == 0) {
        my_putchar('0', p);
        my_putchar('x', p);
    }
    if (n != 0) {
        rest = n % 16;
        hexav2(n / 16, p);
        my_putchar(tab[rest], p);
    }
    if (p.signe == 1) {
        p.signe = pad(p);
    }
}
