/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** contains all of prototypes
*/

#ifndef MY_H
    #define MY_H
    #include <stdio.h>
    #include <unistd.h>
    #include <stdint.h>
    #include <time.h>
    #include <limits.h>
    #include <stdarg.h>
    #include <errno.h>
    #include <math.h>
    #include <stdlib.h>
    #include <string.h>
    #include <fcntl.h>
    #include "sys/stat.h"

char **my_str_to_word_array(char const *str, char *pattern);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_isalpha(char str);
int my_isnum(char str);

#endif
