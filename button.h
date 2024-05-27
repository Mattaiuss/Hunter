/*
** EPITECH PROJECT, 2023
** B-MUL-100-MPL-1-1-myhunter-valentin.galvaing
** File description:
** button
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#ifndef BUTTON_H_
    #define BUTTON_H_

    #define NB_BUTTONS 2

    #define PLAY 0
    #define RUN 1

    #define PLAY_FILE "Sprites/fbutton.png"
    #define RUN_FILE "Sprites/rbutton.png"

typedef struct button_s {
    sfSprite *sprite;
    sfTexture *texture;

    char *texture_file;
    sfVector2f scale;
    sfVector2f position;
    int x;
    int y;
    void (*fonc)(void *);
} button_t;

void init_button(struct button_s *button);
button_t **create_all_buttons(void);
#endif /* !BUTTON_H_ */
