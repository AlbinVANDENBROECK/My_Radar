/*
** EPITECH PROJECT, 2023
** my_strstr.c
** File description:
** Function reproduce strstr function
*/

int find(char *str, char const *to_find)
{
    while (*str && *to_find && (*str == *to_find)) {
        str++;
        to_find++;
    }
    if (*to_find == '\0') {
        return 1;
    }
    if (*str == '\0') {
        return 0;
    }
}

char *my_strstr(char *str, char const *to_find)
{
    while (str[0] != 0) {
        if (find(str, to_find) == 1) {
            return str;
        }
        str++;
    }
    return 0;
}
