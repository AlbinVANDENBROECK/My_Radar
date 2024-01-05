/*
** EPITECH PROJECT, 2023
** my_strlen.C
** File description:
** Function wich returns the number of characters
*/

int my_strlen(char const *str)
{
    int comp = 0;

    while (*str != '\0') {
        comp++;
        str++;
    }
    return comp;
}
