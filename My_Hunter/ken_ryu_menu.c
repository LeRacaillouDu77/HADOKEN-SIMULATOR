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


void init_ken(sfRenderWindow *menu, sfIntRect rect)
{
    sfTexture *texture = sfTexture_createFromFile(
    "./ressources/spritesheets/ken_stand.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos = {100, 650};
    sfVector2f scale = {3, 3};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setTextureRect(sprite, rect);
    sfRenderWindow_drawSprite(menu, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

void init_ryu(sfRenderWindow *menu, sfIntRect rect)
{
    sfTexture *texture2 = sfTexture_createFromFile(
    "./ressources/spritesheets/ryu_menu.png", NULL);
    sfSprite *sprite2 = sfSprite_create();
    sfVector2f scale = {3, 3};
    sfVector2f pos2 = {1500, 650};

    sfSprite_setTexture(sprite2, texture2, sfTrue);
    sfSprite_setScale(sprite2, scale);
    sfSprite_setPosition(sprite2, pos2);
    sfSprite_setTextureRect(sprite2, rect);
    sfRenderWindow_drawSprite(menu, sprite2, NULL);
    sfTexture_destroy(texture2);
    sfSprite_destroy(sprite2);
}

sfIntRect ken_ryu_menu(sfRenderWindow *menu, sfIntRect rect, sfClock *clock)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if ( seconds >= 0.06) {
        move_rect(&rect, 78, 780);
        sfClock_restart(clock);
    }
    init_ken(menu, rect);
    init_ryu(menu, rect);
    return rect;
}
