/*
** EPITECH PROJECT, 2023
** oct_len.c
** File description:
** return len of octal
*/

#include "my.h"
#include <stdio.h>

int oct_len(unsigned long int n, int i)
{
    char tab[] = {"012345678"};
    int rest = 0;

    if (n != 0) {
        rest = n % 8;
        i = oct_len(n / 8, i);
        i++;
    }
    return i;
}
