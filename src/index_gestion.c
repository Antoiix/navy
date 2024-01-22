/*
** EPITECH PROJECT, 2024
** navy
** File description:
** index_gestion.c
*/

#include "my.h"

int add_binary(int a)
{
    static int data = 0;

    if (a == 2)
        return data;
    if (a == 3)
        data = 0;
    if (a == 0)
        data = (data << 1) | 0;
    if (a == 1)
        data = (data << 1) | 1;
    return 0;
}
