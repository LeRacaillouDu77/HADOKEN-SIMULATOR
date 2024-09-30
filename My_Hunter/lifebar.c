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

sfSprite *create_life_bar(sfRenderWindow *window)
{
    sfTexture *texture = sfTexture_createFromFile(
    "./ressources/spritesheets/life_bar.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

void move_hp(sfIntRect *rect, int offset, int max_value)
{
    if (rect->top >= 0) {
        rect->top -= offset;
    } else {
        rect->top = -1;
    }
}

void print_hp(sfRenderWindow *window, sfIntRect rect, sfSprite *sprite)
{
    sfVector2f pos_hp = {1162, 875};

    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setPosition(sprite, pos_hp);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}
