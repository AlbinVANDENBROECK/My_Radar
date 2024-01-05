/*
** EPITECH PROJECT, 2023
** my_put_float
** File description:
** my_put_float
*/

#include "my.h"
#include <stdlib.h>

float my_put_float2(double calcul, int i, int **tab_two, padding p)
{
    long int nombre = calcul;
    long int dernier = nombre % 10;

    p.precision + 1;
    if (dernier < 0)
        dernier = -dernier;
    (*tab_two)[i] = dernier;
    calcul -= nombre;
    if (0 != calcul && i < (p.precision)) {
        i++;
        my_put_float2(calcul * 10.0f, i, tab_two, p);
    }
    return 0;
}

long int number(int i, int **tab_two, long int nombre)
{
    for (i = i - 1; (*tab_two)[i] == 10; i--) {
        (*tab_two)[i] = 0;
        if (i == 0) {
            nombre += 1;
            return nombre;
        }
        (*tab_two)[i - 1] += 1;
    }
    return nombre;
}

long int last(int **tab_two, padding p, long int nombre)
{
    int i = p.precision;

    if ((*tab_two)[i] > 4 && (*tab_two)[i] < 10) {
        (*tab_two)[i - 1] += 1;
        nombre = number(i, tab_two, nombre);
    }
    return nombre;
}

long int is_nega(double calcul, long int nombre, padding p)
{
    if (calcul < 0 && calcul > -1) {
        my_putchar('-', p);
        nombre = -nombre;
    }
    return nombre;
}

float my_put_float(double calcul, padding p)
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
    return 0;
}
