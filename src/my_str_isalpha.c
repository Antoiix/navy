/*
** EPITECH PROJECT, 2023
** my_str_isalpha.c
** File description:
** this file returns 1 if all of the
** characters of a string are alphas.
** created and edited by Antoine Orange.
** All rights reserved
*/

int my_isalpha(char str)
{
    if (str < 65 || str > 90) {
        return 0;
    }
    return 1;
}
