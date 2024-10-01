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

void background(sfRenderWindow *menu)
{
    sfTexture *texture = sfTexture_createFromFile(
    "./ressources/images/ken_stage.gif", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {2.2, 2};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    sfRenderWindow_drawSprite(menu, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

void logo(sfRenderWindow *menu)
{
    sfTexture *texture = sfTexture_createFromFile(
    "./ressources/images/logo.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos = {630, 50};
    sfVector2f scale = {1.10, 1.10};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(menu, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

void buttons(sfRenderWindow *menu)
{
    sfTexture *texture = sfTexture_createFromFile(
    "./ressources/images/buttons.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos = {1920 / 2 - 500 * 0.7, 650};
    sfVector2f scale = {0.7, 0.7};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(menu, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

void help(sfRenderWindow *menu)
{
    sfTexture *texture = sfTexture_createFromFile(
    "./ressources/images/help.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {1, 1};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    sfRenderWindow_drawSprite(menu, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

void cursor(sfRenderWindow *menu, sfVector2f pos)
{
    sfTexture *texture = sfTexture_createFromFile(
    "./ressources/images/cursor.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {0.2, 0.2};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(menu, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}
