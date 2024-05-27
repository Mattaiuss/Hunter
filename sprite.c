/*
** EPITECH PROJECT, 2023
** sprite.c
** File description:
** inits and displays sprites
*/

#include "my.h"

void draw_sprites(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->sprite_bg, NULL);
    for (int i = 0; i < game->nimage; i ++) {
        sfRenderWindow_drawSprite(game->window,
        game->imagestab[i].sprite, NULL);
    }
    for (int i = 0; i < game->nbut; i++)
        sfRenderWindow_drawSprite(game->window,
        game->buttons[i]->sprite, NULL);
}

void set_pika(game_t *game)
{
    image_t *pika = malloc(sizeof(image_t));

    pika->sprite = sfSprite_create();
    pika->texture = sfTexture_createFromFile("Sprites/pika.png", NULL);
    pika->rect = (sfIntRect){0, 0, 50, 45};
    sfSprite_setTexture(pika->sprite, pika->texture, sfTrue);
    sfSprite_setPosition(pika->sprite, (sfVector2f){1500, 720});
    sfSprite_setScale(pika->sprite, (sfVector2f){6.0, 6.0f});
    sfSprite_setTextureRect(pika->sprite, pika->rect);
    game->imagestab[2] = *pika;
}

void set_title(game_t *game)
{
    image_t *title = malloc(sizeof(image_t));

    title->sprite = sfSprite_create();
    title->texture = sfTexture_createFromFile("Sprites/title.png", NULL);
    sfSprite_setPosition(title->sprite, (sfVector2f){480, 100});
    sfSprite_setScale(title->sprite, (sfVector2f){1.5, 1.5f});
    sfSprite_setTexture(title->sprite, title->texture, sfTrue);
    game->imagestab[0] = *title;
}

void set_oak(game_t *game)
{
    image_t *oak = malloc(sizeof(image_t));

    oak->sprite = sfSprite_create();
    oak->texture = sfTexture_createFromFile("Sprites/oak.png", NULL);
    sfSprite_setPosition(oak->sprite, (sfVector2f){1130, 300});
    sfSprite_setScale(oak->sprite, (sfVector2f){3, 3});
    sfSprite_setTexture(oak->sprite, oak->texture, sfTrue);
    game->imagestab[1] = *oak;
}

void set_snorlax(game_t *game)
{
    image_t *snorlax = malloc(sizeof(image_t));

    snorlax->sprite = sfSprite_create();
    snorlax->texture = sfTexture_createFromFile("Sprites/snorlax.png", NULL);
    sfSprite_setPosition(snorlax->sprite, (sfVector2f){150, 550});
    sfSprite_setScale(snorlax->sprite, (sfVector2f){2, 2});
    sfSprite_setTexture(snorlax->sprite, snorlax->texture, sfTrue);
    game->imagestab[3] = *snorlax;
}
