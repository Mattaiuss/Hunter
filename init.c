/*
** EPITECH PROJECT, 2023
** init
** File description:
** my hunter
*/

#include "my.h"

void set_tabcoo(game_t *game)
{
    game->tabcoo[0][0] = -160;
    game->tabcoo[0][1] = 1240;
    game->tabcoo[1][0] = 2020;
    game->tabcoo[1][1] = 1180;
    game->tabcoo[2][0] = 2020;
    game->tabcoo[2][1] = 50;
    game->tabcoo[3][0] = -160;
    game->tabcoo[3][1] = 200;
    game->tabshtex[0] = "Sprites/shsheet2.png";
    game->tabshtex[1] = "Sprites/shsheet.png";
    game->tabshtex[2] = "Sprites/shsheet.png";
    game->tabshtex[3] = "Sprites/shsheet2.png";
    game->tabshtex[4] = "Sprites/shsheet2.png";
}

void set_tabvec(game_t *game)
{
    game->tabvec[0][0] = 1;
    game->tabvec[0][1] = -1;
    game->tabvec[1][0] = -1;
    game->tabvec[1][1] = -1;
    game->tabvec[2][0] = -2;
    game->tabvec[2][1] = 0;
    game->tabvec[3][0] = 2;
    game->tabvec[3][1] = 0;
    game->tabtex[0] = "Sprites/sheet2.png";
    game->tabtex[1] = "Sprites/sheet.png";
    game->tabtex[2] = "Sprites/sheet.png";
    game->tabtex[3] = "Sprites/sheet2.png";
    game->tabtex[4] = "Sprites/sheet2.png";
}

static void set_tabs(game_t *game)
{
    int **tabcoo = malloc(sizeof(int *) * 5);
    int **tabvec = malloc(sizeof(int *) * 5);
    char **tabtex = malloc(sizeof(char *) * 5);
    char **tabshtex = malloc(sizeof(char *) * 5);

    for (int i = 0; i != 5; i ++) {
        tabcoo[i] = malloc(sizeof(int) * 5);
        tabvec[i] = malloc(sizeof(int) * 5);
        tabtex[i] = malloc(sizeof(char) * 5);
        tabshtex[i] = malloc(sizeof(char) * 5);
    }
    game->tabcoo = tabcoo;
    game->tabvec = tabvec;
    game->tabtex = tabtex;
    game->tabshtex = tabshtex;
    set_tabvec(game);
    set_tabcoo(game);
}

static void settext(game_t *game)
{
    char *text = malloc(sizeof(char) * 9);

    for (int i = 0; i != 9; i ++) {
        text[i] = '\0';
    }
    game->textscore = text;
}

static int get_bs(void)
{
    return fs_get_number_from_first_line("gamescore.txt");
}

static void basics(game_t *game)
{
    sfTexture *texture = malloc(sizeof(sfTexture *));
    mob_t **list = malloc(sizeof(mob_t *) * 5);

    game->mob_list = list;
    game->mobs = 0;
    game->maxmob = 0;
    game->score = 0;
    game->nimage = 4;
    game->nbut = 2;
    game->lives = 3;
    game->timer = 0;
    game->highest_score = get_bs();
    settext(game);
    game->cursor = sfSprite_create();
    game->music_titre = sfMusic_createFromFile("Sprites/menu.ogg");
    game->buttons = create_all_buttons();
    game->clock = sfClock_create();
    texture = sfTexture_createFromFile("Sprites/cursor2.png", NULL);
    sfSprite_setTexture(game->cursor, texture, sfTrue);
    sfSprite_setScale(game->cursor, (sfVector2f){3.0f, 3.0f});
}

static void set_texture(game_t *game)
{
    set_pika(game);
    set_title(game);
    set_oak(game);
    set_snorlax(game);
}

void set_feuillage(game_t *game)
{
    sfTexture *feuilles = sfTexture_createFromFile("Sprites/feuilles.png",
    NULL);
    sfTexture *lifes = sfTexture_createFromFile("Sprites/life.png", NULL);

    game->feuillage = sfSprite_create();
    sfSprite_setTexture(game->feuillage, feuilles, sfTrue);
    sfSprite_setScale(game->feuillage, (sfVector2f){0.972f, 0.85f});
    sfSprite_setPosition(game->feuillage, (sfVector2f){0, 0});
    game->imlife.sprite = sfSprite_create();
    game->imlife.rect = (sfIntRect){0, 0, 36, 12};
    sfSprite_setTexture(game->imlife.sprite, lifes, sfTrue);
    sfSprite_setTextureRect(game->imlife.sprite, game->imlife.rect);
    sfSprite_setScale(game->imlife.sprite, (sfVector2f){10, 10});
    sfSprite_setPosition(game->imlife.sprite, (sfVector2f){0, 895});
}

void init_game(game_t *game)
{
    basics(game);
    set_tabs(game);
    game->font = sfFont_createFromFile("Sprites/font.ttf");
    game->text = sfText_create();
    sfText_setFont(game->text, game->font);
    sfText_setCharacterSize(game->text, 70);
    sfText_setColor(game->text, sfBlue);
    game->imagestab = malloc(sizeof(image_t) * game->nimage);
    game->sprite_bg = sfSprite_create();
    game->texture_bg = sfTexture_createFromFile("Sprites/mbg.png", NULL);
    sfSprite_setTexture(game->sprite_bg, game->texture_bg, sfTrue);
    sfSprite_setScale(game->sprite_bg, (sfVector2f){1.45f, 1.35f});
    game->status = 0;
    set_texture(game);
    set_feuillage(game);
    sfMusic_play(game->music_titre);
    sfMusic_setLoop(game->music_titre, sfTrue);
}
