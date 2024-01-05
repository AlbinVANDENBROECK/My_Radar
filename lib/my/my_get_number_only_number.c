/*
** EPITECH PROJECT, 2023
** B-CPE-110-LIL-1-1-settingup-albin.vanden-broeck
** File description:
** my_get_number_only_number.c
*/

#include "my.h"

int my_get_number_only_number(char *str, int *taille)
{
    *taille = 0;
    if (!str)
        return 84;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9'){
            return 84;
        } else
            *taille = *taille * 10 + str[i] - 48;
    }
    return 0;
}
