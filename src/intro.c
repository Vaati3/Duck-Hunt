/*
** EPITECH PROJECT, 2018
** intro
** File description:
** amazing intro
*/

#include "my_hunter.h"

void dog_walk(sfRenderWindow *window, obj_t *tab)
{
    sfIntRect rect;

    rect.height = 45;
    rect.top = 0;
    rect.width = 55;
    tab[10].coord.x = tab[10].coord.x + 3;
    move_rect(&rect, (sfVector2i){272, 10}, 0.3, tab);
    sfSprite_setTextureRect(tab[10].spr, rect);
    sfSprite_setPosition(tab[10].spr, tab[10].coord);
    sfRenderWindow_drawSprite(window, tab[10].spr, NULL);
}

void dog_jump(sfRenderWindow *window, obj_t *tab)
{
    tab[10].coord.x = tab[10].coord.x + 2;
    if (tab[4].seconds < 6.4) {
        sfRenderWindow_drawSprite(window, tab[2].spr, NULL);
        tab[10].txt = sfTexture_createFromFile("sprites/dog_jump.png", NULL);
        sfSprite_setTexture(tab[10].spr, tab[10].txt, sfTrue);
        tab[10].coord.y = tab[10].coord.y - 13;
        sfSprite_setPosition(tab[10].spr, tab[10].coord);
        sfRenderWindow_drawSprite(window, tab[10].spr, NULL);
        if (tab[4].seconds > 6.35)
            sfMusic_play(tab[6].music);
    } else {
        tab[10].txt = sfTexture_createFromFile("sprites/dog_jump2.png", NULL);
        sfSprite_setTexture(tab[10].spr, tab[10].txt, sfTrue);
        tab[10].coord.y = tab[10].coord.y + 13;
        sfSprite_setPosition(tab[10].spr, tab[10].coord);
        sfRenderWindow_drawSprite(window, tab[10].spr, NULL);
        sfRenderWindow_drawSprite(window, tab[2].spr, NULL);
        if (tab[4].seconds > 6.59 && tab[4].seconds < 6.7)
            sfMusic_play(tab[6].music);
    }
}

void intro(sfRenderWindow *window, obj_t *tab)
{
    if (tab[4].seconds <= 0)
        sfMusic_play(tab[10].music);
    tab[4].time = sfClock_getElapsedTime(tab[4].clock);
    tab[4].seconds = tab[4].time.microseconds / 1000000.0;
    if (tab[4].seconds > 7)
        tab[10].index2 = 1;
    sfRenderWindow_drawSprite(window, tab[1].spr, NULL);
    if (tab[4].seconds > 6)
        dog_jump(window, tab);
    else
        sfRenderWindow_drawSprite(window, tab[2].spr, NULL);
    if (tab[4].seconds < 5)
        dog_walk(window, tab);
    else if (tab[4].seconds <= 6) {
        tab[10].txt = sfTexture_createFromFile("sprites/dog_wait.png", NULL);
        sfSprite_setTexture(tab[10].spr, tab[10].txt, sfTrue);
        sfRenderWindow_drawSprite(window, tab[10].spr, NULL);
    }
    draw_cursor(tab, window);
}