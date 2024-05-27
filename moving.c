/*
** EPITECH PROJECT, 2023
** moving.c
** File description:
** moves the sprites and rectangles
*/

#include "my.h"

void check_time(game_t *game)
{
    if (game->timer >= 20 && game->maxmob < 4) {
        game->maxmob ++;
        game->timer = 0;
    }
}

void move_rect(game_t *game)
{
    for (int i = 0; i != 1; i ++) {
        if (game->imagestab[2].rect.left >= 800) {
            game->imagestab[2].rect.left = 0;
        }else {
            game->imagestab[2].rect.left += 50;
        }
    }
}

void move_mobrect(game_t *game)
{
    for (int i = 0; i != game->maxmob; i ++) {
        if (game->mob_list[i]->rect.left >= 104) {
            game->mob_list[i]->rect.left = 0;
        }else {
            game->mob_list[i]->rect.left += 52;
        }
    }
}

void move_sprite(game_t *game)
{
    sfTime sec;

    sec = sfClock_getElapsedTime(game->clock);
    if (sfTime_asSeconds(sec) > 0.1) {
        move_rect(game);
        sfClock_restart(game->clock);
    }
}

void move_mob(game_t *game)
{
    sfTime sec;

    sec = sfClock_getElapsedTime(game->clock);
    if (sfTime_asSeconds(sec) > 0.1) {
        move_mobrect(game);
        game->timer += 0.1;
        sfClock_restart(game->clock);
    }
    for (int i = 0; i != game->maxmob; i ++) {
        game->mob_list[i]->position.x += game->tabvec[i][0];
        game->mob_list[i]->position.y += game->tabvec[i][1];
        sfSprite_setPosition(game->mob_list[i]->sprite,
        (sfVector2f){game->mob_list[i]->position.x + game->tabvec[i][0],
        game->mob_list[i]->position.y + game->tabvec[i][1]});
    }
}
