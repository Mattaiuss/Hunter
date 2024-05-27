/*
** EPITECH PROJECT, 2023
** init
** File description:
** my hunter
*/

#include "my.h"
#include <time.h>

static void print_rules(void)
{
    make_ball();
    my_putstr("-----------------------------\n");
    my_putstr("==========MY_HUNTER==========\n");
    my_putstr("-----------------------------\n");
    my_putstr("\n            RULES:\n\n0-MENU-0\n-click the FIGHT button ");
    my_putstr("to start playing.\n-click the RUN button or ");
    my_putstr("press the escape key to leave.\n\n");
    my_putstr("0-IN GAME-0\n-click on the birds to increase your score");
    my_putstr(" points and beat the best score !\n-You have 3lives, each");
    my_putstr(" birds that leaves the screen make you lose one life\n");
    my_putstr("-You can still press the escape key in game to leave");
    my_putstr("leave the game.\n\n0-GAME OVER-0\n-you can restart with ");
    my_putstr("the space key\n");
}

static int test_flag(int ac, char **av)
{
    if (ac == 1) {
        return 1;
    }
    if (ac > 2) {
        return 84;
    }
    if (my_strcmp("-h", av[1]) == 0)
        return 0;
    return 84;
}

static int flags(int ac, char **av)
{
    if (test_flag(ac, av) == 84) {
        write(2, "invalid flag\n", 13);
        return 84;
    }
    if (test_flag(ac, av) == 0) {
        print_rules();
        return 0;
    }
    return 1;
}

static void change_bg(game_t *game)
{
    game->texture_bg = sfTexture_createFromFile("Sprites/gamebg.png", NULL);
    sfSprite_setTexture(game->sprite_bg, game->texture_bg, sfTrue);
    sfSprite_setScale(game->sprite_bg, (sfVector2f){0.97f, 0.85f});
}

static void change_game(game_t *game)
{
    game->maxmob = 2;
    check_spawns(game);
    init_oizo(game);
    change_bg(game);
    sfMusic_destroy(game->music_titre);
    game->music_titre = sfMusic_createFromFile("Sprites/Littleroot.ogg");
    sfMusic_play(game->music_titre);
    sfMusic_setLoop(game->music_titre, sfTrue);
    game->clock = sfClock_create();
    game->nimage = 0;
    game->nbut = 0;
}

void create_window(game_t *game)
{
    sfVideoMode md = {1920, 1080, 32};
    time_t t;

    srand((unsigned) time(&t));
    game->window = sfRenderWindow_create(md, "MY_HUNTER", sfResize | sfClose,
    NULL);
    game->status = 0;
    sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
}

void destroy_all(game_t *game)
{
    sfText_destroy(game->text);
    sfClock_destroy(game->clock);
    sfFont_destroy(game->font);
    sfRenderWindow_destroy(game->window);
    for (int i = 0; i != NB_BUTTONS; i ++)
        sfSprite_destroy(game->buttons[i]->sprite);
    for (int i = 0; i != game->nimage; i ++)
        sfSprite_destroy(game->imagestab[i].sprite);
    for (int i = 0; i != NB_BUTTONS; i ++)
        sfTexture_destroy(game->buttons[i]->texture);
    for (int i = 0; i != game->nimage; i ++)
        sfTexture_destroy(game->imagestab[i].texture);
}

int main(int ac, char **av)
{
    sfEvent event;
    game_t *game = malloc(sizeof(game_t));

    if (flags(ac, av) != 1)
        return 84;
    create_window(game);
    while (sfRenderWindow_isOpen(game->window) && game->status != 3) {
        init_game(game);
        while (game->status == 0 && sfRenderWindow_isOpen(game->window))
            load_menu(game, event);
        change_game(game);
        while (game->status == 1 && sfRenderWindow_isOpen(game->window))
            load_game(game, event);
        change_gameover(game);
        while (game->status == 2 && sfRenderWindow_isOpen(game->window))
            game_over(game, event);
        sfMusic_destroy(game->music_titre);
    }
    destroy_all(game);
    return 0;
}
