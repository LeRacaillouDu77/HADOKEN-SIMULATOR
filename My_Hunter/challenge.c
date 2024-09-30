/*
** EPITECH PROJECT, 2023
** MUL_my_hunter_$ACADEMIC_YEAR
** File description:
** my_hunter.c
*/

#include "my.h"
#include <string.h>
#include <SFML/Graphics.h>

void init_challenge(defi_t *defi, menu_t *m)
{
    m->buttons->defi_1 = init_button((sfVector2f){100, 350}, (sfVector2f){600, 150}, sfWhite);
    m->buttons->defi_2 = init_button((sfVector2f){100, 550}, (sfVector2f){600, 150}, sfWhite);
    m->buttons->defi_3 = init_button((sfVector2f){100, 750}, (sfVector2f){600, 150}, sfWhite);
    m->buttons->exit_defi = init_button((sfVector2f){800, 900}, (sfVector2f){200, 100}, sfTransparent);
    m->buttons->exit_defi->sprite = sfSprite_create();
    m->defi_selected = 0;
    m->buttons->defi_1->sprite = sfSprite_create();
    m->buttons->defi_2->sprite = sfSprite_create();
    m->buttons->defi_3->sprite = sfSprite_create();
    m->base_bubble = sfSprite_create();
    m->challenge1_bubble = sfSprite_create();
    m->challenge2_bubble = sfSprite_create();
    m->challenge3_bubble = sfSprite_create();
    m->highscore1 = get_highscore("highscores/defi1.txt");
    m->highscore2 = get_highscore("highscores/defi2.txt");
    m->highscore3 = get_highscore("highscores/defi3.txt");
    sfSprite_setTexture(m->buttons->exit_defi->sprite, sfTexture_createFromFile("ressources/images/exit_but.png", NULL), sfFalse);
    sfSprite_setPosition(m->buttons->exit_defi->sprite, (sfVector2f){800, 900});

    sfSprite_setTexture(m->buttons->defi_1->sprite, sfTexture_createFromFile("ressources/images/defi1.png", NULL), sfFalse);
    sfSprite_setPosition(m->buttons->defi_1->sprite, (sfVector2f){100, 350});

    sfSprite_setTexture(m->buttons->defi_2->sprite, sfTexture_createFromFile("ressources/images/defi2.png", NULL), sfFalse);
    sfSprite_setPosition(m->buttons->defi_2->sprite, (sfVector2f){100, 550});

    sfSprite_setTexture(m->buttons->defi_3->sprite, sfTexture_createFromFile("ressources/images/defi3.png", NULL), sfFalse);
    sfSprite_setPosition(m->buttons->defi_3->sprite, (sfVector2f){100, 750});

    sfSprite_setTexture(m->base_bubble, sfTexture_createFromFile("ressources/images/challenge_bubble_base.png", NULL), sfFalse);
    sfSprite_setPosition(m->base_bubble, (sfVector2f){1150, 200});
    sfSprite_setTexture(m->challenge1_bubble, sfTexture_createFromFile("ressources/images/challenge_1_bubble.png", NULL), sfFalse);
    sfSprite_setPosition(m->challenge1_bubble, (sfVector2f){1150, 200});
    sfSprite_setTexture(m->challenge2_bubble, sfTexture_createFromFile("ressources/images/challenge_2_bubble.png", NULL), sfFalse);
    sfSprite_setPosition(m->challenge2_bubble, (sfVector2f){1150, 200});
    sfSprite_setTexture(m->challenge3_bubble, sfTexture_createFromFile("ressources/images/challenge_3_bubble.png", NULL), sfFalse);
    sfSprite_setPosition(m->challenge3_bubble, (sfVector2f){1150, 200});

    sfSprite_setScale(m->buttons->exit_defi->sprite, (sfVector2f){0.85, 1});
    defi->bac_sprite = sfSprite_create();
    defi->text_bac = sfTexture_createFromFile("ressources/images/DEFI.png", NULL);
    sfSprite_setTexture(defi->bac_sprite, defi->text_bac, sfFalse);
}

