/*
** EPITECH PROJECT, 2023
** my_find_prim_sup.c
** File description:
** Function wich find the smallest prime number that
** is great than, or equal to, the number given as parameter
*/

int prime(int nb)
{
    if (nb <= 2) {
        return 2;
    }
    for (int i = 2; i < nb; i++) {
        if (nb % i == 0) {
            return 0;
        }
    }
    return 1;
}

int my_find_prime_sup(int nb)
{
    int nbr = nb;

    if (nb <= 2) {
        return 2;
    }
    if (nbr % 2 == 0) {
        nbr++;
    }
    while (!prime(nbr)) {
        nbr += 2;
    }
    return nbr;
}
