/*
** EPITECH PROJECT, 2023
** my_hd
** File description:
** Display short int
*/

#include "my.h"

int my_hd(short nb, padding p)
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
        p.signe = pad(p);
    return (0);
}
