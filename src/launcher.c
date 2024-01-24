/*
** EPITECH PROJECT, 2024
** navy
** File description:
** launcher.c
*/

#include "my.h"

void launcher_p1(char **empty_map, char **map, char **navy_pos, int get_value)
{
    if (get_value == 255) {
        mini_printf("enemy connected\n\n");
        add_binary(CLEAR);
        int_to_signal(255, add_pid_enemy(GET_PID));
        init_maps(map, empty_map, navy_pos);
        print_maps(map, empty_map);
    }
    game_conditionsp1(add_pid_enemy(GET_PID), get_value, empty_map, map);
}

void launcher_p2(char **empty_map, char **map, char **navy_pos, int get_value)
{
    if (get_value == 255) {
        mini_printf("successfully connected to enemy\n\n");
        add_binary(CLEAR);
        init_maps(map, empty_map, navy_pos);
        print_maps(map, empty_map);
        int_to_signal(100, add_pid_enemy(GET_PID));
    }
    game_conditionsp2(add_pid_enemy(GET_PID), get_value, empty_map, map);
}
