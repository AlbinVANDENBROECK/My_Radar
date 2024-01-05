/*
** EPITECH PROJECT, 2023
** point
** File description:
** Reproduce %p to display pointer adress
*/

#include <stdio.h>
#include "my.h"

long point2_len(long n, int i)
{
    char tab[] = {"0123456789abcdef"};
    long rest = 0;

    if (n != 0) {
        rest = n % 16;
        i = point2_len(n / 16, i);
        i++;
    }
    return i;
}

int point_len(long n, int i)
{
    i = i + 2;
    i = point2_len(n, i);
    return i;
}
