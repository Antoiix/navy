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
    static int bit_check = 0;

    if (a == CLEAR)
        data = 0;
    if (a == ADD_ZERO) {
        bit_check = bit_check + 1;
        data = (data << 1) | 0;
    }
    if (a == ADD_ONE) {
        bit_check = bit_check + 1;
        data = (data << 1) | 1;
    }
    if (a == GET) {
        if (bit_check == 8 || bit_check == 0) {
            bit_check = 0;
            return data;
        }
    }
    return 0;
}

int add_pid_enemy(int a)
{
    static int pid_enemy = 0;

    if (a == -2)
        pid_enemy = -2;
    if (a == -3)
        pid_enemy = -3;
    if (a == -1)
        return pid_enemy;
    else
        pid_enemy = a;
    return 0;
}
