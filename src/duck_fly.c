/*
** EPITECH PROJECT, 2018
** duck direction
** File description:
** duck sprite change
*/

#include "my_hunter.h"

void duck_move(obj_t *tab, unsigned int skin, int id, unsigned int dir)
{
    if (dir == 0){
        duck_texture(tab, skin, id);
        sfSprite_setScale(tab[id].spr,  (sfVector2f){-3, 3});
        tab[id].move = (sfVector2f){-5, 0};
    }
    if (dir == 1) {
        duck_texture_angle(tab, skin, id);
        sfSprite_setScale(tab[id].spr,  (sfVector2f){-3, 3});
        tab[id].move = (sfVector2f){-5, -5};
    }
    if (dir == 2) {
        duck_texture_angle(tab, skin, id);
        sfSprite_setScale(tab[id].spr,  (sfVector2f){3, 3});
        tab[id].move = (sfVector2f){5, -5};
    }
    if (dir == 3) {
        duck_texture(tab, skin, id);
        sfSprite_setScale(tab[id].spr,  (sfVector2f){3, 3});
        tab[id].move = (sfVector2f){5, 0};
    }
}

void duck_direction(obj_t *tab, int id, unsigned int skin)
{
    unsigned int dir = randr(0, 4);

    if (tab[id].coord.y > 500)
        dir = randr(2, 3);
    tab[2].time = sfClock_getElapsedTime(tab[2].clock);
    tab[2].seconds = tab[2].time.microseconds / 1000000.0;
    if (tab[2].seconds > 0.7)
    {
        duck_move(tab, skin, id, dir);
        sfMusic_play(tab[5].music);
        sfClock_restart(tab[2].clock);
    }
    tab[id].coord.x = tab[id].coord.x + tab[id].move.x;
    tab[id].coord.y = tab[id].coord.y + tab[id].move.y;
}
