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

char *my_evil_str(char *str)
{
    int	i = 0;
    int	j = 0;
    char a;

    while (str[i] != '\0') {
        i++;
    }
    i--;
    while (i != j && i > j) {
        a = str[i];
        str[i] = str[j];
        str[j] = a;
        i--;
        j++;
    }
    return (str);
}

int int_len(int nb)
{
    int cpt = 1;

    while (nb > 10) {
        nb = nb / 10;
        cpt++;
    }
    return cpt;
}

int my_strlen(char const *str)
{
    int c = 0;

    while (str[c] != '\0') {
        c = c + 1;
    }
    return c;
}

char *my_strncat(char *dest, char const *src, int nb)
{
    int	i = my_strlen(dest);
    int	count = 0;

    while (src[count] && count < nb) {
        dest[i + count] = src[count];
        count++;
    }
    dest[i + count] = '\0';
    return (dest);
}
