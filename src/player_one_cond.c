/*
** EPITECH PROJECT, 2024
** navy
** File description:
** player_one_cond.c
*/

#include "my.h"

void place_p1_attack(int ints[3], int get_value, size_t *size, char **buf)
{
    if (get_value == 100 || ints[2] == 1) {
        ints[2] = 1;
        if (ints[1] == 0)
            int_to_signal(100, add_pid_enemy(GET_PID));
        ints[1] = 1;
        mini_printf("attack: ");
        getline(buf, size, stdin);
        ints[0] = place_to_int(*buf);
        if ((ints[0] >= 11 && ints[0] <= 88) && ints[0] % 10 != 0 &&
        ints[0] % 10 != 9 && ('A' <= (*buf)[0]) && ('H' >= (*buf)[0]) &&
        ('1' <= (*buf)[1]) && ('8' >= (*buf)[1]) && my_strlen(*buf) == 3) {
            ints[2] = 0;
            add_binary(CLEAR);
            int_to_signal(place_to_int(*buf), add_pid_enemy(GET_PID));
        } else
            mini_printf("\nwrong position\n\n");
    }
}

void hit_reaction_p1(int get_value, int ints[3], char **empty_map, char *buf)
{
    if (get_value == 99) {
        ints[2] = 0;
        mini_printf("\nresult: %c%c:hit\n\n", buf[0], buf[1]);
        empty_map[ints[0] / 10 - 1][ints[0] % 10 - 1] = 'x';
        ints[1] = 0;
        add_binary(CLEAR);
        int_to_signal(200, add_pid_enemy(GET_PID));
    }
}

void miss_reaction_p1(int get_value, int ints[3], char **empty_map, char *buf)
{
    if (get_value == 98) {
        ints[2] = 0;
        mini_printf("\nresult: %c%c:missed\n\n", buf[0], buf[1]);
        if (empty_map[ints[0] / 10 - 1][ints[0] % 10 - 1] != 'x')
            empty_map[ints[0] / 10 - 1][ints[0] % 10 - 1] = 'o';
        ints[1] = 0;
        add_binary(CLEAR);
        int_to_signal(200, add_pid_enemy(GET_PID));
    }
}

void same_position_p1(char **map, int get_value)
{
    if (map[get_value / 10 - 1][get_value % 10 - 1] != 'x')
        map[get_value / 10 - 1][get_value % 10 - 1] = 'o';
}

void send_att_p1(int get_value, char **map, int *map_turn, int enemy_pid)
{
    if ((get_value >= 11 && get_value <= 88) &&
        get_value % 10 != 0 && get_value % 10 != 9) {
        if (map[get_value / 10 - 1][get_value % 10 - 1] != '.' &&
            map[get_value / 10 - 1][get_value % 10 - 1] != 'o' &&
            map[get_value / 10 - 1][get_value % 10 - 1] != 'x') {
            map[get_value / 10 - 1][get_value % 10 - 1] = 'x';
            mini_printf("result: %c%c:hit\n\n", (get_value % 10 + 64),
                (get_value / 10 + 48));
            int_to_signal(99, enemy_pid);
            *map_turn = 1;
        } else {
            same_position_p1(map, get_value);
            mini_printf("result: %c%c:missed\n\n", (get_value % 10 + 64),
                (get_value / 10 + 48));
            int_to_signal(98, enemy_pid);
            *map_turn = 1;
        }
        add_binary(CLEAR);
    }
}
