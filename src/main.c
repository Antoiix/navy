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
    struct stat s;

    if (fd < 0)
        return NULL;
    stat(file_path, &s);
    buff = malloc(sizeof(char) * (s.st_size + 1));
    buff[s.st_size] = '\0';
    rd = read(fd, buff, sizeof(char) * (s.st_size + 1));
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
    if (my_isalpha(navy_pos[i + 1][0]) == 0 ||
    my_isnum(navy_pos[i + 1][1]) == 0)
        return 84;
    if (my_isalpha(navy_pos[i + 2][0]) == 0 ||
        my_isnum(navy_pos[i + 2][1]) == 0)
        return 84;
    if (my_getnbr(navy_pos[i]) < 2 || my_getnbr(navy_pos[i]) > 5)
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

    if (ac < 2)
        return 84;
    navy_pos = parse_pos(av[1]);
    if (navy_pos == NULL)
        return 84;
    if (verif_navy(navy_pos) == 84)
        return 84;
    printf("%s, %s, %s\n%s, %s, %s\n%s, %s, %s\n%s, %s, %s\n",
        navy_pos[0], navy_pos[1], navy_pos[2], navy_pos[3], navy_pos[4],
        navy_pos[5], navy_pos[6], navy_pos[7], navy_pos[8], navy_pos[9],
        navy_pos[10], navy_pos[11]);
    all_free(navy_pos);
    return 0;
}
