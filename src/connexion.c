/*
** EPITECH PROJECT, 2024
** navy
** File description:
** connexion.c
*/

#include "my.h"

void handler(int signo, siginfo_t *info, void *context)
{
    add_pid_enemy(info->si_pid);
    if (signo == SIGUSR1) {
        add_binary(ADD_ZERO);
    }
    if (signo == SIGUSR2) {
        add_binary(ADD_ONE);
    }
}

void launch_p1(char **navy_pos)
{
    struct sigaction act = {0};
    char **map = malloc(sizeof(char *) * 9);
    char **empty_map = malloc(sizeof(char *) * 9);

    empty_map[8] = NULL;
    map[8] = NULL;
    mini_printf("my_pid: %d\n\n", getpid());
    mini_printf("waiting for enemy connection...\n\n");
    act.sa_sigaction = &handler;
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
    while (1) {
        launcher_p1(empty_map, map, navy_pos);
    }
}

void launch_p2(char **navy_pos, char *pid_enemy)
{
    struct sigaction act = {0};
    char **map = malloc(sizeof(char *) * 9);
    char **empty_map = malloc(sizeof(char *) * 9);

    empty_map[8] = NULL;
    map[8] = NULL;
    mini_printf("my_pid: %d\n\n", getpid());
    act.sa_sigaction = &handler;
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
    int_to_signal(255, my_getnbr(pid_enemy));
    while (1) {
        launcher_p2(empty_map, map, navy_pos, my_getnbr(pid_enemy));
    }
}

void navy_launch(char **navy_pos, int ac, char *pid_enemy)
{
    if (ac == 2)
        launch_p1(navy_pos);
    if (ac == 3)
        launch_p2(navy_pos, pid_enemy);
}
