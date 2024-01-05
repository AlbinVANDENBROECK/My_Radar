/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myradar-albin.vanden-broeck
** File description:
** my_radar.c
*/

#include "../lib/my/my.h"

int split_buffer_into_lines(display *d, char ***lines)
{
    *lines = my_str_to_word_array(d->file->buff, '\n');
    return my_lenarray(*lines);
}

void process_lines_and_update_buffer(display *d, char **lines, int num_lines)
{
    char *newLine;
    int len;

    d->file->buffer = malloc(sizeof(char **) * (num_lines + 1));
    for (int i = 0; i < num_lines; i++) {
        len = my_strlen(lines[i]);
        if (len > 0 && lines[i][len - 1] != ' ') {
            newLine = malloc(len + 2);
            my_strcpy(newLine, lines[i]);
            newLine[len] = ' ';
            newLine[len + 1] = '\0';
            d->file->buffer[i] = my_str_to_word_array(newLine, ' ');
            free(newLine);
        } else {
            d->file->buffer[i] = my_str_to_word_array(lines[i], ' ');
        }
    }
    d->file->buffer[num_lines] = NULL;
}

void reset_grid(display *d)
{
    for (int i = 0; i < d->gridWidth; i++) {
        for (int j = 0; j < d->gridHeight; j++) {
            d->grid[i][j] = NULL;
        }
    }
}

static void update_grid2(int gridx, int gridy, display *d, plane *p)
{
    if (gridx >= 0 && gridx < d->gridWidth && gridy >= 0 &&
        gridy < d->gridHeight) {
        d->grid[gridx][gridy] = p;
    }
}

void update_grid_with_planes(display *d, planes *p_list)
{
    int gridx;
    int gridy;
    plane *p;

    for (planes *p_node = p_list; p_node != NULL; p_node = p_node->next) {
        p = (plane *)p_node->data;
        if (p && p->ishere == 1) {
            d->hitboxPos = sfRectangleShape_getPosition(p->hitbox);
            d->hitboxSize = sfRectangleShape_getSize(p->hitbox);
            d->centerX = d->hitboxPos.x + d->hitboxSize.x / 2.0f;
            d->centerY = d->hitboxPos.y + d->hitboxSize.y / 2.0f;
            gridx = (int)(d->centerX / 20.0f);
            gridy = (int)(d->centerY / 20.0f);
            update_grid2(gridx, gridy, d, p);
        }
    }
}

void collisionsgrid(display *d, planes *p_list)
{
    reset_grid(d);
    update_grid_with_planes(d, p_list);
}
