/*
** EPITECH PROJECT, 2024
** navy
** File description:
** index_gestion.c
*/

#include "my.h"

int add_binary(op_bin_t a)
{
    static int data = 0;

    if (a == GET)
        return data;
    if (a == CLEAR)
        data = 0;
    if (a == ADD_ZERO)
        data = (data << 1) | 0;
    if (a == ADD_ONE)
        data = (data << 1) | 1;
    return 0;
}

int add_pid_enemy(int a)
{
    static int pid_enemy = 0;

    if (a == -1)
        return pid_enemy;
    else
        pid_enemy = a;
    return 0;
}
