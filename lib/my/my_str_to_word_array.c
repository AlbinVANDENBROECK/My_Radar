/*
** EPITECH PROJECT, 2023
** my_str_to_word_array
** File description:
** task04
*/
#include "my.h"

int my_lenarray(char **tab)
{
    int i;

    for (i = 0; tab[i] != 0; i++);
    return i;
}

int alphanumeric(char str, char separator)
{
    if (str != separator)
        return 1;
    else
        return 0;
}

int first_tab(const char *str, char separator)
{
    int o = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (alphanumeric(str[i], separator) == 1 &&
        alphanumeric(str[i + 1], separator) == 0 ||
        alphanumeric(str[i], separator) == 1 &&
        alphanumeric(str[i + 1], separator) == '\0') {
            o++;
        }
    }
    return o;
}

char remplir(int o, const char *str, char **gtab, char separator)
{
    int k;

    for (int h = 0; h < o;) {
        for (k = 0; alphanumeric(*str, separator) != 0; k++){
            gtab[h][k] = *str;
            str++;
        }
        if (h != o)
            gtab[h][k] = '\0';
        str -= k;
        if (alphanumeric(*str, separator) != 0) {
            h++;
        }
        str += k;
        k = 0;
        str++;
    }
    gtab[o] = 0;
}

char **my_str_to_word_array(char const *str, char separator)
{
    int a = 0;
    int p = 0;
    char **gtab = 0;
    int o = first_tab(str, separator);

    gtab = malloc(sizeof(char *) * (o + 1));
    for (int j = 0; str[j] != '\0'; j++) {
        if (alphanumeric(str[j], separator) == 1) {
            a++;
        }
        if ((alphanumeric(str[j], separator) == 0
            && (j > 0 && alphanumeric(str[j - 1], separator) == 1)) ||
            (alphanumeric(str[j], separator) == 1 && str[j + 1] == '\0')) {
            gtab[p] = malloc(sizeof(char) * (a + 1));
            a = 0;
            p++;
        }
    }
    remplir(o, str, gtab, separator);
    return gtab;
}
