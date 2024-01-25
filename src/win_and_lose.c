/*
** EPITECH PROJECT, 2024
** navy
** File description:
** win_and_lose.c
*/

#include "my.h"

void lose_condition(char **map, int i, int j, int *is_in)
{
    if ('0' <= map[i][j] && map[i][j] <= '9')
        *is_in = 1;
}

void lose_loop(char **map, int enemy_pid, char **empty_map, int get_value)
{
    int is_in = 0;

    if (get_value == 255 || get_value == 0)
        return;
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            lose_condition(map, i, j, &is_in);
        }
    }
    if (is_in == 0) {
        print_maps(map, empty_map);
        mini_printf("Enemy won\n");
        add_pid_enemy(-3);
    }
}

void win_condition(char **map, int i, int j, int *count_x)
{
    if (map[i][j] == 'x')
        *count_x = *count_x + 1;
}

void win_loop(char **map, int enemy_pid, char **empty_map, int get_value)
{
    int count_x = 0;

    if (get_value == 255 || get_value == 0)
        return;
    for (int i = 0; empty_map[i] != NULL; i++) {
        for (int j = 0; empty_map[i][j] != '\0'; j++) {
            win_condition(empty_map, i, j, &count_x);
        }
    }
    if (count_x == 14) {
        print_maps(map, empty_map);
        mini_printf("I won\n");
        add_pid_enemy(-2);
    }
}
