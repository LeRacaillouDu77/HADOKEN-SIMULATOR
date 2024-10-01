/*
** EPITECH PROJECT, 2023
** epitech_pool_day09
** File description:
** file that contains all prototypes
*/

#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#ifndef MY_H
    #define MY_H

typedef struct ken {
    sfIntRect rect;
    sfSprite *sprite;
} st;

typedef struct button_s {
    sfRectangleShape *rect;
    sfSprite *sprite;
    sfTexture *text;
    sfVector2f size;
    sfVector2f pos;
    sfColor color;
} button_struct;

typedef struct all_buttons {
    button_struct *defi_menu;
    button_struct *defi_1;
    button_struct *defi_2;
    button_struct *defi_3;
    button_struct *exit_defi;
} all_buts;

typedef struct ken_ko {
    sfBool is_visible;
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f position;
    sfClock *clock;
} hit_t;

typedef struct akuma_defi_completed {
    sfBool is_visible;
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f position;
    sfClock *clock;
} defi_completed_t;


typedef struct mega {
    sfRenderWindow *game_window;
    sfEvent event;
    sfMusic *music;
    sfClock *clock;
    sfSprite *sprite_ennemy;
    sfIntRect ken_game;
    sfIntRect lifebar;
    sfBool is_gameover;
    int score;
    int comp;
    st life_bar;
    st ennemy;
    sfVector2f move;
    int speed;
    button_struct *gameover_restart;
    button_struct *gameover_quit;
    sfClock *defi_clock;
    int direction;
    hit_t *ken_hit;
} mgst;

typedef struct menu {
    sfRenderWindow *window;
    sfEvent event;
    sfMusic *music;
    sfVector2f pos_cursor;
    sfClock *clock;
    sfIntRect rect; 
    all_buts *buttons;
    sfBool is_visible;
    int highscore1;
    int highscore2;
    int highscore3;
    int defi_selected;
    sfSprite *base_bubble;
    sfSprite *challenge1_bubble;
    sfSprite *challenge2_bubble;
    sfSprite *challenge3_bubble;
    defi_completed_t *akuma_defi;
} menu_t;

typedef struct challenge {
    sfSprite *bac_sprite;
    sfTexture *text_bac;
} defi_t;

void start_game(int defi);
void move_rect(sfIntRect *rect, int offset, int max_value);
void manage_mouse_click(sfRenderWindow *window);
char *int_to_str(int nb);
int main(int ac, char **av);
void main2(void);
char *my_evil_str(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int str_to_int(char *str);
int my_strlen(char const *str);
int int_len(int nb);
sfIntRect ken_ryu_menu(sfRenderWindow *menu, sfIntRect rect, sfClock *clock);
void gameover(mgst *m, int defi);
int print_score_game_over(sfRenderWindow *game_window, int score_int);
sfMusic *game_over_music(void);
void print_hp(sfRenderWindow *window, sfIntRect rect, sfSprite *sprite);
void move_hp(sfIntRect *rect, int offset, int max_value);
sfSprite *create_life_bar(sfRenderWindow *window);
sfVector2f key_events_menu
(sfRenderWindow *menu, sfMusic *music, sfVector2f pos_cursor);
void menu_elts(sfRenderWindow *menu, sfVector2f pos_cursor);
sfIntRect def_rect2(void);
sfIntRect def_rect(void);
sfMusic *play_game_music(void);
void play_miss(void);
void manage_mouse_click(sfRenderWindow *window);
sfMusic *play_music(void);
void select_sound(void);
void write_score(int score_int, char *filename);
int get_highscore(char *filename);
int print_score(sfRenderWindow *game_window, int score_int, int defi);
int hit(mgst *m, sfSprite *ennemy, int score, sfIntRect *hp);
void background(sfRenderWindow *menu);
void logo(sfRenderWindow *menu);
void buttons(sfRenderWindow *menu);
void cursor(sfRenderWindow *menu, sfVector2f pos_cursor);
void help(sfRenderWindow *menu);
sfVector2f update_move(sfVector2f move, mgst *m, int defi);
sfIntRect def_lifebar(void);
sfIntRect def_kenrect(void);
void game_background(sfRenderWindow *window, char *filename);
sfIntRect print_sprite(mgst *m);
void viseur(sfRenderWindow *game_window);
sfSprite *create_ennemy(sfRenderWindow *window);
void gameov_h(mgst *m, int defi);
sfVector2f m_ev(menu_t *menu);
button_struct *init_button(sfVector2f position, sfVector2f size, sfColor color);
sfBool is_button_clicked(button_struct *button, menu_t *m);
sfBool is_hooved(button_struct *button, menu_t *m);
void disp_buttons(all_buts *but, menu_t *m);
void colors(menu_t *m, button_struct *button, sfColor color);
void init_menu_button(menu_t *m);
void free_menu_t(menu_t *m);
void init_challenge(defi_t *defi, menu_t *m);
void free_challenge(defi_t *defi);
void draw_challenge(defi_t *defi, menu_t *m);
void exit_challenge(menu_t *m, button_struct *button, sfColor color);
void challenges(menu_t *m, button_struct *button, sfColor color, int defi_number);
int hit_defi(mgst *m, sfSprite *ennemy, int score, sfIntRect *hp, int defi);
void ken_hit_animation(mgst *m);
void init_akuma_defi(menu_t *menu);
void akuma_is_visible(menu_t *menu);
void print_akuma(menu_t *menu);
void free_akuma_struct(defi_completed_t *akuma);

    #define ERR_MSG_OPEN "File can't be open"
    #define BUFFSIZE 30000

#endif /* MY_H */
