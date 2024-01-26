/*
** EPITECH PROJECT, 2024
** navy
** File description:
** abs.c
*/

#include "my.h"

int abs(int x)
{
    if (x < 0)
        return -1 * x;
    else
        return x;
}

int check_correct_pos(char **navy_pos, int *exit, int i)
{
    if ((navy_pos[i + 1][0] >= 'A') && ('H' >= navy_pos[i + 1][0]) &&
        ('1' <= navy_pos[i + 1][1]) && ('8' >= navy_pos[i + 1][1]) &&
        my_strlen(navy_pos[i + 1]) == 2)
        *exit = *exit + 1;
    if ((navy_pos[i + 2][0] >= 'A') && ('H' >= navy_pos[i + 2][0]) &&
        ('1' <= navy_pos[i + 2][1]) && ('8' >= navy_pos[i + 2][1]) &&
        my_strlen(navy_pos[i + 2]) == 2)
        *exit = *exit + 1;
    if ((navy_pos[i + 1][0] != navy_pos[i + 2][0]) && (navy_pos[i + 1][1]
    != navy_pos[i + 2][1]))
        return 84;
    if (abs(navy_pos[i + 1][0] - navy_pos[i + 2][0]) !=
        my_getnbr(navy_pos[i]) - 1 && abs(navy_pos[i + 1][1]
        - navy_pos[i + 2][1]) != my_getnbr(navy_pos[i]) - 1)
        return 84;
    return 0;
}
