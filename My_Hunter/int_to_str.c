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

int str_to_int(char *str)
{
    int pos = my_strlen(str);
    int total = 0;
    int cpt = 1;

    while (pos > 0) {
        if (str[pos - 1] < '0' || str[pos - 1] > '9') {
            return total;
        }
        total = total + (str[pos - 1] - '0') * cpt;
        cpt *= 10;
        pos --;
    }
    return total;
}

char *int_to_str(int nb)
{
    char *str = malloc(sizeof(char) * (int_len(nb)));
    int to_add = 0;
    char elt;

    str[0] = '\0';
    while (nb >= 10) {
        to_add = nb % 10;
        elt = to_add + 48;
        str = my_strncat(str, &elt, 1);
        nb = nb / 10;
    }
    elt = nb + 48;
    str = my_strncat(str, &elt, 1);
    str = my_evil_str(str);
    return str;
}
