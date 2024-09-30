/*
** EPITECH PROJECT, 2023
** MUL_my_hunter_$ACADEMIC_YEAR
** File description:
** my_hunter.c
*/

#include "my.h"
#include <SFML/Graphics.h>

button_struct *init_button(sfVector2f position, sfVector2f size, sfColor color)
{
    button_struct *button = malloc(sizeof(button_struct));

    button->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect, position);
    sfRectangleShape_setSize(button->rect, size);
    sfRectangleShape_setFillColor(button->rect, color);
    return button;
}

sfBool is_button_clicked(button_struct *button, menu_t *m)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(m->window);
    sfFloatRect float_rec = sfRectangleShape_getGlobalBounds(button->rect);

    if ((sfFloatRect_contains(&float_rec, pos_mouse.x, pos_mouse.y) == sfTrue)
    && (m->event.type == sfEvtMouseButtonPressed) &&
    (m->event.key.code == sfMouseLeft)) {
        sfRectangleShape_setFillColor(button->rect, sfBlue);
        return sfTrue;
    }
    return sfFalse;
}

sfBool is_hooved(button_struct *button, menu_t *m)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(m->window);
    sfFloatRect float_rec = sfRectangleShape_getGlobalBounds(button->rect);

    if (sfFloatRect_contains(&float_rec, pos_mouse.x, pos_mouse.y) == sfTrue) {
        return sfTrue;
    }
    return sfFalse;
}

/*
void print_size(menu_t *m)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();
    sfVector2f size;
    sfVector2f pos;

    size.x = m->current_size;
    size.y = m->current_size;
    pos.x = 215;
    pos.y = 333;
    sfRectangleShape_setSize(rectangle, size);
    sfRectangleShape_setFillColor(rectangle, m->current_color);
    sfRectangleShape_setPosition(rectangle, pos);
    sfRenderWindow_drawRectangleShape(m->window, rectangle, NULL);
    sfRectangleShape_destroy(rectangle);
}
*/
void disp_buttons(all_buts *but, menu_t *m)
{
    sfRenderWindow_drawRectangleShape(m->window, m->buttons->defi_menu->rect, NULL);
    sfRenderWindow_drawSprite(m->window, m->buttons->defi_menu->sprite, NULL);
}

void colors(menu_t *m, button_struct *button, sfColor color)
{
    if (m->is_visible == sfTrue) {
        if (is_button_clicked(button, m) == sfTrue) {
            m->is_visible = sfFalse;
        } else if (is_hooved(button, m) == sfTrue) {
            sfRectangleShape_setOutlineColor(button->rect, sfBlack);
            sfRectangleShape_setOutlineThickness(button->rect, 5);
        } else {
            sfRectangleShape_setFillColor(button->rect, color);
            sfRectangleShape_setOutlineThickness(button->rect, 0);
        }
    }
}

void init_menu_button(menu_t *m)
{
    m->buttons->defi_menu = init_button((sfVector2f){1725, 20}, (sfVector2f){180, 180}, sfTransparent);
    m->buttons->defi_menu->sprite = sfSprite_create();
    m->buttons->defi_menu->text = sfTexture_createFromFile("ressources/images/defi_logo.jpg", NULL);
    sfSprite_setTexture(m->buttons->defi_menu->sprite, m->buttons->defi_menu->text, sfFalse);
    sfSprite_setPosition(m->buttons->defi_menu->sprite, (sfVector2f){1725, 20});
    sfSprite_setScale(m->buttons->defi_menu->sprite, (sfVector2f){0.36, 0.36});
    m->is_visible = sfTrue;
}

void free_menu_t(menu_t *m)
{
    sfSprite_destroy(m->buttons->defi_menu->sprite);
    sfSprite_destroy(m->buttons->defi_1->sprite);
    sfSprite_destroy(m->buttons->defi_2->sprite);
    sfSprite_destroy(m->buttons->defi_3->sprite);
    sfTexture_destroy(m->buttons->defi_menu->text);
    free(m->buttons->defi_menu);
    free(m->buttons);
    free(m);
}