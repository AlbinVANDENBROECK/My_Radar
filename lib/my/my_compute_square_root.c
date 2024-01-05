/*
** EPITECH PROJECT, 2023
** my_compute_square_root.c
** File description:
** Function wich returns the square root of the number
** given as argument, if is not a while number, return 0
*/

int my_compute_square_root(int nb)
{
    int pow = 1;

    if (pow < 0) {
        return 0;
    }
    while (pow * pow <= nb) {
        if (pow * pow == nb) {
            return pow;
        }
        pow++;
    }
    return 0;
}
