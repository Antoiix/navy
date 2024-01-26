/*
** EPITECH PROJECT, 2024
** navy
** File description:
** map_gestion.c
*/

#include "my.h"

void vertical_fill(int a, char **navy_pos, int k, char **map)
{
    if (navy_pos[k + 1][0] == navy_pos[k + 2][0]) {
        a = place_to_int(navy_pos[k + 1]);
        for (int l = 0; l < my_getnbr(navy_pos[k]); l++) {
            map[a / 10 - 1][a % 10 - 1] = (my_getnbr(navy_pos[k]) + 48);
            a += 10;
        }
    }
}

void horizontal_fill(int a, char **navy_pos, int k, char **map)
{
    if (navy_pos[k + 1][1] == navy_pos[k + 2][1]) {
        a = place_to_int(navy_pos[k + 1]);
        for (int l = 0; l < my_getnbr(navy_pos[k]); l++) {
            map[a / 10 - 1][a % 10 - 1] = (my_getnbr(navy_pos[k]) + 48);
            a += 1;
        }
    }
}

void fill_map(char **map, char **navy_pos)
{
    int a = 0;

    for (int k = 0; k != 12; k = k + 3) {
        vertical_fill(a, navy_pos, k, map);
        horizontal_fill(a, navy_pos, k, map);
    }
}

void init_maps(char **map, char **empty_map, char **navy_pos)
{
    for (int i = 0; i < 8; i++) {
        map[i] = malloc(sizeof(char) * 9);
        for (int j = 0; j < 8; j++) {
            map[i][j] = '.';
        }
        map[i][8] = '\0';
    }
    fill_map(map, navy_pos);
    for (int i = 0; i < 8; i++) {
        empty_map[i] = malloc(sizeof(char) * 9);
        for (int j = 0; j < 8; j++) {
            empty_map[i][j] = '.';
        }
        empty_map[i][8] = '\0';
    }
}

void print_maps(char **map, char **empty_map)
{
    mini_printf("my_navy:\n |A B C D E F G H\n-+---------------\n");
    for (int i = 0; i != 8; i++) {
        mini_printf("%d|", i + 1);
        for (int j = 0; j != 8; j++)
            mini_printf("%c ", map[i][j]);
        mini_printf("\n");
    }
    mini_printf("\nenemy navy:\n |A B C D E F G H\n-+---------------\n");
    for (int i = 0; i != 8; i++) {
        mini_printf("%d|", i + 1);
        for (int j = 0; j != 8; j++)
            mini_printf("%c ", empty_map[i][j]);
        mini_printf("\n");
    }
    mini_printf("\n");
}
