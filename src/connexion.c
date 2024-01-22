/*
** EPITECH PROJECT, 2024
** navy
** File description:
** connexion.c
*/

#include "my.h"

void handler(int signo, siginfo_t *info, void *context)
{
    if (signo == SIGUSR1) {
        add_binary(0);
    }
    if (signo == SIGUSR2) {
        add_binary(1);
    }
}

void launch_p1(char **navy_pos)
{
    struct sigaction act = {0};

    mini_printf("my_pid: %d\n\n", getpid());
    mini_printf("waiting for enemy connection...\n\n");
    act.sa_sigaction = &handler;
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
    while (1);
}

void launch_p2(char **navy_pos, char *pid_enemy)
{
    mini_printf("my_pid: %d\n\n", getpid());
    int_to_signal(190, my_getnbr(pid_enemy));
}

void navy_launch(char **navy_pos, int ac, char *pid_enemy)
{
    if (ac == 2)
        launch_p1(navy_pos);
    if (ac == 3)
        launch_p2(navy_pos, pid_enemy);
}
