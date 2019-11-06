/*
** EPITECH PROJECT, 2018
** texture change
** File description:
** texture gestion
*/

#include "my_hunter.h"

void duckfall_texture(obj_t *tab, unsigned int skin, int id)
{
    if (skin == 0)
        tab[id].txt = sfTexture_createFromFile("sprites/duckfall1.png",
            NULL);
    if (skin == 1)
        tab[id].txt = sfTexture_createFromFile("sprites/duckfall2.png",
            NULL);
    if (skin == 2)
        tab[id].txt = sfTexture_createFromFile("sprites/duckfall3.png",
            NULL);
    sfSprite_setTexture(tab[id].spr, tab[id].txt, sfTrue);
    sfSprite_setOrigin(tab[id].spr, (sfVector2f){19, 21});
}

void duckshot_texture(obj_t *tab, unsigned int skin, int id)
{
    if (skin == 0)
        tab[id].txt = sfTexture_createFromFile("sprites/duckshot1.png",
            NULL);
    if (skin == 1)
        tab[id].txt = sfTexture_createFromFile("sprites/duckshot2.png",
            NULL);
    if (skin == 2)
        tab[id].txt = sfTexture_createFromFile("sprites/duckshot3.png",
            NULL);
    sfSprite_setTexture(tab[id].spr, tab[id].txt, sfTrue);
    sfSprite_setOrigin(tab[id].spr, (sfVector2f){19, 21});
}

void duck_texture_angle(obj_t *tab, unsigned int skin, int id)
{
    if (skin == 0)
        tab[id].txt = sfTexture_createFromFile("sprites/duckup1.png",
            NULL);
    if (skin == 1)
        tab[id].txt = sfTexture_createFromFile("sprites/duckup2.png",
            NULL);
    if (skin == 2)
        tab[id].txt = sfTexture_createFromFile("sprites/duckup3.png",
            NULL);
    sfSprite_setTexture(tab[id].spr, tab[id].txt, sfTrue);
    sfSprite_setOrigin(tab[id].spr, (sfVector2f){19, 21});
}

void duck_texture(obj_t *tab, unsigned int skin, int id)
{
    if (skin == 0)
        tab[id].txt = sfTexture_createFromFile("sprites/duck1.png",
            NULL);
    if (skin == 1)
        tab[id].txt = sfTexture_createFromFile("sprites/duck2.png",
            NULL);
    if (skin == 2)
        tab[id].txt = sfTexture_createFromFile("sprites/duck3.png",
            NULL);
    sfSprite_setTexture(tab[id].spr, tab[id].txt, sfTrue);
    sfSprite_setOrigin(tab[id].spr, (sfVector2f){19, 21});
}