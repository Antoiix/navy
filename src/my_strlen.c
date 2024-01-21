/*
** EPITECH PROJECT, 2023
** my_strlen.c
** File description:
** this file returns the length of
** a string.
** created and edited by Antoine Orange.
** All rights reserved
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i += 1;
    }
    return i;
}
