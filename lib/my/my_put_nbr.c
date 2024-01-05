/*
** EPITECH PROJECT, 2023
** my_put_nbr.c
** File description:
** Function wich displays number given as parameter
*/

#include "my.h"
int my_put_nbr2(long int nb, long int nb2, padding p)
{
    if (nb < 0) {
        my_putchar('-', p);
        nb = -nb;
    }
    if (nb >= 10) {
        nb2 = nb % 10;
        nb = nb / 10;
        my_put_nbr2(nb, nb2, p);
        my_putchar(nb2 + 48, p);
    } else {
        my_putchar(nb + 48, p);
    }
}

int my_put_nbr(long int nb, padding p)
{
    long int nb2;

    if (nb < 0) {
        my_putchar('-', p);
        nb = -nb;
    }
    if (nb >= 10) {
        nb2 = nb % 10;
        nb = nb / 10;
        my_put_nbr2(nb, nb2, p);
        my_putchar(nb2 + 48, p);
    } else {
        my_putchar(nb + 48, p);
    }
    return (0);
}

int my_put_nbrpad(long int nb, padding p)
{
    long int nb2;

    if (nb < 0) {
        my_putchar('-', p);
        nb = -nb;
    }
    if (nb >= 10) {
        nb2 = nb % 10;
        nb = nb / 10;
        my_put_nbr2(nb, nb2, p);
        my_putchar(nb2 + 48, p);
    } else {
        my_putchar(nb + 48, p);
    }
    if (p.signe == 1)
        p.signe = pad(p);
    return (0);
}
