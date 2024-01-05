/*
** EPITECH PROJECT, 2023
** my_len_int_c
** File description:
** len int
*/

int my_counter(int i, long int nb2)
{
    i++;
    if (nb2 >= 10) {
        i = my_counter(i, nb2 / 10);
    }
    return i;
}

int my_len_nbr(double nb)
{
    long int nb2 = nb;
    int i = 0;

    if (nb2 < 0) {
        i++;
        nb2 = -nb2;
    }
    if (nb2 >= 10) {
        i = my_counter(i, nb2);
    }
    if (nb2 > 0 && nb2 < 9)
        i += 1;
    return i;
}
