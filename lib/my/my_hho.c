/*
** EPITECH PROJECT, 2023
** my_ho.c
** File description:
** display unsigned short int on octal
*/

#include "my.h"

int my_hho2(unsigned char n, padding p)
{
    char tab[] = {"012345678"};
    unsigned long int rest = 0;

    if (n != 0) {
        rest = n % 8;
        my_hho2(n / 8, p);
        my_putchar(tab[rest], p);
    }
}

int my_hho(unsigned char n, padding p)
{
    char tab[] = {"012345678"};
    unsigned long int rest = 0;

    if (p.hash >= 1 && p.zero == 0) {
        if (p.signe == 0) {
            my_putchar(' ', p);
            my_putchar('0', p);
        } else
            my_putchar('0', p);
    }
    if (n != 0) {
        rest = n % 8;
        my_hho2(n / 8, p);
        my_putchar(tab[rest], p);
    }
    if (p.signe != 0 && p.hash >= 1)
        my_putchar(' ', p);
    if (p.signe == 1)
        p.signe = pad(p);
}
