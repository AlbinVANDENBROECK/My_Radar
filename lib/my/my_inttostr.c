/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myhunter-albin.vanden-broeck
** File description:
** my_inttostr.c
*/

#include "my.h"

void inttostr(int number, char *str)
{
    int num = number;
    int numDigits = 0;
    int temp = num;
    char *current;

    while (temp != 0) {
        numDigits++;
        temp /= 10;
    }
    current = str + numDigits;
    *current = '\0';
    if (num == 0)
        *current = '0';
    while (num != 0) {
        current--;
        *current = '0' + (num % 10);
        num /= 10;
    }
}
