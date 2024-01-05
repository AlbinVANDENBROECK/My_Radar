/*
** EPITECH PROJECT, 2023
** my_printf3.c
** File description:
** extension my_printf.c
*/
#include "my.h"

int signe(int *i, const char *format, va_list list, padding p)
{
    if (format[*i + 1] == '-') {
        p.signe = 1;
        p.zero = 0;
        (*i)++;
    } else {
        p.signe = 0;
    }
    return p.signe;
}

int pad(padding p)
{
    if (p.zero == 0) {
        for (int i = 0; i < p.tmp; i++) {
            my_putchar(' ', p);
        }
    } else {
        for (int i = 0; i < p.tmp; i++)
        my_putchar('0', p);
    }
    p.signe = 0;
    return p.signe;
}

int zeropad(int *i, const char *format, va_list list, padding p)
{
    if (format[*i + 1] == '0') {
        p.zero = 1;
    } else {
        p.zero = 0;
    }
    return p.zero;
}

int my_flag(int *i, const char *format, padding p, int taille)
{
    if (format[*i + 1] - '0' >= 0 && format[*i + 1] - '0' <= 9) {
        taille = my_len(i, format, p, taille);
    }
    if (p.truee == 1)
        taille -= 1;
    if (p.hash >= 1)
        taille -= 2 * p.hash;
    return taille;
}

float my_put_floatpad(double calcul, padding p)
{
    long int nombre = calcul;
    int i = 0;
    int *tab_two = malloc(sizeof(int) * (p.precision + 1));

    for (int j = 0; j < p.precision + 1; j++)
        tab_two[j] = 0;
    calcul -= nombre;
    nombre = is_nega(calcul, nombre, p);
    if (0 != calcul)
        my_put_float2(calcul * 10.0f, i, &tab_two, p);
    nombre = last(&tab_two, p, nombre);
    my_put_nbr(nombre, p);
    my_putchar('.', p);
    for (int j = 0; j < p.precision; j++)
        my_putchar(tab_two[j] + '0', p);
    free(tab_two);
    if (p.signe == 1)
        p.signe = pad(p);
    return 0;
}
