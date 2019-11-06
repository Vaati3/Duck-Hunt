/*
** EPITECH PROJECT, 2018
** ammo and score
** File description:
** ammo and score gestion
*/

#include "my_hunter.h"

void draw_ammo(obj_t *tab, sfRenderWindow *window)
{
    sfIntRect rect;

    rect.top = 0;
    rect.left = 0;
    rect.height = 9;
    if (tab[4].index >= 3)
        rect.width = 0;
    if (tab[4].index == 2)
        rect.width = 8;
    if (tab[4].index == 1)
        rect.width = 16;
    if (tab[4].index == 0)
        rect.width = 26;
    sfSprite_setPosition(tab[4].spr, tab[4].coord);
    sfSprite_setTextureRect(tab[4].spr, rect);
    sfRenderWindow_drawSprite(window, tab[4].spr, NULL);
}

void miss_or_hit(obj_t *tab, int *score, sfRenderWindow *window)
{
    int i = 0;

    tab[6].coord.x = 427;
    while (i < 10)
    {
        if (score[i] == 1) {
            sfSprite_setPosition(tab[6].spr, tab[6].coord);
            sfRenderWindow_drawSprite(window, tab[6].spr, NULL);
        }
        tab[6].coord.x = tab[6].coord.x + 36;
        i++;
    }
}

void score_hit(obj_t *tab, int *score)
{
    tab[6].index2 = 0;
    if (tab[4].index2 == 1 && tab[5].index2 < 10) {
        tab[4].index = 0;
        tab[4].index2 = 0;
        if (tab[6].index == 0) {
            score[tab[5].index2] = 1;
            tab[5].index2 = tab[5].index2 + 1;
            tab[6].index2 = tab[6].index2 + 36;
            tab[5].coord.x = tab[5].coord.x + tab[6].index2;
            tab[5].move.x = tab[5].move.x + 150;
        } else
            tab[5].move.x = tab[5].move.x + 50;
    } else if (tab[4].index >= 3 && tab[5].index2 < 10) {
        miss(tab, score);
    }
}

void point(obj_t *tab, sfRenderWindow *window)
{
    int len = nbrlen((int)tab[5].move.x);
    char buf[len + 1];
    int i = 0;
    int tmp = (int)tab[5].move.x;

    buf[len] = '\0';
    while (len > 0) {
        len--;
        buf[len] = (tmp % 10) + '0';
        tmp = tmp / 10;
    }
    draw_text(buf, (sfVector2f){905, 835}, 25, window);
    draw_text("score", (sfVector2f){910, 865}, 25, window);
}

void draw_score(obj_t *tab, int *score, sfRenderWindow *window)
{
    sfIntRect rect;

    score_hit(tab, score);
    rect.height = 9;
    rect.top = 0;
    rect.width = 8;
    move_rect(&rect, (sfVector2i){145, 5}, 0.1, tab);
    sfSprite_setTextureRect(tab[5].spr, rect);
    sfSprite_setPosition(tab[5].spr, tab[5].coord);
    if (tab[5].index2 < 10) {
        sfRenderWindow_drawSprite(window, tab[5].spr, NULL);
    }
    miss_or_hit(tab, score, window);
}