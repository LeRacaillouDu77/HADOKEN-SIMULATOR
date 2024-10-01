/*
** EPITECH PROJECT, 2023
** my hunter
** File description:
** main file
*/

#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "my.h"
#include <fcntl.h>

void init_akuma_defi(menu_t *menu)
{
    menu->akuma_defi = malloc(sizeof(defi_completed_t));
    menu->akuma_defi->clock = sfClock_create();
    menu->akuma_defi->is_visible = sfFalse;
    menu->akuma_defi->position = (sfVector2f){1700, -15};
    menu->akuma_defi->rect = (sfIntRect){0, 0, 263, 224};
    menu->akuma_defi->sprite = sfSprite_create();
    menu->akuma_defi->texture = sfTexture_createFromFile("ressources/spritesheets/akuma_defi_completed.png", NULL);
    sfSprite_setTexture(menu->akuma_defi->sprite, menu->akuma_defi->texture, sfFalse);
    sfSprite_setTextureRect(menu->akuma_defi->sprite, menu->akuma_defi->rect);
    sfSprite_setPosition(menu->akuma_defi->sprite, menu->akuma_defi->position);
}

void akuma_is_visible(menu_t *menu)
{
    if (get_highscore("highscores/defi1.txt") != 80 &&
    get_highscore("highscores/defi2.txt") != 80 &&
    get_highscore("highscores/defi3.txt") != 80) {
        menu->akuma_defi->is_visible = sfTrue;
    } else {
        menu->akuma_defi->is_visible = sfFalse;
    }
}

void print_akuma(menu_t *menu)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(menu->akuma_defi->clock);
    seconds = time.microseconds / 1000000.0;
    if ( seconds >= 0.06) {
        move_rect(&menu->akuma_defi->rect, 263, 7890);
        sfSprite_setTextureRect(menu->akuma_defi->sprite, menu->akuma_defi->rect);
        sfClock_restart(menu->akuma_defi->clock);
    }
    if (menu->akuma_defi->is_visible == sfTrue)
        sfRenderWindow_drawSprite(menu->window, menu->akuma_defi->sprite, NULL);

}

void free_akuma_struct(defi_completed_t *akuma)
{
    sfSprite_destroy(akuma->sprite);
    sfTexture_destroy(akuma->texture);
    sfClock_destroy(akuma->clock);
    free(akuma);
}