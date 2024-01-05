/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myradar-albin.vanden-broeck
** File description:
** init1.c
*/

#include "../lib/my/my.h"

void init_buffer(display *d)
{
    char **lines;
    int num_lines = split_buffer_into_lines(d, &lines);

    process_lines_and_update_buffer(d, lines, num_lines);
}

void initialize_display_settings(display *d)
{
    d->mode.width = 1920;
    d->mode.height = 1080;
    d->mode.bitsPerPixel = 32;
    d->window = sfRenderWindow_create(d->mode, "myradar", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(d->window, 60);
    d->totalElapsedTimeClock = sfClock_create();
    d->hitboxVisible = true;
    d->spriteVisible = true;
    d->end = 1;
    d->angle = false;
}

int initialize_textures_and_grid(display *d)
{
    d->backgroundTexture = sfTexture_createFromFile("assets/fond.png", NULL);
    d->planeTexture = sfTexture_createFromFile("assets/plane.png", NULL);
    d->tourTexture = sfTexture_createFromFile("assets/tower.png", NULL);
    d->font = sfFont_createFromFile("assets/dino.ttf");
    if (!d->backgroundTexture || !d->planeTexture || !d->tourTexture ||
        !d->font) {
        return 84;
    }
    d->backgroundSprite = sfSprite_create();
    sfSprite_setTexture(d->backgroundSprite, d->backgroundTexture, sfTrue);
    d->gridWidth = d->mode.width / 20;
    d->gridHeight = d->mode.height / 20;
    d->grid = malloc(d->gridWidth * sizeof(plane**));
    for (int i = 0; i < d->gridWidth; i++) {
        d->grid[i] = malloc(d->gridHeight * sizeof(plane*));
    }
    memset(d->time, 0, sizeof(d->time));
    return 0;
}

int init_param(display *d)
{
    d->file = malloc(sizeof(files));
    initialize_display_settings(d);
    return (initialize_textures_and_grid(d));
}
