/*
** EPITECH PROJECT, 2023
** my_compute_power_rec.c
** File description:
** Recursive function that returns the first argument
** raised to the power of the second
*/

int my_compute_power_rec(int nb, int p)
{
    int res = nb;

    if (p == 0) {
        return 1;
    }
    if (p < 0) {
        return 0;
    } else {
        res = nb * my_compute_power_rec(nb, p - 1);
        if (res > 2147483647) {
            return 0;
        }
        return res;
    }
}
