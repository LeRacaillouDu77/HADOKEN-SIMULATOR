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

static void quit_game(sfRenderWindow *wind, sfMusic *mus, sfSprite *sprite)
{
    sfRenderWindow_close(wind);
    sfMusic_stop(mus);
    main2();
}

static void mega_structure(mgst *m)
{
    m->game_window;
    m->event;
    m->music = play_game_music();
    m->clock;
    m->sprite_ennemy = create_ennemy(m->game_window);
    m->ken_game = def_kenrect();
    m->lifebar = def_lifebar();
    m->score = 0;
    m->comp = 0;
    m->life_bar;
    m->ennemy;
    m->move;
    m->gameover_restart = init_button((sfVector2f){1450, 850}, (sfVector2f){200, 100}, sfWhite);
    m->gameover_quit = init_button((sfVector2f){1700, 850}, (sfVector2f){200, 100}, sfWhite);
    m->gameover_restart->sprite = sfSprite_create();
    m->gameover_quit->sprite = sfSprite_create();
    sfSprite_setTexture(m->gameover_restart->sprite, sfTexture_createFromFile("ressources/images/restart.png", NULL), sfFalse);
    sfSprite_setTexture(m->gameover_quit->sprite, sfTexture_createFromFile("ressources/images/quit.png", NULL), sfFalse);
    sfSprite_setPosition(m->gameover_restart->sprite, (sfVector2f){1450, 850});
    sfSprite_setPosition(m->gameover_quit->sprite, (sfVector2f){1700, 850});
    m->ken_hit = malloc(sizeof(hit_t));
    m->ken_hit->sprite = sfSprite_create();
    m->ken_hit->texture = sfTexture_createFromFile("ressources/spritesheets/ken_hit.png", NULL);
    m->ken_hit->clock = sfClock_create();
    m->ken_hit->rect = (sfIntRect){0, 0, 181, 120};
    m->ken_hit->is_visible = sfFalse;
    sfSprite_setTexture(m->ken_hit->sprite, m->ken_hit->texture, sfFalse);
    sfSprite_setTextureRect(m->ken_hit->sprite, m->ken_hit->rect);
}

static void pause_game(mgst *m)
{
    sfMusic *za_warudo = sfMusic_createFromFile(
    "ressources/music/za_warudo.ogg");
    sfMusic *resume = sfMusic_createFromFile("ressources/music/resume.ogg");
    sfTime resume_time;

    resume_time.microseconds = 2500000;
    if (sfKeyboard_isKeyPressed(sfKeyP)) {
        sfMusic_pause(m->music);
        sfMusic_play(za_warudo);
        while (sfKeyboard_isKeyPressed(sfKeyR) == sfFalse) {
        }
        sfMusic_play(resume);
        sfSleep(resume_time);
        sfMusic_destroy(resume);
        sfMusic_destroy(za_warudo);
        sfMusic_play(m->music);
    }
}

static void game_evt2(mgst *m, int defi)
{
    if (m->event.type == sfEvtClosed) {
            sfRenderWindow_close(m->game_window);
        }
        if (m->event.type == sfEvtKeyPressed) {
            if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
                quit_game(m->game_window, m->music, m->ennemy.sprite);
            }
            pause_game(m);
        }
        if (m->event.type == sfEvtMouseButtonPressed && defi == 0) {
            m->score = hit(m,
            m->ennemy.sprite, m->score, &m->life_bar.rect);
            manage_mouse_click(m->game_window);
            if (m->comp != m->score) {
                m->move.x = -160;
                m->move.y = rand() % 700;
                m->comp = m->score;
            }
        } else if (m->event.type == sfEvtMouseButtonPressed && defi != 0) {
            m->score = hit_defi(m,
            m->ennemy.sprite, m->score, &m->life_bar.rect, defi);
            manage_mouse_click(m->game_window);
            if (m->comp != m->score) {
                if (m->direction == 0) {
                    m->move.x = -160;
                    m->move.y = rand() % 700;
                } else {
                    m->move.x = 1920;
                    m->move.y = rand() % 700;
                }
                m->comp = m->score;
            }
        }
}

static void hardcore_mod(mgst *m)
{
    if (sfKeyboard_isKeyPressed(sfKeyS) && sfKeyboard_isKeyPressed(sfKeyD)) {
        m->speed = 15;
    }
}

