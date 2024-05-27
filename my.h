/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** my.h
*/

#pragma once

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "button.h"

typedef struct mob_s {
    sfSprite *sprite;
    sfTexture *texture;
    char *texture_file;
    sfIntRect rect;

    sfVector2f scale;
    sfVector2f position;
    int x;
    int y;

    void (*fonc)(void *);
} mob_t;

typedef struct {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
} image_t;

typedef struct {
    sfClock *clock;
    int nimage;
    int nbut;
    sfFont *font;
    sfText *text;
    int score;
    int highest_score;
    char *textscore;
    int **tabcoo;
    int **tabvec;
    char **tabtex;
    char **tabshtex;
    int lives;
    float timer;

    sfSprite *sprite_bg;
    sfSprite *feuillage;
    sfTexture *texture_bg;
    sfSprite *cursor;
    button_t **buttons;
    sfMusic *music_titre;
    image_t *imagestab;

    int mobs;
    int maxmob;
    mob_t **mob_list;
    image_t imlife;

    sfRenderWindow* window;
    int status;
} game_t;

int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2);

char *int_tochar(int nb, int cpt, int index);

void manage_mouse_click(sfEvent event, game_t *game);

int my_put_nbr(int nb);

int my_putstr(char const *str);

void my_putchar(char c);

void init_game(game_t *game);

void draw_sprites(game_t *game);

void move_rect(game_t *game);

void move_mob(game_t *game);

void move_sprite(game_t *game);

void start_game(game_t *game);

void end_game(game_t *game);

void respawn(game_t *game, int i);

void load_menu(game_t *game, sfEvent event);

void load_game(game_t *game, sfEvent event);

int fs_get_number_from_first_line(const char *filepath);

int my_getnbr(char *str);

int write_bs(char *score);

char *my_strcat(char *dest, char const *src);

void spawn_mob(game_t *game, int i);

void check_spawns(game_t *game);

void game_over(game_t *game, sfEvent event);

void draw_score(game_t *game);

void set_pika(game_t *game);

void set_title(game_t *game);

void set_oak(game_t *game);

void set_snorlax(game_t *game);

void init_oizo(game_t *game);

void check_time(game_t *game);

void destroy_all(game_t *game);

void change_gameover(game_t *game);

void make_ball(void);

char *is_shiny(game_t *game, int i);
