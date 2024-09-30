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

sfMusic *play_game_music(void)
{
    sfMusic *music = sfMusic_createFromFile("ressources/music/theme.ogg");

    sfMusic_play(music);
    sfMusic_setLoop(music, sfTrue);
    return music;
}

void play_miss(void)
{
    sfMusic *miss = sfMusic_createFromFile("ressources/music/miss.ogg");

    sfMusic_play(miss);
}

void manage_mouse_click(sfRenderWindow *window)
{
    sfMusic *hadoken = sfMusic_createFromFile("ressources/music/hadoken.wav");

    sfMusic_setVolume(hadoken, 25);
    sfMusic_play(hadoken);
}

sfMusic *play_music(void)
{
    sfMusic *music = sfMusic_createFromFile(
    "./ressources/music/menu_theme.ogg");

    sfMusic_play(music);
    sfMusic_setLoop(music, sfTrue);
    return music;
}

void select_sound(void)
{
    sfMusic *select = sfMusic_createFromFile(
    "./ressources/music/select_sound.ogg");

    sfMusic_play(select);
}
