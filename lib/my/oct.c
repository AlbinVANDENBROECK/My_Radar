/*
** EPITECH PROJECT, 2023
** oct.c
** File description:
** display number with 8 base.
*/

#include "my.h"

int octv2(unsigned int n, padding p)
{
    char tab[] = {"012345678"};
    int rest = 0;

    if (n != 0) {
        rest = n % 8;
        octv2(n / 8, p);
        my_putchar(tab[rest], p);
    }
}

int oct(unsigned int n, padding p)
{
    char tab[] = {"012345678"};
    int rest = 0;

    if (p.hash >= 1 && p.zero == 0) {
        if (p.signe == 0) {
            my_putchar(' ', p);
            my_putchar('0', p);
        } else
            my_putchar('0', p);
    }
    if (n != 0) {
        rest = n % 8;
        octv2(n / 8, p);
        my_putchar(tab[rest], p);
    }
    if (p.signe != 0 && p.hash >= 1)
        my_putchar(' ', p);
    if (p.signe == 1)
        p.signe = pad(p);
}
