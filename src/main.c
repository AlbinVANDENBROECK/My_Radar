/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myradar-albin.vanden-broeck
** File description:
** my_radar.c
*/

#include "../lib/my/my.h"

void printfonc()
{
    my_printf("Air traffic simulation panel\n\n"
        "USAGE\n"
        "./my_radar [OPTIONS] path_to_script\n"
        "path_to_script The path to the script file.\n\n"
        "INFORMATION\n"
        "All collisions are calculated relative to the base\n"
        "hitboxes, the orientation of the hitboxes is only\n"
        "visual and does not affect the calculations.\n\n"
        "COLORS\n"
        "'RED' : detected by a tower.\n"
        "'GREEN' : not detected by a tower.\n\n"
        "OPTIONS\n"
        "-h print the usage and quit.\n\n"
        "USER INTERACTIONS\n"
        "'A' key enable/disable orientation of the planes\n"
        "‘L’ key enable/disable hitboxes and areas.\n"
        "‘S’ key enable/disable sprites.\n");
}

int validate_arguments(int ac)
{
    if (ac == 1 || ac > 2) {
        my_printf("./my_radar: bad arguments\nretry with -h\n");
        return 84;
    }
    return 0;
}

int print_help_if_requested(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        printfonc();
        return 1;
    }
    return 0;
}

int initialize_display_and_lists(display *d, char *filename
    , planes **p, tours **t)
{
    if (init_param(d) == 84) {
        my_printf("Invalid Assets\n");
        return 84;
    }
    if (file_buff_size(filename, d->file) == 84) {
        return 84;
    }
    init_buffer(d);
    if (init_lists(d, p, t) == 84) {
        my_printf("Invalid FileContent\n");
        return 84;
    }
    return 0;
}

static int basic_error(char **env)
{
    int display = 0;

    if (!env || !env[0])
        return 84;
    display = tty(env, display);
    if (!display)
        return 84;
    return 0;
}

int main(int ac, char **av, char **env)
{
    display *d = malloc(sizeof(display));
    planes *p = NULL;
    tours *t = NULL;

    if (basic_error(env) == 84)
        return 84;
    if (validate_arguments(ac) == 84)
        return 84;
    if (print_help_if_requested(ac, av) == 1)
        return 0;
    if (initialize_display_and_lists(d, av[1], &p, &t) == 84) {
        free_all(d, p, t);
        return 84;
    }
    window(d, p, t);
    free_all(d, p, t);
    return 0;
}
