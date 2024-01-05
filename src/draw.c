/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myradar-albin.vanden-broeck
** File description:
** my_radar.c
*/

#include "../lib/my/my.h"

void isshow(display *d, plane *p)
{
    if (p->isProtected == true)
        sfRectangleShape_setOutlineColor(p->hitbox, sfRed);
    else if (p->isProtected == false)
        sfRectangleShape_setOutlineColor(p->hitbox, sfGreen);
    if (d->spriteVisible)
        sfSprite_setColor(p->sprite, sfColor_fromRGB(255, 255, 255));
    else
        sfSprite_setColor(p->sprite, sfTransparent);
    if (!d->hitboxVisible)
        sfRectangleShape_setOutlineColor(p->hitbox, sfTransparent);
}

void drawplane(display *d, planes *p_list, planes *p_node)
{
    plane *p = (plane *)p_node->data;

    if (p && p->sprite) {
        isshow(d, p);
        if (p->elapsedTime >= p->delay && p->ishere == 1) {
            sfSprite_setPosition(p->sprite, (sfVector2f){p->xstart - 20 / 2,
                p->ystart - 20 / 2});
            sfSprite_setScale(p->sprite, (sfVector2f){0.07f, 0.075f});
            sfRenderWindow_drawSprite(d->window, p->sprite, NULL);
        }
        if (p->elapsedTime >= p->delay && p->ishere == 1) {
            sfRectangleShape_setPosition(p->hitbox, (sfVector2f)
                {p->xstart - 20 / 2, p->ystart - 20 / 2});
            sfRenderWindow_drawRectangleShape(d->window, p->hitbox, NULL);
        }
    }
}

void drawtower(display *d, tours *t_list, tours *t_node)
{
    tour *t = (tour *)t_node->data;
    sfVector2u textureSize;
    sfVector2f spriteSize;

    if (t && t->sprite) {
        if (d->spriteVisible) {
            sfSprite_setPosition(t->sprite, (sfVector2f){t->x, t->y});
            sfSprite_setScale(t->sprite, (sfVector2f){0.15f, 0.15f});
            sfRenderWindow_drawSprite(d->window, t->sprite, NULL);
        }
        if (d->hitboxVisible) {
            textureSize = sfTexture_getSize(d->tourTexture);
            spriteSize = (sfVector2f){(float)textureSize.x,
                (float)textureSize.y};
            sfSprite_setOrigin(t->sprite, (sfVector2f){spriteSize.x / 2,
                spriteSize.y / 2});
            sfCircleShape_setPosition(t->circle, (sfVector2f){t->x, t->y});
            sfRenderWindow_drawCircleShape(d->window, t->circle, NULL);
        }
    }
}

void drawplanetower(display *d, planes *p_list, tours *t_list)
{
    for (planes *p_node = p_list; p_node != NULL; p_node = p_node->next) {
        drawplane(d, p_list, p_node);
    }
    for (tours *t_node = t_list; t_node != NULL; t_node = t_node->next) {
        drawtower(d, t_list, t_node);
    }
}
