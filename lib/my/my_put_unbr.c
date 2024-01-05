/*
** EPITECH PROJECT, 2023
** my_put_unbr
** File description:
** unsigned int putnbr
*/

#include "my.h"

int my_put_unbrv2(unsigned int nombre, padding p)
{
    if (nombre / 10) {
        my_put_unbrv2(nombre / 10, p);
    }
    my_putchar(48 + (nombre % 10), p);
}

int my_put_unbr(unsigned int nombre, padding p)
{
    if (nombre / 10){
        my_put_unbrv2(nombre / 10, p);
    }
    my_putchar(48 + (nombre % 10), p);
    if (p.signe == 1)
        p.signe = pad(p);
    return 0;
}
