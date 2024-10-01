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

sfBool is_button_clicked_go(button_struct *button, mgst *m)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(m->game_window);
    sfFloatRect float_rec = sfRectangleShape_getGlobalBounds(button->rect);

    if ((sfFloatRect_contains(&float_rec, pos_mouse.x, pos_mouse.y) == sfTrue)
    && (m->event.type == sfEvtMouseButtonPressed) &&
    (m->event.key.code == sfMouseLeft)) {
        sfRectangleShape_setFillColor(button->rect, sfBlue);
        return sfTrue;
    }
    return sfFalse;
}

sfBool is_hooved_go(button_struct *button, mgst *m)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(m->game_window);
    sfFloatRect float_rec = sfRectangleShape_getGlobalBounds(button->rect);

    if (sfFloatRect_contains(&float_rec, pos_mouse.x, pos_mouse.y) == sfTrue) {
        return sfTrue;
    }
    return sfFalse;
}

void retry(mgst *m, button_struct *button, sfColor color)
{
    if (m->is_gameover == sfTrue) {
        if (is_button_clicked_go(button, m) == sfTrue) {
            m->is_gameover = sfFalse;
            sfMusic_stop(m->music);
            sfRenderWindow_close(m->game_window);
            start_game(0);
        } else if (is_hooved_go(button, m) == sfTrue) {
            sfRectangleShape_setOutlineColor(button->rect, sfBlack);
            sfRectangleShape_setOutlineThickness(button->rect, 5);
        } else {
            sfRectangleShape_setFillColor(button->rect, color);
            sfRectangleShape_setOutlineThickness(button->rect, 0);
        }
    }
}

void quit(mgst *m, button_struct *button, sfColor color)
{
    if (m->is_gameover == sfTrue) {
        if (is_button_clicked_go(button, m) == sfTrue) {
            m->is_gameover = sfFalse;
            sfMusic_stop(m->music);
            write_score(m->score, "highscores/highscore.txt");
            sfRenderWindow_close(m->game_window);
            main2();
            exit(0);
        } else if (is_hooved_go(button, m) == sfTrue) {
            sfRectangleShape_setOutlineColor(button->rect, sfBlack);
            sfRectangleShape_setOutlineThickness(button->rect, 5);
        } else {
            sfRectangleShape_setFillColor(button->rect, color);
            sfRectangleShape_setOutlineThickness(button->rect, 0);
        }
    }
}

sfMusic *game_over_music(void)
{
    sfMusic *music = sfMusic_createFromFile(
    "ressources/music/gameover_theme.ogg");

    sfMusic_play(music);
    sfMusic_setLoop(music, sfTrue);
    return music;
}

void text1(sfText *text_t, char *text, sfFont *font, sfVector2f pos_text)
{
    sfText_setString(text_t, text);
    sfText_setCharacterSize(text_t, 80);
    sfText_setFont(text_t, font);
    sfText_setPosition(text_t, pos_text);
}

int print_score_game_over(sfRenderWindow *game_window, int score_int)
{
    char *text = "YOUR SCORE :";
    char *disp_score = int_to_str(score_int);
    sfText *score = sfText_create();
    sfText *text_t = sfText_create();
    sfFont *font = sfFont_createFromFile(
    "ressources/fonts/VINA.ttf");
    sfVector2f pos_score = {1000, 600};
    sfVector2f pos_text = {600, 600};

    text1(text_t, text, font, pos_text);
    sfRenderWindow_drawText(game_window, text_t, NULL);
    sfText_setString(score, disp_score);
    sfText_setCharacterSize(score, 80);
    sfText_setFont(score, font);
    sfText_setPosition(score, pos_score);
    sfRenderWindow_drawText(game_window, score, NULL);
    sfText_destroy(score);
    sfFont_destroy(font);
    return score_int;
}

void gameover(mgst *m, int defi)
{
    sfTexture *texture = sfTexture_createFromFile(
    "./ressources/images/gameover.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {5, 4.55};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    sfRenderWindow_drawSprite(m->game_window, sprite, NULL);
    print_score_game_over(m->game_window, m->score);
    if (defi == 0) {
        sfRenderWindow_drawRectangleShape(m->game_window, m->gameover_restart->rect, NULL);
        sfRenderWindow_drawSprite(m->game_window, m->gameover_restart->sprite, NULL);
    }
    sfRenderWindow_drawRectangleShape(m->game_window, m->gameover_quit->rect, NULL);
    sfRenderWindow_drawSprite(m->game_window, m->gameover_quit->sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

void gameov_h(mgst *m, int defi)
{
    sfMusic_stop(m->music);
    m->music = game_over_music();
    sfRenderWindow_setMouseCursorVisible(m->game_window, sfTrue);
    while (m->is_gameover == sfTrue) {
        while (sfRenderWindow_pollEvent(m->game_window, &m->event)) {
            quit(m, m->gameover_quit, sfWhite);
            if (defi == 0)
                retry(m, m->gameover_restart, sfWhite);
            if (m->event.type == sfEvtClosed) {
                sfMusic_stop(m->music);
                write_score(m->score, "highscores/highscore.txt");
                sfRenderWindow_close(m->game_window);
                exit(0);
            }
        }
        sfRenderWindow_clear(m->game_window, sfWhite);
        gameover(m, defi);
        sfRenderWindow_display(m->game_window);
    }
}