void print_score_defi(menu_t *m)
{
    char *disp_score = int_to_str(m->highscore1);
    sfText *score = sfText_create();
    sfText *text_t = sfText_create();
    sfFont *font = sfFont_createFromFile(
    "ressources/fonts/VINA.ttf");
    sfVector2f pos_score = {800, 375};

    sfText_setString(score, strcat(disp_score, " seconds"));
    sfText_setCharacterSize(score, 80);
    sfText_setFont(score, font);
    sfText_setPosition(score, pos_score);
    sfRenderWindow_drawText(m->window, score, NULL);
    pos_score.y += 200;
    sfText_setPosition(score, pos_score);
    disp_score = int_to_str(m->highscore2);
    sfText_setString(score, strcat(disp_score, " seconds"));
    sfRenderWindow_drawText(m->window, score, NULL);
    pos_score.y += 200;
    sfText_setPosition(score, pos_score);
    disp_score = int_to_str(m->highscore3);
    sfText_setString(score, strcat(disp_score, " seconds"));
    sfRenderWindow_drawText(m->window, score, NULL);
    sfText_destroy(score);
    sfFont_destroy(font);
}

void free_challenge(defi_t *defi)
{
    sfSprite_destroy(defi->bac_sprite);
    sfTexture_destroy(defi->text_bac);
    free(defi);
}

static void set_to_default_bubble(menu_t *m, int defi_number)
{
    if (m->defi_selected != 1 && m->defi_selected != 2 && defi_number == 3)
        m->defi_selected = 0;
    else if (m->defi_selected != 2 && m->defi_selected != 3 && defi_number == 1)
        m->defi_selected = 0;
    else if (m->defi_selected != 1 && m->defi_selected != 3 && defi_number == 2)
        m->defi_selected = 0;
}

static void set_defi_number(menu_t *m, int defi_number)
{
    if (defi_number == 1)
        m->defi_selected = 1;
    else if (defi_number == 2)
        m->defi_selected = 2;
    else if (defi_number == 3)
        m->defi_selected = 3;  
}

void challenges(menu_t *m, button_struct *button, sfColor color, int defi_number)
{
    if (m->is_visible == sfFalse) {
        if (is_button_clicked(button, m) == sfTrue) {
            // lancer le défi ici
            sfRenderWindow_close(m->window);
            start_game(defi_number);
        } else if (is_hooved(button, m) == sfTrue) {
            set_defi_number(m, defi_number);
            sfRectangleShape_setOutlineColor(button->rect, sfRed);
            sfRectangleShape_setOutlineThickness(button->rect, 5);
        } else {
            set_to_default_bubble(m, defi_number);
            sfRectangleShape_setFillColor(button->rect, color);
            sfRectangleShape_setOutlineThickness(button->rect, 0);
        }
    }
}

void exit_challenge(menu_t *m, button_struct *button, sfColor color)
{
    if (m->is_visible == sfFalse) {
        if (is_button_clicked(button, m) == sfTrue) {
            m->is_visible = sfTrue;
        } else if (is_hooved(button, m) == sfTrue) {
            sfRectangleShape_setOutlineColor(button->rect, sfRed);
            sfRectangleShape_setOutlineThickness(button->rect, 5);
        } else {
            sfRectangleShape_setFillColor(button->rect, color);
            sfRectangleShape_setOutlineThickness(button->rect, 0);
        }
    }
}

void draw_challenge(defi_t *defi, menu_t *m)
{
    sfRenderWindow_drawSprite(m->window, defi->bac_sprite, NULL);
    sfRenderWindow_drawRectangleShape(m->window, m->buttons->defi_1->rect, NULL);
    sfRenderWindow_drawRectangleShape(m->window, m->buttons->defi_2->rect, NULL);
    sfRenderWindow_drawRectangleShape(m->window, m->buttons->defi_3->rect, NULL);
    sfRenderWindow_drawRectangleShape(m->window, m->buttons->exit_defi->rect, NULL);
    sfRenderWindow_drawSprite(m->window, m->buttons->exit_defi->sprite, NULL);
    sfRenderWindow_drawSprite(m->window, m->buttons->defi_1->sprite, NULL);
    sfRenderWindow_drawSprite(m->window, m->buttons->defi_2->sprite, NULL);
    sfRenderWindow_drawSprite(m->window, m->buttons->defi_3->sprite, NULL);
    print_akuma(m);
    if (m->defi_selected == 1)
        sfRenderWindow_drawSprite(m->window, m->challenge1_bubble, NULL);
    else if (m->defi_selected == 2)
        sfRenderWindow_drawSprite(m->window, m->challenge2_bubble, NULL);
    else if (m->defi_selected == 3)
        sfRenderWindow_drawSprite(m->window, m->challenge3_bubble, NULL);
    else
        sfRenderWindow_drawSprite(m->window, m->base_bubble, NULL);
    print_score_defi(m);
}
