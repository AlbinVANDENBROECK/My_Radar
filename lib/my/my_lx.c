/*
** EPITECH PROJECT, 2023
** my_lx.c
** File description:
** Display unsigned long int in hexadecimal notation
*/

#include "my.h"

int my_lx2(unsigned long int n, padding p)
{
    char tab[] = {"0123456789abcdef"};
    unsigned long int rest = 0;

    if (n != 0) {
        rest = n % 16;
        my_lx2(n / 16, p);
        my_putchar(tab[rest], p);
    }
}

int my_lx(unsigned long int n, padding p)
{
    char tab[] = {"0123456789abcdef"};
    unsigned long int rest = 0;

    if (p.hash >= 1 && p.zero == 0) {
        my_putchar('0', p);
        my_putchar('x', p);
    }
    if (n != 0) {
        rest = n % 16;
        my_lx2(n / 16, p);
        my_putchar(tab[rest], p);
    }
    if (p.signe == 1)
        p.signe = pad(p);
}
