/*
** EPITECH PROJECT, 2023
** step 6
** File description:
** get the number at line 1
*/

#include "my.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int test_error(int nb)
{
    if (nb < 0) {
        return 1;
    }
    return 0;
}

int fs_get_number_from_first_line(const char *filepath)
{
    int fd;
    char *str_num = malloc(sizeof(char) * 32000);
    char *str = malloc(sizeof(char) * 32000);

    fd = open(filepath, O_RDONLY);
    for (int j = 0; j < 32000; j ++) {
        str[j] = '\0';
        str_num[j] = '\0';
    }
    read(fd, str, 32000);
    for (int i = 0; str[i] != '\n'; i ++) {
        str_num[i] = str[i];
    }
    if (test_error(my_getnbr(str_num)) == 1) {
        return -1;
    }
    return (my_getnbr(str_num));
}

int write_bs(char *score)
{
    int fd = open("gamescore.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    write(fd, score, my_strlen(score));
    close(fd);
    return 0;
}
