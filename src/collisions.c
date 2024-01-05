/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myradar-albin.vanden-broeck
** File description:
** my_radar.c
*/

#include "../lib/my/my.h"

bool isneartower(display *d, plane *p, tours *t_list)
{
    float radius;
    float dx;
    float dy;
    float distance;
    tour *t;

    for (tours *t_node = t_list; t_node != NULL; t_node = t_node->next) {
        t = (tour *)t_node->data;
        radius = sfCircleShape_getRadius(t->circle);
        dx = p->xstart - t->x;
        dy = p->ystart - t->y;
        distance = sqrt(dx * dx + dy * dy);
        if (distance <= radius) {
            return true;
        }
    }
    return false;
}

void update_protection_status(display *d, int x, int y, tours *t_list)
{
    if (d->grid[x][y] == NULL)
        return;
    d->grid[x][y]->isProtected = isneartower(d, d->grid[x][y], t_list);
}

static int check_for_collision(display *d, int x, int y, int dir[2])
{
    int newX = x + dir[0];
    int newY = y + dir[1];

    if (newX >= 0 && newX < d->gridWidth && newY >= 0 &&
        newY < d->gridHeight) {
        if (d->grid[newX][newY] != NULL && d->grid[newX][newY] !=
            d->grid[x][y]) {
            d->grid[x][y]->ishere = 0;
            return 1;
        }
    }
    return 0;
}

void detect_collision(display *d, int x, int y)
{
    int dirs[8][2] = {
        {-1, -1}, {0, -1}, {1, -1},
        {-1, 0}, {1, 0},
        {-1, 1}, {0, 1}, {1, 1}
    };

    if (d->grid[x][y] == NULL || d->grid[x][y]->isProtected)
        return;
    for (int i = 0; i < 8; i++) {
        if (check_for_collision(d, x, y, dirs[i])) {
            break;
        }
    }
}

void checkcollision(display *d, int x, int y, tours *t_list)
{
    update_protection_status(d, x, y, t_list);
    detect_collision(d, x, y);
}

void collisionsplane(display *d, tours *t_list)
{
    for (int i = 0; i < d->gridWidth; i++) {
        for (int j = 0; j < d->gridHeight; j++) {
            checkcollision(d, i, j, t_list);
        }
    }
}
