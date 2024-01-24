/*
** EPITECH PROJECT, 2024
** navy
** File description:
** place_conversion.c
*/

#include "my.h"

int place_to_int(char *place)
{
    int a = (place[1] - 48) * 10;

    a += (place[0] - 64);
    return a;
}
