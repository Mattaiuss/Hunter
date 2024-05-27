/*
** EPITECH PROJECT, 2023
** task03
** File description:
** reverses a string
*/

char *my_revstr(char *str)
{
    int cpt = 0;
    int i = 0;
    char t = '0';

    while (str[cpt] != '\0') {
        cpt ++;
    }
    while (cpt > i) {
        t = str[i];
        str[i] = str[cpt];
        str[cpt] = t;
        cpt --;
        i ++;
    }
    return str;
}
