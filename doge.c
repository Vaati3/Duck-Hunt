/*
** EPITECH PROJECT, 2018
** such doge
** File description:
** dog gestion
*/

#include "my_hunter.h"

void got_one_dog(obj_t *tab, sfRenderWindow *window, int id)
{
    tab[7].time = sfClock_getElapsedTime(tab[7].clock);
    tab[7].seconds = tab[7].time.microseconds / 1000000.0;
    if (tab[7].seconds < 1.5 && tab[7].index == 1 && tab[9].index == 0) {
        if (tab[7].seconds < 0.3000)
            sfMusic_play(tab[7].music);
        if (tab[7].seconds < 0.4)
            tab[7].coord.y = tab[7].coord.y - 3;
        else
            tab[7].coord.y = tab[7].coord.y + 3;
        sfSprite_setPosition(tab[7].spr, tab[7].coord);
        sfRenderWindow_drawSprite(window, tab[7].spr, NULL);
    } else {
        sfClock_restart(tab[7].clock);
        tab[7].index = 0;
        tab[7].coord.x = tab[id].coord.x - 56;
        tab[7].coord.y = 550;
    }
}

sfIntRect init_miss_one(obj_t *tab)
{
    sfIntRect rect;

    rect.top = 0;
    rect.width = 37;
    rect.height = 150;
    tab[1].time = sfClock_getElapsedTime(tab[1].clock);
    tab[1].seconds = tab[1].time.microseconds / 1000000.0;
    return (rect);
}

void miss_one(obj_t *tab, sfRenderWindow *window)
{
    sfIntRect rect = init_miss_one(tab);

    if (tab[1].seconds < 1.5 && tab[8].index2 == 1 && tab[9].index == 0) {
        if (tab[1].seconds < 0.3000)
            sfMusic_play(tab[8].music);
        if (tab[1].seconds < 0.4)
            tab[8].coord.y = tab[8].coord.y - 3;
        else
            tab[8].coord.y = tab[8].coord.y + 3;
        sfSprite_setPosition(tab[8].spr, tab[8].coord);
        move_rect(&rect, (sfVector2i){74, 8}, 0.2, tab);
        sfSprite_setTextureRect(tab[8].spr, rect);
        sfRenderWindow_drawSprite(window, tab[8].spr, NULL);
    } else {
        sfClock_restart(tab[1].clock);
        tab[8].index2 = 0;
        tab[8].coord.x = 462;
        tab[8].coord.y = 550;
    }
}

/*void got_perfect(obj_t *tab, sfRenderWindow *window)
{
    if (tab[9].seconds < 1.5 ) {
        tab[9].time = sfClock_getElapsedTime(tab[9].clock);
        tab[9].seconds = tab[9].time.microseconds / 1000000.0;
        if (tab[9].seconds < 0.3000)
            sfMusic_play(tab[9].music);
        if (tab[9].seconds < 0.5)
            tab[9].coord.y = tab[9].coord.y - 3;
        else
            tab[9].coord.y = tab[9].coord.y + 3;
        sfSprite_setPosition(tab[9].spr, tab[9].coord);
        sfRenderWindow_drawSprite(window, tab[9].spr, NULL);
    } else {
        sfClock_restart(tab[9].clock);
        tab[9].index = 0;
        tab[9].coord.x = 462;
        tab[9].coord.y = 525;
    }
}*/