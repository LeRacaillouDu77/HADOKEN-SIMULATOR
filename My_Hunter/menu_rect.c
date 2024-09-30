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

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left < max_value - offset) {
        rect->left += offset;
    } else {
        rect->left = 0;
    }
}

sfIntRect def_rect(void)
{
    sfIntRect rect;

    rect.top = 0;
    rect.left = 0;
    rect.width = 78;
    rect.height = 111;
    return rect;
}

sfIntRect def_rect2(void)
{
    sfIntRect rect3;

    rect3.top = 0;
    rect3.left = 0;
    rect3.width = 160;
    rect3.height = 138;
    return rect3;
}

sfIntRect def_kenrect(void)
{
    sfIntRect ken_game;

    ken_game.top = 0;
    ken_game.left = 0;
    ken_game.height = 138;
    ken_game.width = 160;
    return ken_game;
}

sfIntRect def_lifebar(void)
{
    sfIntRect lifebar;

    lifebar.top = 1074 - 168;
    lifebar.left = 0;
    lifebar.height = 138;
    lifebar.width = 630;
    return lifebar;
}