static void game_events(mgst *m, int defi)
{
    while (sfRenderWindow_pollEvent(m->game_window, &m->event)) {
        hardcore_mod(m);
        game_evt2(m, defi);
        if (m->life_bar.rect.top == -1) {
            m->is_gameover = sfTrue;
            gameov_h(m, defi);
            exit(0);
        }
        if (defi == 1 && m->score == 50) {
            sfRenderWindow_close(m->game_window);
            write_score(sfTime_asSeconds(sfClock_getElapsedTime(m->defi_clock)), "highscores/defi1.txt");
            sfClock_destroy(m->defi_clock);
            main2();
        }
        if (defi == 2 && m->score == 50) {
            sfRenderWindow_close(m->game_window);
            write_score(sfTime_asSeconds(sfClock_getElapsedTime(m->defi_clock)), "highscores/defi2.txt");
            sfClock_destroy(m->defi_clock);
            main2();
        }
        if (defi == 3 && m->score == 50) {
            sfRenderWindow_close(m->game_window);
            write_score(sfTime_asSeconds(sfClock_getElapsedTime(m->defi_clock)), "highscores/defi3.txt");
            sfClock_destroy(m->defi_clock);
            main2();
        }
    }
}

static void game_regular(mgst *m)
{
    sfRenderWindow_clear(m->game_window, sfWhite);
    game_background(m->game_window, "ressources/images/game_stage.gif");
    print_hp(m->game_window, m->life_bar.rect, m->life_bar.sprite);
    m->ennemy.rect = print_sprite(m);
    if (m->ken_hit->is_visible == sfTrue)
        ken_hit_animation(m);
    m->score = print_score(m->game_window, m->score, 0);
    viseur(m->game_window);
    m->move = update_move(m->move, m, 0);
    sfRenderWindow_display(m->game_window);
}

static void game_defi1(mgst *m)
{
    sfRenderWindow_clear(m->game_window, sfWhite);
    game_background(m->game_window, "ressources/images/defi1_stage.gif");
    m->ennemy.rect = print_sprite(m);
    if (m->ken_hit->is_visible == sfTrue)
        ken_hit_animation(m);
    m->score = print_score(m->game_window, m->score, 1);
    viseur(m->game_window);
    m->move = update_move(m->move, m, 1);
    sfRenderWindow_display(m->game_window);
}

static void game_defi2(mgst *m)
{
    sfRenderWindow_clear(m->game_window, sfWhite);
    game_background(m->game_window, "ressources/images/defi2_stage.gif");
    m->ennemy.rect = print_sprite(m);
    if (m->ken_hit->is_visible == sfTrue)
        ken_hit_animation(m);
    m->score = print_score(m->game_window, m->score, 2);
    viseur(m->game_window);
    m->move = update_move(m->move, m, 2);
    sfSprite_setPosition(m->sprite_ennemy, m->move);
    sfRenderWindow_display(m->game_window);
}

static void game_defi3(mgst *m)
{
    sfRenderWindow_clear(m->game_window, sfWhite);
    game_background(m->game_window, "ressources/images/defi3_stage.gif");
    m->ennemy.rect = print_sprite(m);
    if (m->ken_hit->is_visible == sfTrue)
        ken_hit_animation(m);
    m->score = print_score(m->game_window, m->score, 3);
    viseur(m->game_window);
    m->move = update_move(m->move, m, 3);
    sfRenderWindow_display(m->game_window);
}

void start_game(int defi)
{
    mgst m;
    sfVideoMode mode = {1920, 1080, 64};

    mega_structure(&m);
    m.speed = 5;
    m.game_window = sfRenderWindow_create(
    mode, "My Hunter", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(m.game_window, 60);
    m.clock = sfClock_create();
    m.defi_clock = sfClock_create();
    m.ennemy.rect = m.ken_game;
    m.ennemy.sprite = m.sprite_ennemy;
    m.life_bar.rect = m.lifebar;
    m.life_bar.sprite = create_life_bar(m.game_window);
    m.direction = 0;
    srand(sfTime_asMicroseconds(sfClock_getElapsedTime(m.clock)));
    while (sfRenderWindow_isOpen(m.game_window)) {
        game_events(&m, defi);
        if (defi == 0)
            game_regular(&m);
        if (defi == 1)
            game_defi1(&m);
        if (defi == 2)
            game_defi2(&m);
        if (defi == 3)
            game_defi3(&m);
    }
    sfRenderWindow_destroy(m.game_window);
}
