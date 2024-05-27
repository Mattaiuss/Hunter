/*
** EPITECH PROJECT, 2023
** task06
** File description:
** compares the two strings
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int j = 0;

    while (s1[i] == s2[i]) {
        if (s1[i] == '\0') {
            return 0;
        }
        i ++;
    }
    j = s1[i] - s2[i];
    if (j > 0) {
        return 1;
    }else {
        return -1;
    }
}
