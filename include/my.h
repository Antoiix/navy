/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** contains all of prototypes
*/

#ifndef MY_H
    #define MY_H
    #include <stdio.h>
    #include <unistd.h>
    #include <stdint.h>
    #include <time.h>
    #include <limits.h>
    #include <stdarg.h>
    #include <errno.h>
    #include <math.h>
    #include <stdlib.h>
    #include <string.h>
    #include <fcntl.h>
    #include "sys/stat.h"
    #include "signal.h"
    #define GET_PID (-1)

typedef enum op_binary {
    ADD_ZERO,
    ADD_ONE,
    GET,
    CLEAR
} op_bin_t;
char **my_str_to_word_array(char const *str, char *pattern);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_isalpha(char str);
int my_isnum(char str);
int mini_printf(const char *format, ...);
int my_pf_put_nbr(int nb, int *count);
void my_pf_putchar(char c, int *count);
int my_pf_putstr(char const *str, int *count);
void navy_launch(char **navy_pos, int ac, char *pid_enemy);
char *my_strdup(char const *src);
void int_to_signal(int decimal_val, int enemy_pid);
void handler(int signo, siginfo_t *info, void *context);
int add_binary(op_bin_t a);
int add_pid_enemy(int a);
void print_maps(char **map, char **empty_map);
void init_maps(char **map, char **empty_map, char **navy_pos);
int place_to_int(char *place);
void launcher_p1(char **empty_map, char **map, char **navy_pos, int get_value);
void launcher_p2(char **empty_map, char **map, char **navy_pos, int get_value);
void game_conditionsp1(int enemy_pid, int get_value,
    char **empty_map, char **map);
void game_conditionsp2(int enemy_pid, int get_value,
    char **empty_map, char **map);
void place_p1_attack(int ints[3], int get_value, size_t *size, char **buf);
void hit_reaction_p1(int get_value, int ints[3], char **empty_map, char *buf);
void miss_reaction_p1(int get_value, int ints[3], char **empty_map, char *buf);
void send_att_p1(int get_value, char **map, int map_turn, int enemy_pid);
void place_p2_attack(int ints[4], int get_value, size_t *size, char **buf);
void miss_reaction_p2(int get_value, int ints[4], char **empty_map, char *buf);
void hit_reaction_p2(int get_value, int ints[4], char **empty_map, char *buf);
void send_att_p2(int get_value, char **map, int enemy_pid);

#endif
