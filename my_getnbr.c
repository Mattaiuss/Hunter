/*
** EPITECH PROJECT, 2023
** header
** File description:
** heu
*/

#include <unistd.h>
#include <limits.h>

int my_getnbr(char *str)
{
    int i = 0;
    int sign = 1;
    int result = 0;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            sign = sign * (-1);
        i = i + 1;
    }
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
        result = result * 10;
        result = result + str[i] - 48;
        i = i + 1;
    }
    return result * sign;
}
