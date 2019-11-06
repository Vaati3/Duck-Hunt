/*
** EPITECH PROJECT, 2018
** duck
** File description:
** duck gestion
*/

#include "my_hunter.h"

void flying_duck(obj_t *tab, unsigned int skin, int id)
{
    sfIntRect rect;

    rect.top = 0;
    rect.height = 41;
    rect.width = 39;
    duck_direction(tab, id, skin);
    move_rect(&rect, (sfVector2i){158, id}, 0.2, tab);
    sfSprite_setTextureRect(tab[id].spr, rect);
    if (tab[id].coord.x > 1300 || tab[id].coord.x < 0 || tab[id].coord.y < 0) {
        tab[4].index = 3;
        tab[id].coord.x = rand() % 500;
        tab[id].coord.y = 600;
    }
}

void landing_duck(obj_t *tab, sfRenderWindow *window, int id)
{
    if (tab[id].coord.y > 600) {
        sfMusic_play(tab[4].music);
        tab[id].index2 = 0;
        if (id == 3)
            tab[0].index = 0;
        if (id == 12)
            tab[0].move.x = 0;
        if (id == 13)
            tab[0].move.y = 0;
        tab[id].coord.x = randr(200, 900);
        tab[id].coord.y = 650;
        tab[7].index = 1;
        tab[6].index = 0;
        tab[id - 2].move.x = randr(0, 3);
        duck_texture_angle(tab, tab[id - 2].move.x, id);
    }
}

void falling_duck(obj_t *tab, sfRenderWindow *window, int id)
{
    sfIntRect rect;

    rect.top = 0;
    rect.height = 41;
    rect.width = 24;
    tab[6].index = 1;
    duckfall_texture(tab, tab[id - 2].move.x, id);
    move_rect(&rect, (sfVector2i){96, id}, 0.3, tab);
    sfSprite_setTextureRect(tab[id].spr, rect);
    tab[id].coord.y = tab[id].coord.y + 7;
    if (tab[id].index2 == 0) {
        tab[id].index2 = 1;
        sfMusic_play(tab[1].music);
    }
    landing_duck(tab, window, id);
}

void draw_duck(obj_t *tab, sfRenderWindow *window, int id)
{
    if ((tab[0].index == 0 && id == 3) || (tab[0].move.x == 0 && id == 12)
    || (tab[0].move.y == 0 && id == 13)) {
        flying_duck(tab, tab[id - 2].move.x, id);
    } else if ((tab[0].index < 11 && id == 3) ||
        (tab[0].move.x < 11 && id == 12) ||
        (tab[0].move.y < 11 && id == 13)) {
        if (tab[0].index < 11 && id == 3)
            tab[0].index = tab[0].index + 1;
        if (tab[0].move.x < 11 && id == 12)
            tab[0].move.x = tab[0].move.x + 1;
        if (tab[0].move.y < 11 && id == 13)
            tab[0].move.y = tab[0].move.y + 1;
    } else {
        falling_duck(tab, window, id);
    }
    got_one_dog(tab, window, id);
    miss_one(tab, window);
    sfSprite_setPosition(tab[id].spr, tab[id].coord);
    sfRenderWindow_drawSprite(window, tab[id].spr, NULL);
}