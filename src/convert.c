/*
** EPITECH PROJECT, 2024
** navy
** File description:
** convert.c
*/

#include "my.h"

void int_to_signal(int decimal_val, int enemy_pid)
{
    int bin[8] = {0};

    for (int i = 7; i >= 0; i--) {
        bin[i] = decimal_val & 1;
        decimal_val = decimal_val >> 1;
    }
    for (int i = 0; i < 8; i++) {
        usleep(10000);
        if (bin[i] == 0) {
            kill(enemy_pid, SIGUSR1);
        }
        if (bin[i] == 1) {
            kill(enemy_pid, SIGUSR2);
        }
    }
}
