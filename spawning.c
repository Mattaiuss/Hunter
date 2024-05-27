/*
** EPITECH PROJECT, 2023
** spawning.c
** File description:
** spawns mobs
*/

#include "my.h"

char *is_shiny(game_t *game, int i)
{
    int x = rand() % 50;

    if (x == 1) {
        return game->tabshtex[i];
    }else {
        return game->tabtex[i];
    }
}

void spawn_mob(game_t *game, int i)
{
    mob_t *oizo = malloc(sizeof(mob_t));

    oizo->sprite = sfSprite_create();
    oizo->texture = sfTexture_createFromFile(is_shiny(game, i), NULL);
    oizo->rect = (sfIntRect){0, 0, 52, 52};
    sfSprite_setPosition(oizo->sprite, (sfVector2f){game->tabcoo[i][0],
    game->tabcoo[i][1]});
    sfSprite_setScale(oizo->sprite, (sfVector2f){2, 2});
    oizo->position.x = game->tabcoo[i][0];
    oizo->position.y = game->tabcoo[i][1];
    oizo->x = game->tabcoo[i][0];
    oizo->y = game->tabcoo[i][1];
    sfSprite_setTexture(oizo->sprite, oizo->texture, sfTrue);
    sfSprite_setTextureRect(oizo->sprite, oizo->rect);
    game->mob_list[i] = oizo;
    game->mobs ++;
}

void check_spawns(game_t *game)
{
    for (int i = game->mobs; i != game->maxmob; i ++) {
        spawn_mob(game, i);
    }
}
