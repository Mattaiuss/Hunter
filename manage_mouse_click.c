/*
** EPITECH PROJECT, 2023
** pour le coding style
** File description:
** oui
*/

#include <stdio.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "my.h"

void start_game(game_t *game)
{
    game->status = 1;
}

void end_game(game_t *game)
{
    sfRenderWindow_close(game->window);
}

static void check_functions(game_t *game, sfMouseButtonEvent event, int i)
{
    if (event.y <= game->buttons[i]->y + game->buttons[i]->position.y
    && event.y >= game->buttons[i]->position.y ) {
        if (event.x <= game->buttons[i]->x + game->buttons[i]->position.x
        && event.x >= game->buttons[i]->position.x ) {
            game->buttons[i]->fonc(game);
        }
    }
}

void respawn(game_t *game, int i)
{
    sfTexture *text = sfTexture_createFromFile(is_shiny(game, i), NULL);

    sfSprite_setTexture(game->mob_list[i]->sprite, text, sfTrue);
    sfSprite_setPosition(game->mob_list[i]->sprite,
    (sfVector2f){game->tabcoo[i][0], game->tabcoo[i][1]});
    game->mob_list[i]->position = (sfVector2f){game->tabcoo[i][0],
    game->tabcoo[i][1]};
    game->mob_list[i]->x = game->mob_list[i]->position.x;
    game->mob_list[i]->y = game->mob_list[i]->position.y;
    if (game->lives <= 0) {
        game->status = 2;
    }
}

static void bird_istouch(game_t *game, sfMouseButtonEvent event, int i)
{
    if (event.y <= game->mob_list[i]->position.y +
    game->mob_list[i]->rect.height * 2
    && event.y >= game->mob_list[i]->position.y ) {
        if (event.x <= game->mob_list[i]->position.x +
        game->mob_list[i]->rect.width * 2
        && event.x >= game->mob_list[i]->position.x ) {
            respawn(game, i);
            game->score ++;
        }
    }
}

static void analyse_events(sfMouseButtonEvent event, game_t *game)
{
    for (int i = 0; i != game->nbut; i ++) {
        check_functions(game, event, i);
    }
    for (int j = 0; j != game->maxmob; j ++) {
        bird_istouch(game, event, j);
    }
}

void manage_mouse_click(sfEvent event, game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtMouseButtonPressed)
            analyse_events(event.mouseButton, game);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            game->status = 3;
        }
        if (sfKeyboard_isKeyPressed(sfKeySpace) && game->status == 2)
            game->status = 0;
    }
}
