/*
** EPITECH PROJECT, 2023
** myputnbr
** File description:
** displays a number
*/

#include "my.h"
#include <limits.h>
#include <unistd.h>

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        if (nb == INT_MIN) {
            my_putchar('2');
            my_put_nbr(nb / -10);
        }else {
            my_put_nbr(-nb);
        }
    }else if (nb > 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }else {
        my_putchar(nb + '0');
    }
    return 0;
}
