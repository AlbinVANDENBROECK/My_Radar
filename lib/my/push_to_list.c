/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myradar-albin.vanden-broeck
** File description:
** push_to_list.c
*/

#include "my.h"

void push_to_list_plane(planes **begin, plane *data)
{
    planes *newNode;

    if (!begin || !data)
        return;
    newNode = malloc(sizeof(planes));
    if (!newNode)
        return;
    newNode->data = data;
    newNode->next = *begin;
    *begin = newNode;
}

void push_to_list_tour(tours **begin, tour *data)
{
    tours *newNode;

    if (!begin || !data)
        return;
    newNode = malloc(sizeof(tours));
    if (!newNode)
        return;
    newNode->data = data;
    newNode->next = *begin;
    *begin = newNode;
}
