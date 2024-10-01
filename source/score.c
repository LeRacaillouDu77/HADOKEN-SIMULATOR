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
#include <fcntl.h>
#include <string.h>
#include "my.h"

void write_score(int score_int, char *filename)
{
    FILE *fp;
    char *score = int_to_str(score_int);

    if (score_int > get_highscore(filename) && strcmp(filename, "highscores/highscore.txt") == 0) {
        fp = fopen(filename, "w");
        fputs(int_to_str(score_int), fp);
        fclose(fp);
    } else if (score_int < get_highscore(filename) && strcmp(filename, "highscores/highscore.txt") != 0) {
        fp = fopen(filename, "w");
        fputs(int_to_str(score_int), fp);
        fclose(fp);
    }
}

int get_highscore(char *filename)
{
    int fd = open(filename, O_RDONLY);
    char buffer[BUFFSIZE];
    char *length;
    int highscore = 0;
    int i = 0;

    if (fd == -1) {
        write(2, ERR_MSG_OPEN, my_strlen(ERR_MSG_OPEN)+1);
        return highscore;
    }
    read(fd, buffer, BUFFSIZE);
    buffer[BUFFSIZE] = '\0';
    while ((buffer[i] >= '0') && (buffer[i] <= '9')) {
        i++;
    }
    length = malloc(sizeof(char) * i);
    my_strncat(length, buffer, i);
    highscore = str_to_int(length);
    close(fd);
    return highscore;
}

int print_score(sfRenderWindow *game_window, int score_int, int defi)
{
    char *disp_score;
    sfText *score = sfText_create();
    sfFont *font = sfFont_createFromFile("ressources/fonts/VINA.ttf");
    sfVector2f pos_score = {30, 875};

    disp_score = int_to_str(score_int);
    if (defi != 0)
        disp_score = my_strncat(disp_score, "/50", 3);
    sfText_setString(score, disp_score);
    sfText_setCharacterSize(score, 120);
    sfText_setFont(score, font);
    sfText_setPosition(score, pos_score);
    sfRenderWindow_drawText(game_window, score, NULL);
    sfText_destroy(score);
    sfFont_destroy(font);
    return score_int;
}

static int is_hit(mgst *m, sfVector2f pos_ennemy, sfVector2f pos_mouse_float)
{
    if ((((pos_ennemy.x <= pos_mouse_float.x)
    && (pos_ennemy.x >= pos_mouse_float.x - m->ken_game.width))
    && ((pos_ennemy.y <= pos_mouse_float.y)
    && (pos_ennemy.y >= pos_mouse_float.y - m->ken_game.height))))
        return 1;
    return 0;
}

int hit(mgst *m, sfSprite *ennemy, int score, sfIntRect *hp)
{
    sfVector2f pos_ennemy = sfSprite_getPosition(ennemy);
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(m->game_window);
    sfVector2f pos_mouse_float;

    pos_mouse_float.x = (float)pos_mouse.x;
    pos_mouse_float.y = (float)pos_mouse.y;
    if ((((pos_ennemy.x <= pos_mouse_float.x)
    && (pos_ennemy.x >= pos_mouse_float.x - 160))
    && ((pos_ennemy.y <= pos_mouse_float.y)
    && (pos_ennemy.y >= pos_mouse_float.y - 132))) ){
        m->ken_hit->is_visible = sfTrue;
        m->ken_hit->position = pos_ennemy;
        m->ken_hit->rect.left = 0;
        return score + 100;
    }
    play_miss();
    move_hp(hp, 185, 936);
    return score;
}

void ken_hit_animation(mgst *m)
{
    sfTime time;
    float seconds;

    if (m->ken_hit->rect.left >= 4887 - 181) {
        m->ken_hit->is_visible = sfFalse;
        m->ken_hit->rect.left = 0;
        sfClock_restart(m->ken_hit->clock);
        return;
    }
    time = sfClock_getElapsedTime(m->ken_hit->clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds >= 0.05) {
        move_rect(&m->ken_hit->rect, 181, 4887);
        sfClock_restart(m->ken_hit->clock);
    }
    sfSprite_setPosition(m->ken_hit->sprite, m->ken_hit->position);
    sfSprite_setTextureRect(m->ken_hit->sprite, m->ken_hit->rect);
    sfRenderWindow_drawSprite(m->game_window, m->ken_hit->sprite, NULL);
}

int hit_defi(mgst *m, sfSprite *ennemy, int score, sfIntRect *hp, int defi)
{
    sfVector2f pos_ennemy = sfSprite_getPosition(ennemy);
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(m->game_window);
    sfVector2f pos_mouse_float;
    sfVector2f scale_ennemy = sfSprite_getScale(ennemy);

    pos_mouse_float.x = (float)pos_mouse.x;
    pos_mouse_float.y = (float)pos_mouse.y;
    if (is_hit(m, pos_ennemy, pos_mouse_float) == 1) {
        m->ken_hit->is_visible = sfTrue;
        m->ken_hit->position = pos_ennemy;
        m->ken_hit->rect.left = 0;
        if (defi == 3 || defi == 1) {
            scale_ennemy.x = scale_ennemy.x * 0.97;
            scale_ennemy.y = scale_ennemy.y * 0.97;
            sfSprite_setScale(ennemy, scale_ennemy);
            sfSprite_setScale(m->ken_hit->sprite, scale_ennemy);
            m->ken_game.height *= 0.97;
            m->ken_game.width *= 0.97;
        }
        if (defi == 2 || defi == 3)
            m->direction = rand() % 2;
        m->ken_hit->is_visible = sfTrue;
        m->ken_hit->position = pos_ennemy;
        return score + 1;
    } else {
        play_miss();
        if (defi != 0)
            m->life_bar.rect.top = -1;
        return score;
    }
}

sfVector2f update_move(sfVector2f move, mgst *m, int defi)
{
    if (m->direction == 0) {
        if (move.x < -200)
            move.x = -160;
        if (move.x < 1792) {
            move.x += m->speed * int_len(m->score);
            return move;
        }
        if (m->move.x < 1920 && m->move.x > 1792) {
            if (defi == 3)
                m->life_bar.rect.top = -1;
            else {
                move_hp(&m->life_bar.rect, 185, 936);
                move.y = rand() % 700;
                move.x = -160;
                if (defi != 0)
                    m->direction = rand() % 2;
            }
            return move;
        }
    } else {
        if (move.x > 0) {
            move.x -= m->speed * int_len(m->score);
            return move;
        }
        else {
            if (defi == 3) 
                m->life_bar.rect.top = -1;
            else {
                move.y = rand() % 700;
                move.x = 1792;
                m->direction = rand() % 2;
            }
            return move;
        }
    }
}