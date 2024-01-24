/*
** EPITECH PROJECT, 2024
** navy
** File description:
** game_conditions.c
*/

#include "my.h"

void game_conditionsp1(int enemy_pid, int get_value,
    char **empty_map, char **map)
{
    static char *buf = NULL;
    size_t size;
    static int map_turn = 0;
    static int ints[3] = {0};

    if (map_turn == 1) {
        print_maps(map, empty_map);
        map_turn = 0;
    }
    place_p1_attack(ints, get_value, &size, &buf);
    hit_reaction_p1(get_value, ints, empty_map, buf);
    miss_reaction_p1(get_value, ints, empty_map, buf);
    if (get_value == 200) {
        mini_printf("waiting for enemy's attack...\n\n");
        add_binary(CLEAR);
    }
    send_att_p1(get_value, map, map_turn, enemy_pid);
}

void game_conditionsp2(int enemy_pid, int get_value,
    char **empty_map, char **map)
{
    static char *buf = NULL;
    size_t size;
    static int ints[4] = {0};

    if (ints[3] == 1) {
        print_maps(map, empty_map);
        ints[3] = 0;
    }
    if (get_value == 100) {
        mini_printf("waiting for enemy's attack...\n\n");
        add_binary(CLEAR);
    }
    place_p2_attack(ints, get_value, &size, &buf);
    hit_reaction_p2(get_value, ints, empty_map, buf);
    miss_reaction_p2(get_value, ints, empty_map, buf);
    send_att_p2(get_value, map, enemy_pid);
}
