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

void menu_elts(sfRenderWindow *menu, sfVector2f pos_cursor)
{
    background(menu);
    logo(menu);
    buttons(menu);
    cursor(menu, pos_cursor);
}

void help_while(sfRenderWindow *menu)
{
    while (sfKeyboard_isKeyPressed(sfKeyEscape) == sfFalse) {
        sfRenderWindow_clear(menu, sfWhite);
        help(menu);
        sfRenderWindow_display(menu);
    }
}

sfVector2f key_events_menu(sfRenderWindow *me, sfMusic *mus, sfVector2f pos)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown) && pos.y == 600) {
        pos.y += 130;
    } else if (sfKeyboard_isKeyPressed(sfKeyUp) && pos.y == 730) {
        pos.y -= 130;
    }
    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        select_sound();
        if (pos.y == 730) {
            sfRenderWindow_close(me);
        }
        if (pos.y == 600) {
            sfRenderWindow_close(me);
            sfMusic_stop(mus);
            start_game(0);
        }
    }
    return pos;
}
