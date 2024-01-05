/*
** EPITECH PROJECT, 2023
** hexa_len.c
** File description:
** return len
*/

#include "my.h"
#include <stdio.h>

int hexa_len(unsigned long int n, int i)
{
    char tab[] = {"0123456789abcdef"};
    int rest = 0;

    if (n != 0) {
        rest = n % 16;
        i = hexa_len(n / 16, i);
        i++;
    }
    return i;
}
