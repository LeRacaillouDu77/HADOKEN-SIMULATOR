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

void game_background(sfRenderWindow *window, char *filename)
{
    sfTexture *texture = sfTexture_createFromFile(
    filename, NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {2.2, 2};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

sfIntRect print_sprite(mgst *m)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(m->clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds >= 0.01) {
        move_rect(&m->ennemy.rect, 160, 960);
        sfClock_restart(m->clock);
    }
    sfSprite_setPosition(m->ennemy.sprite, m->move);
    sfSprite_setTextureRect(m->ennemy.sprite, m->ennemy.rect);
    sfRenderWindow_drawSprite(m->game_window, m->ennemy.sprite, NULL);
    return m->ennemy.rect;
}

void viseur(sfRenderWindow *game_window)
{
    sfTexture *texture = sfTexture_createFromFile(
    "./ressources/images/viseur.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {0.1, 0.1};
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(game_window);
    sfVector2f pos_sprite;

    pos_sprite.x = (float)pos_mouse.x - 25;
    pos_sprite.y = (float)pos_mouse.y - 25;
    sfRenderWindow_setMouseCursorVisible(game_window, sfFalse);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos_sprite);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_drawSprite(game_window, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

sfSprite *create_ennemy(sfRenderWindow *window)
{
    sfTexture *texture = sfTexture_createFromFile(
    "./ressources/spritesheets/ken.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}
