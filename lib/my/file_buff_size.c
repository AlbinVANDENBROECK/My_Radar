/*
** EPITECH PROJECT, 2023
** B-CPE-110-LIL-1-1-settingup-albin.vanden-broeck
** File description:
** file_buff_size.c
*/

#include "my.h"

int file_buff_size(char const *file_path, files *file)
{
    struct stat stats;

    file->fd = open(file_path, O_RDONLY);
    if (file->fd == -1) {
        my_printf("Incorrect FilePath\n");
        return 84;
    }
    stat(file_path, &stats);
    file->size = stats.st_size;
    file->buff = malloc(sizeof(char) * (file->size + 1));
    read(file->fd, file->buff, file->size);
    file->buff[file->size] = '\0';
    return 0;
}
