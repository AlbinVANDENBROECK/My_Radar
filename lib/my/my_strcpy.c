/*
** EPITECH PROJECT, 2023
** my_strcpy.c
** File description:
** Function that copies a string into another
*/

char *my_strcpy(char *dest, char const *src)
{
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return dest;
}
