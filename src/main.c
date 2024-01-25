/*
** EPITECH PROJECT, 2024
** navy
** File description:
** main.c
*/

#include "my.h"

char **parse_pos(char *file_path)
{
    int fd = open(file_path, O_RDONLY);
    int rd;
    char *buff;
    char **arr;
    int size = lseek(fd, 0, SEEK_END);

    close(fd);
    fd = open(file_path, O_RDONLY);
    if (fd < 0)
        return NULL;
    buff = malloc(sizeof(char) * (size + 1));
    buff[size] = '\0';
    rd = read(fd, buff, sizeof(char) * (size + 1));
    if (rd < 0)
        return NULL;
    close(fd);
    arr = my_str_to_word_array(buff, ":\n");
    free(buff);
    return arr;
}

void all_free(char **navy_pos)
{
    if (!navy_pos) {
        free(navy_pos);
        return;
    }
    for (int i = 0; navy_pos[i] != NULL; i++) {
        free(navy_pos[i]);
    }
    free(navy_pos);
}

int check_pos(char **navy_pos, int i, int *ship_check)
{
    int exit = 0;

    if ((navy_pos[i + 1][0] >= 'A') && ('H' >= navy_pos[i + 1][0]) &&
    ('1' <= navy_pos[i + 1][1]) && ('8' >= navy_pos[i + 1][1]) &&
    my_strlen(navy_pos[i + 1]) == 2)
        exit++;
    if ((navy_pos[i + 2][0] >= 'A') && ('H' >= navy_pos[i + 2][0]) &&
    ('1' <= navy_pos[i + 2][1]) && ('8' >= navy_pos[i + 2][1]) &&
    my_strlen(navy_pos[i + 2]) == 2)
        exit++;
    if (my_getnbr(navy_pos[i]) < 2 || my_getnbr(navy_pos[i]) > 5
        || exit != 2)
        return 84;
    else
        ship_check[my_getnbr(navy_pos[i]) - 2] = 1;
    return 0;
}

int verif_navy(char **navy_pos)
{
    int j;
    int ship_check[4] = {0};

    for (j = 0; navy_pos[j] != NULL; j++);
    if (j % 3 != 0) {
        all_free(navy_pos);
        return 84;
    }
    for (int i = 0; navy_pos[i] != NULL; i = i + 3) {
        if (check_pos(navy_pos, i, ship_check) == 84)
            return 84;
    }
    for (int j = 0; j != 4; j++) {
        if (ship_check[j] == 0)
            return 84;
    }
    return 0;
}

int main(int ac, char **av)
{
    char **navy_pos;
    char *pid_enemy = NULL;

    if (ac != 2 && ac != 3)
        return 84;
    if (ac == 2)
        navy_pos = parse_pos(av[1]);
    if (ac == 3) {
        navy_pos = parse_pos(av[2]);
        pid_enemy = my_strdup(av[1]);
    }
    if (verif_navy(navy_pos) == 84 || navy_pos == NULL)
        return 84;
    navy_launch(navy_pos, ac, pid_enemy);
    all_free(navy_pos);
    if (add_pid_enemy(GET_PID) == -2)
        return 0;
    if (add_pid_enemy(GET_PID) == -3)
        return 1;
    return 0;
}
