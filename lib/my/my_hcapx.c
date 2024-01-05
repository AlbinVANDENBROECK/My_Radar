/*
** EPITECH PROJECT, 2023
** my_hcapx.c
** File description:
** display unsigned short in hexadecimal notation
*/


#include "my.h"

int my_hcapx2(unsigned short n, padding p)
{
    char tab[] = {"0123456789ABCDEF"};
    unsigned long int rest = 0;

    if (n != 0) {
        rest = n % 16;
        my_hcapx2(n / 16, p);
        my_putchar(tab[rest], p);
    }
}

int my_hcapx(unsigned short n, padding p)
{
    char tab[] = {"0123456789ABCDEF"};
    unsigned long int rest = 0;

    if (p.hash >= 1 && p.zero == 0) {
        my_putchar('0', p);
        my_putchar('X', p);
    }
    if (n != 0) {
        rest = n % 16;
        my_hcapx2(n / 16, p);
        my_putchar(tab[rest], p);
    }
    if (p.signe == 1)
        p.signe = pad(p);
}
