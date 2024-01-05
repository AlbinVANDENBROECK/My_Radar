/*
** EPITECH PROJECT, 2023
** my_e.c
** File description:
** display the scientific notation of the number
*/

#include "my.h"
#include <stdio.h>


int my_e_pos(double n, padding p)
{
    long int nombre = n;
    int compte = 0;

    if (n < 0) {
        my_putchar('-', p);
        nombre = -nombre;
        n = -n;
    }
    while (nombre > 10) {
        n = n / 10;
        nombre = nombre / 10;
        compte++;
    }
    my_put_float(n, p);
    my_putchar('e', p);
    my_putchar('+', p);
    if (compte <= 9)
        my_putchar('0', p);
    my_put_nbr(compte, p);
}

int my_e_neg(double n, padding p)
{
    int compte = 0;

    if (n < 0) {
        my_putchar('-', p);
        n = -n;
    }
    while (n < 1) {
        n = n * 10;
        compte++;
    }
    my_put_float(n, p);
    my_putchar('e', p);
    my_putchar('-', p);
    if (compte <= 9)
        my_putchar('0', p);
    my_put_nbr(compte, p);
}

int my_e(double n, padding p)
{
    if (n < 1 && n > -1) {
        my_e_neg(n, p);
    } else {
        my_e_pos(n, p);
    }
    if (p.signe == 1)
        p.signe = pad(p);
}
