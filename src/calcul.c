/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myradar-albin.vanden-broeck
** File description:
** my_radar.c
*/

#include "../lib/my/my.h"

static void anglechange(plane *p, float dx, float dy, display *d)
{
    float angle = (atan2(dy, dx) * 180 / M_PI) + 180;

    if (d->angle == true) {
        sfSprite_setRotation(p->sprite, angle);
        sfRectangleShape_setRotation(p->hitbox, angle);
    } else {
        sfSprite_setRotation(p->sprite, 0);
        sfRectangleShape_setRotation(p->hitbox, 0);
    }
}

movement calculate_movement(plane *p, float deltaTime, display *d)
{
    movement m;
    float dx = p->xend - p->xstart;
    float dy = p->yend - p->ystart;
    float distance = sqrt(dx * dx + dy * dy);

    anglechange(p, dx, dy, d);
    m.nx = 0;
    m.ny = 0;
    m.moveX = 0;
    m.moveY = 0;
    if (distance != 0 && p->ishere != 0) {
        m.nx = dx / distance;
        m.ny = dy / distance;
        m.moveX = m.nx * p->speed * deltaTime;
        m.moveY = m.ny * p->speed * deltaTime;
    }
    return m;
}

void update_position_and_status(plane *p, movement m, float deltaTime)
{
    float dx = p->xend - p->xstart;
    float dy = p->yend - p->ystart;
    float distance = sqrt(dx * dx + dy * dy);

    if (p->elapsedTime < p->delay) {
        p->elapsedTime += deltaTime;
        return;
    }
    if (distance <= 1) {
        p->ishere = 0;
        p->xstart = p->xend;
        p->ystart = p->yend;
        return;
    }
    p->xstart += m.moveX;
    p->ystart += m.moveY;
}

void flyplane(plane *p, float deltaTime, display *d)
{
    movement m = calculate_movement(p, deltaTime, d);

    update_position_and_status(p, m, deltaTime);
}

void updategame(display *d, planes *p_list, float deltaTime)
{
    plane *p;

    d->end = 0;
    for (planes *p_node = p_list; p_node != NULL; p_node = p_node->next) {
        p = (plane *)p_node->data;
        if (p->ishere == 1)
            d->end += 1;
        flyplane((plane *)p_node->data, deltaTime, d);
    }
}

float get_delta_time(sfClock *clock)
{
    sfTime elapsed = sfClock_restart(clock);
    float delta_time = elapsed.microseconds / 1000000.0f;

    return delta_time;
}
