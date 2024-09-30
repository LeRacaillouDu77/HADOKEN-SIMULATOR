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

sfText *init_text_t(sfText *text_t, char *text, sfFont *font)
{
    sfText_setString(text_t, text);
    sfText_setCharacterSize(text_t, 80);
    sfText_setFont(text_t, font);
    return text_t;
}

int print_highscore(sfRenderWindow *game_window, int score_int)
{
    char *text = "HIGHSCORE :";
    char *disp_score = int_to_str(score_int);
    sfText *score = sfText_create();
    sfText *text_t = sfText_create();
    sfFont *font = sfFont_createFromFile("ressources/fonts/VINA.ttf");
    sfVector2f pos_score = {375, 0};
    sfVector2f pos_text = {50, 0};

    text_t = init_text_t(text_t, text, font);
    sfText_setPosition(text_t, pos_text);
    sfRenderWindow_drawText(game_window, text_t, NULL);
    sfText_setString(score, disp_score);
    sfText_setCharacterSize(score, 80);
    sfText_setFont(score, font);
    sfText_setPosition(score, pos_score);
    sfRenderWindow_drawText(game_window, score, NULL);
    sfText_destroy(score);
    sfText_destroy(text_t);
    sfFont_destroy(font);
    return score_int;
}

static sfRenderWindow *init_window(void)
{
    sfVideoMode mode = {1920, 1080, 64};
    sfRenderWindow *menu;

    menu = sfRenderWindow_create(mode, "My Hunter", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(menu, 60);
    return menu;
}

sfVector2f m_ev(menu_t *menu)
{
    while (sfRenderWindow_pollEvent(menu->window, &menu->event)) {
        if (menu->event.type == sfEvtClosed) {
            sfRenderWindow_close(menu->window);
        }
        menu->pos_cursor = key_events_menu(menu->window, menu->music, menu->pos_cursor);
        colors(menu, menu->buttons->defi_menu, sfTransparent);
        exit_challenge(menu, menu->buttons->exit_defi, sfTransparent);
        challenges(menu, menu->buttons->defi_1, sfWhite, 1);
        challenges(menu, menu->buttons->defi_2, sfWhite, 2);
        challenges(menu, menu->buttons->defi_3, sfWhite, 3);
    }
    return menu->pos_cursor;
}

static void h_opt(void)
{
    int fd;
    char buffer[BUFFSIZE];
    int size;
    int i = 1;

    fd = open("help_msg.txt", O_RDONLY);
    size = read(fd, buffer, BUFFSIZE);
    buffer[BUFFSIZE] = '\0';
    write(1, buffer, size);
    close(fd);
    i++;
}

static void init_menu(menu_t *menu)
{
    menu->window = init_window();
    menu->event;
    menu->music = play_music();
    menu->pos_cursor = (sfVector2f){750, 600};
    menu->clock = sfClock_create();
    menu->rect = def_rect();
    menu->buttons = malloc(sizeof(all_buts));
    init_akuma_defi(menu);
    init_menu_button(menu);
}

void main2(void)
{
    int score = 0;
    menu_t *menu = malloc(sizeof(menu_t));
    defi_t *defi = malloc(sizeof(defi_t));
    init_menu(menu);
    init_challenge(defi, menu);
    akuma_is_visible(menu);

    while (sfRenderWindow_isOpen(menu->window)) {
        menu->pos_cursor = m_ev(menu);
        sfRenderWindow_clear(menu->window, sfWhite);
        if (menu->is_visible == sfTrue) {
            menu_elts(menu->window, menu->pos_cursor);
            menu->rect = ken_ryu_menu(menu->window, menu->rect, menu->clock);
            score = get_highscore("highscores/highscore.txt");
            print_highscore(menu->window, score);
            disp_buttons(menu->buttons, menu);
        } else {
                while (sfRenderWindow_pollEvent(menu->window, &menu->event)) {
        challenges(menu, menu->buttons->defi_1, sfWhite, 1);
        challenges(menu, menu->buttons->defi_2, sfWhite, 2);
        challenges(menu, menu->buttons->defi_3, sfWhite, 3);
    }
            draw_challenge(defi, menu);
        }
        sfRenderWindow_display(menu->window);
    }
    sfRenderWindow_destroy(menu->window);
    free_menu_t(menu);
    free_challenge(defi);
    free_akuma_struct(menu->akuma_defi);
}

int main(int ac, char **av)
{
    srand(time(NULL));
    if (ac == 2) {
        h_opt();
    } else {
        main2();
    }
    return 0;
}
