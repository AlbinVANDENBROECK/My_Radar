/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myradar-albin.vanden-broeck
** File description:
** free_file.c
*/

#include "../lib/my/my.h"

static void free_background(display *d)
{
    if (d->backgroundSprite)
        sfSprite_destroy(d->backgroundSprite);
    if (d->backgroundTexture)
        sfTexture_destroy(d->backgroundTexture);
    if (d->planeTexture)
        sfTexture_destroy(d->planeTexture);
    if (d->tourTexture)
        sfTexture_destroy(d->tourTexture);
}

static void free_planes(planes **p_list)
{
    planes *temp;

    while (*p_list) {
        temp = *p_list;
        *p_list = (*p_list)->next;
        if (((plane *)temp->data)->sprite)
            sfSprite_destroy(((plane *)temp->data)->sprite);
        if (((plane *)temp->data)->hitbox)
            sfRectangleShape_destroy(((plane *)temp->data)->hitbox);
        free(temp->data);
        free(temp);
    }
}

static void free_tours(tours **t_list)
{
    tours *temp;

    while (*t_list) {
        temp = *t_list;
        *t_list = (*t_list)->next;
        if (((tour *)temp->data)->sprite)
            sfSprite_destroy(((tour *)temp->data)->sprite);
        free(temp->data);
        free(temp);
    }
}

static void free_file_buffer2(files *file, int i)
{
    for (int j = 0; file->buffer[i][j]; j++) {
        free(file->buffer[i][j]);
    }
}

static void free_file_buffer(files *file)
{
    if (file->buffer) {
        for (int i = 0; file->buffer[i]; i++) {
            free_file_buffer2(file, i);
            free(file->buffer[i]);
        }
        free(file->buffer);
    }
    if (file->buff) {
        free(file->buff);
    }
}

static void free_grid(display *d)
{
    for (int i = 0; i < d->gridWidth; i++) {
        free(d->grid[i]);
    }
    free(d->grid);
}

void free_all(display *d, planes *p_list, tours *t_list)
{
    free_background(d);
    free_planes(&p_list);
    free_tours(&t_list);
    free_grid(d);
    free_file_buffer(d->file);
    sfFont_destroy(d->font);
    if (d->totalElapsedTimeClock) {
        sfClock_destroy(d->totalElapsedTimeClock);
    }
    if (d->window)
        sfRenderWindow_destroy(d->window);
    free(d);
}
