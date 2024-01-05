/*
** EPITECH PROJECT, 2023
** my_strncmp.c
** File description:
** Reproduce function strncmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int result = 0;

    for (int i = 0; i < n && *s1 != 0 && *s2 != 0; i++) {
        if (*s1 == *s2) {
            s1++;
            s2++;
        }
        if (*s1 != *s2) {
            result = (*s1 - *s2);
        }
    }
    return result;
}
