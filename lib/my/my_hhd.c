/*
** EPITECH PROJECT, 2023
** my_hhd
** File description:
** Display int with signed char
*/

#include "my.h"

int my_hhd(signed char nb, padding p)
{
    long int nb2;

    if (nb < 0) {
        my_putchar('-', p);
        nb = -nb;
    }
    if (nb >= 10) {
        nb2 = nb % 10;
        nb = nb / 10;
        my_put_nbr(nb, p);
        my_putchar(nb2 + 48, p);
    } else {
        my_putchar(nb + 48, p);
    }
    if (p.signe == 1)
        p.signe = padv2(p);
    return (0);
}
