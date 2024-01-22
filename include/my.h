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
    #include "signal.h"

char **my_str_to_word_array(char const *str, char *pattern);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_isalpha(char str);
int my_isnum(char str);
int mini_printf(const char *format, ...);
int my_pf_put_nbr(int nb, int *count);
void my_pf_putchar(char c, int *count);
int my_pf_putstr(char const *str, int *count);
void navy_launch(char **navy_pos, int ac, char *pid_enemy);
char *my_strdup(char const *src);
void int_to_signal(int decimal_val, int enemy_pid);
void handler(int signo, siginfo_t *info, void *context);
int add_binary(int a);

#endif
