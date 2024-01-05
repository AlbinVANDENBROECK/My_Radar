/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myradar-albin.vanden-broeck
** File description:
** init1.c
*/

#include "../lib/my/my.h"

void create_and_set_tour2(display *d, tour *t, tours **t_list)
{
    t->sprite = sfSprite_create();
    t->circle = sfCircleShape_create();
    sfCircleShape_setRadius(t->circle, (t->radius * 1920) / 100);
    sfCircleShape_setOrigin(t->circle, (sfVector2f)
        {(t->radius * 1920) / 100, (t->radius * 1920) / 100});
    sfCircleShape_setFillColor(t->circle, sfTransparent);
    sfCircleShape_setOutlineColor(t->circle, sfRed);
    sfCircleShape_setOutlineThickness(t->circle, 4.0f);
    sfSprite_setTexture(t->sprite
            , d->tourTexture, sfTrue);
    push_to_list_tour(t_list, t);
}

void create_and_set_plane2(display *d, plane *p, planes **p_list)
{
    p->sprite = sfSprite_create();
    sfSprite_setTexture(p->sprite
            , d->planeTexture, sfTrue);
    p->hitbox = sfRectangleShape_create();
    sfRectangleShape_setSize(p->hitbox, (sfVector2f){20, 20});
    sfRectangleShape_setFillColor(p->hitbox, sfTransparent);
    sfRectangleShape_setOutlineColor(p->hitbox, sfGreen);
    sfRectangleShape_setOutlineThickness(p->hitbox, 2.0f);
    p->elapsedTime = 0;
    p->ishere = 1;
    p->isProtected = false;
    push_to_list_plane(p_list, p);
}

int create_and_set_tour(display *d, char **line, tours **t_list)
{
    int taille;
    tour *t = malloc(sizeof(tour));

    if (my_get_number_only_number(line[1], &taille) == 84)
        return 84;
    t->x = taille;
    if (my_get_number_only_number(line[2], &taille) == 84)
        return 84;
    t->y = taille;
    if (my_get_number_only_number(line[3], &taille) == 84)
        return 84;
    t->radius = taille;
    create_and_set_tour2(d, t, t_list);
    return 0;
}

static int create_and_set_plane3(char **line, int taille, plane *p)
{
    if (my_get_number_only_number(line[1], &taille) == 84)
        return 84;
    p->xstart = taille;
    if (my_get_number_only_number(line[2], &taille) == 84)
        return 84;
    p->ystart = taille;
    if (my_get_number_only_number(line[3], &taille) == 84)
        return 84;
    p->xend = taille;
    if (my_get_number_only_number(line[4], &taille) == 84)
        return 84;
    p->yend = taille;
    if (my_get_number_only_number(line[5], &taille) == 84)
        return 84;
    p->speed = taille;
    if (my_get_number_only_number(line[6], &taille) == 84)
        return 84;
    p->delay = taille;
    return 0;
}

int create_and_set_plane(display *d, char **line, planes **p_list)
{
    plane *p = malloc(sizeof(plane));
    int taille;

    if (create_and_set_plane3(line, taille, p) == 84)
        return 84;
    create_and_set_plane2(d, p, p_list);
    return 0;
}

static int process_line(display *d, char **line, planes **p_list,
    tours **t_list)
{
    if (line[0][0] == 'A' && !line[0][1]) {
        return create_and_set_plane(d, line, p_list);
    } else if (line[0][0] == 'T' && !line[0][1]) {
        return create_and_set_tour(d, line, t_list);
    }
    return 84;
}

int init_lists(display *d, planes **p_list, tours **t_list)
{
    char **line;
    int error = 0;
    int result;

    for (int i = 0; d->file->buffer[i] != NULL; i++) {
        line = d->file->buffer[i];
        result = process_line(d, line, p_list, t_list);
        if (result == 84) {
            return 84;
        }
        error += result;
    }
    if (error != 0)
        return 84;
    return 0;
}
