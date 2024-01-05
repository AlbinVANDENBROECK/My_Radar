/*
** EPITECH PROJECT, 2023
** my_putchar.C
** File description:
** display char
*/
#include "my.h"
#include <unistd.h>

int my_putchar(char c, padding p)
{
    write(1, &c, 1);
    (*(p.compt))++;
    return 0;
}

int my_putcharv2(char c, padding p)
{
    write(1, &c, 1);
    (*(p.compt))++;
    if (p.signe == 1)
        p.signe = pad(p);
    return 0;
}
