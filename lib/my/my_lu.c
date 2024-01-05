/*
** EPITECH PROJECT, 2023
** my_lu.c
** File description:
** Display value of unsigned long int
*/

#include "my.h"

int my_lu(unsigned long int nb, padding p)
{
    long int nb2;

    if (nb >= 10) {
        nb2 = nb % 10;
        nb = nb / 10;
        my_put_nbr(nb, p);
        my_putchar(nb2 + 48, p);
    } else {
        my_putchar(nb + 48, p);
    }
    if (p.signe == 1)
        p.signe = pad(p);
    return (0);
}
