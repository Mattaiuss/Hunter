/*
** EPITECH PROJECT, 2023
** score.c
** File description:
** displays score
*/

#include "my.h"

static void draw_bs(game_t *game, int x, int y)
{
    sfText_setString(game->text, "[BEST SCORE] : ");
    sfText_setPosition(game->text, (sfVector2f){x, y});
    sfRenderWindow_drawText(game->window, game->text, NULL);
    sfText_setString(game->text, int_tochar(game->highest_score,
    1, 0));
    sfText_setPosition(game->text, (sfVector2f){x + 475, y + 5});
    sfRenderWindow_drawText(game->window, game->text, NULL);
}

void draw_goscore(game_t *game)
{
    sfText_setString(game->text, "Your score : ");
    sfText_setPosition(game->text, (sfVector2f){670, 330});
    sfRenderWindow_drawText(game->window, game->text, NULL);
    game->textscore = int_tochar(game->score, 1, 0);
    sfText_setString(game->text, game->textscore);
    sfText_setPosition(game->text, (sfVector2f){1100, 335});
    sfRenderWindow_drawText(game->window, game->text, NULL);
    draw_bs(game, 670, 650);
}

void draw_score(game_t *game)
{
    if (game->status == 1) {
        draw_bs(game, 50, 0);
        sfText_setString(game->text, "Score : ");
        sfText_setPosition(game->text, (sfVector2f){1470, 30});
        sfRenderWindow_drawText(game->window, game->text, NULL);
        game->textscore = int_tochar(game->score, 1, 0);
        sfText_setString(game->text, game->textscore);
        sfText_setPosition(game->text, (sfVector2f){1700, 35});
        sfRenderWindow_drawText(game->window, game->text, NULL);
    }
    if (game->status == 0)
        draw_bs(game, 80, 350);
    if (game->status == 2)
        draw_goscore(game);
}

void make_ball(void)
{
    my_putstr("⬜⬜⬜⬜⬜⬛⬛⬛⬛⬜⬜⬜⬜⬜\n");
    my_putstr("⬜⬜⬜⬛⬛🟥🟥🟥🟥🟥⬛⬜⬜⬜\n");
    my_putstr("⬜⬜⬛🟥🟥🟥🟥🟥🟥🟥🟥⬛⬜⬜\n");
    my_putstr("⬜⬛🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥⬛⬜\n");
    my_putstr("⬜⬛🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥⬛⬜\n");
    my_putstr("⬛🟥🟥🟥🟥🟥⬛⬛🟥🟥🟥🟥🟥⬛\n");
    my_putstr("⬛🟥🟥🟥🟥⬛⬜⬜⬛🟥🟥🟥🟥⬛\n");
    my_putstr("⬛⬛⬛⬛⬛⬛⬜⬜⬛⬛⬛⬛⬛⬛\n");
    my_putstr("⬛⬜⬜⬜⬜⬜⬛⬛⬜⬜⬜⬜⬜⬛\n");
    my_putstr("⬜⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬜\n");
    my_putstr("⬜⬛⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬛⬜\n");
    my_putstr("⬜⬜⬛⬜⬜⬜⬜⬜⬜⬜⬜⬛⬜⬜\n");
    my_putstr("⬜⬜⬜⬛⬛⬜⬜⬜⬜⬛⬛⬜⬜⬜\n");
    my_putstr("⬜⬜⬜⬜⬜⬛⬛⬛⬛⬜⬜⬜⬜⬜\n\n");
}
