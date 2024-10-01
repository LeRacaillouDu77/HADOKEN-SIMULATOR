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
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(menu);
    sfVector2f true_pos_mouse = (sfVector2f){pos_mouse.x - (512 * 0.2 / 2), pos_mouse.y - (412 * 0.2 / 2)};
    if (true_pos_mouse.y >= 650 && true_pos_mouse.y < 650 + 125 * 0.7 && (true_pos_mouse.x <= 1920 / 2 + 500 * 0.7 && true_pos_mouse.x > 1920 / 2 || true_pos_mouse.x >= 1920 / 2 - 500 * 0.7 && true_pos_mouse.x <= 1920 / 2)) {
        sfRenderWindow_setMouseCursorVisible(menu, sfFalse);
        cursor(menu, true_pos_mouse);
    } else {
        sfRenderWindow_setMouseCursorVisible(menu, sfTrue);
    }
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
    /*if (sfKeyboard_isKeyPressed(sfKeyDown) && pos.y == 600) {
        pos.y += 130;
    } else if (sfKeyboard_isKeyPressed(sfKeyUp) && pos.y == 730) {
        pos.y -= 130;
    }*/
    sfVector2i pos_m = sfMouse_getPositionRenderWindow(me);
    if (sfMouse_isButtonPressed(sfMouseLeft) && pos_m.y >= 650 && pos_m.y < 650 + 125 * 0.7) {
        if (pos_m.x <= 1920 / 2 + 500 * 0.7 && pos_m.x > 1920 / 2) {
            sfRenderWindow_close(me);
        }
        if (pos_m.x >= 1920 / 2 - 500 * 0.7 && pos_m.x <= 1920 / 2) {
            select_sound();
            sfRenderWindow_close(me);
            sfMusic_stop(mus);
            start_game(0);
        }
    }
    return pos;
}
