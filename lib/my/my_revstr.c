/*
** EPITECH PROJECT, 2023
** my_revstr.c
** File description:
** Function that reverses a string
*/

char *my_revstr(char *str)
{
    char *ptr;
    char *ptr2;
    char c;

    ptr = str;
    ptr2 = str;
    while (*ptr2 != '\0') {
        ptr2 ++;
    }
    ptr2--;
    while (ptr <= ptr2) {
        c = *ptr;
        *ptr = *ptr2;
        *ptr2 = c;
        ptr2--;
        ptr++;
    }
    return str;
}
