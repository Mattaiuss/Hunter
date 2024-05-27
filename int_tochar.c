/*
** EPITECH PROJECT, 2023
** int_tochar.c
** File description:
** transforms a int to char
*/

#include "my.h"
#include <limits.h>
#include <unistd.h>

char *int_tochar(int nb, int cpt, int index)
{
    char *text = malloc(sizeof(char) * 9);
    int temp;

    for (int i = 0; i != 9; i ++) {
        text[i] = '\0';
    }
    while (nb >= 10) {
        temp = nb;
        while (temp >= 10) {
            temp = temp / 10;
            cpt = cpt * 10;
        }
        text[index] = temp + '0';
        nb = nb - cpt * temp;
        cpt = 1;
        index ++;
    }
    text[index] = nb + '0';
    text[index + 1] = '\n';
    return text;
}
