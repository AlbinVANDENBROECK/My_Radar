/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myradar-albin.vanden-broeck
** File description:
** my_radar.c
*/

#include "../lib/my/my.h"

static void drawelapsedtime2(display *d, sfText *planes)
{
    sfText_setCharacterSize(d->text, 75);
    sfText_setCharacterSize(planes, 75);
    sfText_setCharacterSize(d->textplanes, 75);
    sfText_setFont(d->text, d->font);
    sfText_setFont(planes, d->font);
    sfText_setFont(d->textplanes, d->font);
    sfText_setPosition(d->text, (sfVector2f){d->mode.width - 75 -
        (my_strlen(d->time) * 20), 10});
    sfText_setPosition(d->textplanes, (sfVector2f){d->mode.width - 1650, 10});
    sfText_setPosition(planes, (sfVector2f){d->mode.width - 1920, 10});
    sfRenderWindow_drawText(d->window, d->text, NULL);
    sfRenderWindow_drawText(d->window, planes, NULL);
    sfRenderWindow_drawText(d->window, d->textplanes, NULL);
    sfText_destroy(d->text);
    sfText_destroy(planes);
    sfText_destroy(d->textplanes);
}

void drawelapsedtime(display *d)
{
    sfTime elapsed = sfClock_getElapsedTime(d->totalElapsedTimeClock);
    int time = elapsed.microseconds / 1000000;
    char *str = "Planes :";
    sfText *planes = sfText_create();

    d->textplanes = sfText_create();
    d->text = sfText_create();
    inttostr(time, d->time);
    inttostr(d->end, d->planes);
    sfText_setString(d->text, d->time);
    sfText_setString(planes, str);
    sfText_setString(d->textplanes, d->planes);
    drawelapsedtime2(d, planes);
}

void keypressed(sfEvent *event, display *d)
{
    if (event->type == sfEvtKeyPressed) {
        if (event->key.code == sfKeyL) {
            d->hitboxVisible = !d->hitboxVisible;
        }
        if (event->key.code == sfKeyS) {
            d->spriteVisible = !d->spriteVisible;
        }
        if (event->key.code == sfKeyA) {
            d->angle = !d->angle;
        }
    }
}

void analyse_events(sfEvent *event, display *d)
{
    while (sfRenderWindow_pollEvent(d->window, event)) {
        if (event->type == sfEvtClosed) {
            sfRenderWindow_close(d->window);
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            sfRenderWindow_close(d->window);
        }
        keypressed(event, d);
    }
}

void window(display *d, planes *p, tours *t)
{
    sfEvent Event;
    sfClock *clock = sfClock_create();
    float deltaTime;

    while (sfRenderWindow_isOpen(d->window)) {
        sfRenderWindow_clear(d->window, sfBlack);
        deltaTime = get_delta_time(clock);
        updategame(d, p, deltaTime);
        collisionsgrid(d, p);
        collisionsplane(d, t);
        sfRenderWindow_drawSprite(d->window, d->backgroundSprite, NULL);
        drawplanetower(d, p, t);
        drawelapsedtime(d);
        analyse_events(&Event, d);
        sfRenderWindow_display(d->window);
        if (d->end == 0)
            break;
    }
    my_printf("Program ended successfully !\n");
    sfClock_destroy(clock);
}

int tty(char **env, int display)
{
    for (int i = 0; env[i]; i++) {
        if (my_strcmp(env[i], "DISPLAY=:0") == 0)
            display = 1;
    }
    return display;
}
