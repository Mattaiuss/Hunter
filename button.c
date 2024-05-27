/*
** EPITECH PROJECT, 2023
** MyHunter
** File description:
** button
*/

#include "button.h"
#include "my.h"
#include <stdlib.h>

void init_button(struct button_s *button)
{
    button->sprite = sfSprite_create();
    button->texture = sfTexture_createFromFile(button->texture_file, NULL);
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    sfSprite_setScale(button->sprite, button->scale);
    sfSprite_setPosition(button->sprite, button->position);
}

button_t **create_all_buttons(void)
{
    button_t **tableau = malloc(sizeof(button_t *) * NB_BUTTONS);

    tableau[PLAY] = malloc(sizeof(button_t));
    tableau[PLAY]->texture_file = PLAY_FILE;
    tableau[PLAY]->scale = (sfVector2f){3.5f, 3.5f};
    tableau[PLAY]->position = (sfVector2f){715, 500};
    tableau[PLAY]->x = 130 * tableau[PLAY]->scale.x;
    tableau[PLAY]->y = 46 * tableau[PLAY]->scale.y;
    tableau[PLAY]->fonc = start_game;
    tableau[RUN] = malloc(sizeof(button_t));
    tableau[RUN]->texture_file = RUN_FILE;
    tableau[RUN]->scale = (sfVector2f){2.0f, 2.0f};
    tableau[RUN]->position = (sfVector2f){820, 725};
    tableau[RUN]->x = 130 * tableau[RUN]->scale.x;
    tableau[RUN]->y = 46 * tableau[RUN]->scale.y;
    tableau[RUN]->fonc = end_game;
    for (int i = 0; i < NB_BUTTONS; i++)
        init_button(tableau[i]);
    return tableau;
}
