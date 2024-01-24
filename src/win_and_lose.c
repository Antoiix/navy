/*
** EPITECH PROJECT, 2024
** navy
** File description:
** win_and_lose.c
*/

#include "my.h"

void win_condition(char **map, int i, int j, int *is_in)
{
    if ('0' <= map[i][j] && map[i][j] <= '9')
        *is_in = 1;
}

void win_loop(char **map, int enemy_pid, char **empty_map, int get_value)
{
    int is_in = 0;

    if (get_value == 255 || get_value == 0)
        return;
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            win_condition(map, i, j, &is_in);
        }
    }
    if (is_in == 0) {
        print_maps(map, empty_map);
        int_to_signal(166, enemy_pid);
        int_to_signal(199, getpid());
    }
}
