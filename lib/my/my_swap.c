/*
** EPITECH PROJECT, 2023
** my_swap.c
** File description:
** Function wich swaps the content of to integers
*/
void my_swap(void **a, void **b)
{
    void *temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
