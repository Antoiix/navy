/*
** EPITECH PROJECT, 2023
** my_str_isnum.c
** File description:
** this file returns 1 if all of the
** characters of a string are numbers.
** created and edited by Antoine Orange.
** All rights reserved
*/

int my_isnum(char str)
{
    if (str > 57 || str < 48) {
        return 0;
    }
    return 1;
}
