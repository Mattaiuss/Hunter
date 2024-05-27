/*
** EPITECH PROJECT, 2023
** draw_score.c
** File description:
** draw the window based of the game status
*/

#include "my.h"

void init_oizo(game_t *game)
{
    for (int i = 0; i < 2; i ++) {
        sfSprite_setPosition(game->mob_list[i]->sprite,
        (sfVector2f){game->tabcoo[i][0], game->tabcoo[i][1]});
        game->mob_list[i]->position = (sfVector2f){game->tabcoo[i][0],
        game->tabcoo[i][1]};
        game->mob_list[i]->x = game->mob_list[i]->position.x;
        game->mob_list[i]->y = game->mob_list[i]->position.y;
    }
}

static void set_life(game_t *game)
{
    if (game->imlife.rect.left >= 108) {
        game->imlife.rect.left = 0;
    }else {
        game->imlife.rect.left += 36;
    }
    sfSprite_setTextureRect(game->imlife.sprite, game->imlife.rect);
}

static void is_out(game_t *game)
{
    for (int i = 0; i != game->maxmob; i++) {
        if (game->mob_list[i]->position.x > 2250 ||
        game->mob_list[i]->position.x < -190) {
            game->lives --;
            set_life(game);
            respawn(game, i);
            break;
        }
        if (game->mob_list[i]->position.y > 1270 ||
        game->mob_list[i]->position.y < -190) {
            game->lives --;
            set_life(game);
            respawn(game, i);
            break;
        }
    }
}

static void draw_mobs(game_t *game)
{
    for (int i = 0; i != game->maxmob; i ++) {
        sfRenderWindow_drawSprite(game->window,
        game->mob_list[i]->sprite, NULL);
    }
}

void load_menu(game_t *game, sfEvent event)
{
    sfSprite_setPosition(game->cursor,
    (sfVector2f){sfMouse_getPositionRenderWindow(game->window).x - 18,
    sfMouse_getPositionRenderWindow(game->window).y - 19});
    move_sprite(game);
    manage_mouse_click(event, game);
    draw_sprites(game);
    draw_score(game);
    sfRenderWindow_drawSprite(game->window, game->cursor, NULL);
    sfRenderWindow_display(game->window);
    sfRenderWindow_clear(game->window, sfTransparent);
    sfSprite_setTextureRect(game->imagestab[2].sprite,
    game->imagestab[2].rect);
}

void change_gameover(game_t *game)
{
    if (game->status == 2) {
        if (game->score > game->highest_score)
            game->highest_score = game->score;
        write_bs(int_tochar(game->highest_score, 1, 0));
        sfMusic_destroy(game->music_titre);
        game->music_titre = sfMusic_createFromFile("Sprites/gameover.ogg");
        sfMusic_play(game->music_titre);
        sfMusic_setLoop(game->music_titre, sfTrue);
        game->texture_bg = sfTexture_createFromFile("Sprites/gobg.png", NULL);
        sfSprite_setTexture(game->sprite_bg, game->texture_bg, sfTrue);
        sfSprite_setScale(game->sprite_bg, (sfVector2f){1.07f, 1.0f});
    }
}

void game_over(game_t *game, sfEvent event)
{
    manage_mouse_click(event, game);
    sfRenderWindow_drawSprite(game->window, game->sprite_bg, NULL);
    sfText_setColor(game->text, sfBlue);
    draw_score(game);
    sfText_setString(game->text, "Press the space key to restart.");
    sfText_setPosition(game->text, (sfVector2f){450, 910});
    sfText_setColor(game->text, sfWhite);
    sfRenderWindow_drawText(game->window, game->text, NULL);
    sfRenderWindow_display(game->window);
    sfRenderWindow_clear(game->window, sfTransparent);
}

void load_game(game_t *game, sfEvent event)
{
    sfSprite_setPosition(game->cursor,
    (sfVector2f){sfMouse_getPositionRenderWindow(game->window).x - 18,
    sfMouse_getPositionRenderWindow(game->window).y - 19});
    manage_mouse_click(event, game);
    check_time(game);
    check_spawns(game);
    draw_sprites(game);
    move_mob(game);
    is_out(game);
    draw_mobs(game);
    draw_score(game);
    sfRenderWindow_drawSprite(game->window, game->feuillage, NULL);
    sfRenderWindow_drawSprite(game->window, game->imlife.sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->cursor, NULL);
    sfRenderWindow_display(game->window);
    sfRenderWindow_clear(game->window, sfTransparent);
    for (int i = 0; i != game->maxmob; i ++) {
        sfSprite_setTextureRect(game->mob_list[i]->sprite,
        game->mob_list[i]->rect);
    }
}
