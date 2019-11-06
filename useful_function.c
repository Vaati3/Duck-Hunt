/*
** EPITECH PROJECT, 2018
** useful_function
** File description:
** useful function
*/

#include "my_hunter.h"

void init_duck(obj_t *tab, int id)
{
    unsigned int u = randr(0, 2);
    tab[id - 2].move.x = randr(0, 3);

    if (u == 0) {
        tab[id].move = (sfVector2f){-3, -3};
        duck_texture_angle(tab, tab[id - 2].move.x, id);
    }
    else {
        tab[id].move = (sfVector2f){3, -3};
        duck_texture_angle(tab, tab[id - 2].move.x, id);
    }
    sfSprite_setOrigin(tab[id].spr, (sfVector2f){19, 21});
}

void write_help(void)
{
    write(1, "Duck Hunt Remake.\n", 18);
    write(1, "You can select the windows size and the fps.\n", 45);
    write(1, "./my_hunter windows x, windows y, fps\n", 39);
    write(1, "Or launch without parameters to play in 1152x960 and 42fps\n",
        59);
}

void miss(obj_t *tab, int *score)
{
    tab[4].index = 0;
    tab[4].index2 = 0;
    score[tab[5].index2] = -1;
    tab[5].index2 = tab[5].index2 + 1;
    tab[6].index2 = tab[6].index2 + 36;
    tab[5].coord.x = tab[5].coord.x + tab[6].index2;
    tab[8].index2 = 1;
}

void draw_text(const char *str, sfVector2f coord, int size,
    sfRenderWindow *window)
{
    sfFont *font = sfFont_createFromFile("sprites/duck.ttf");
    sfText *text = sfText_create();
    sfText_setCharacterSize(text, size);
    sfText_setFont(text, font);
    sfText_setPosition(text, coord);
    sfText_setColor(text, sfWhite);
    sfText_setStyle(text, sfTextBold);
    sfText_setString(text, str);
    sfRenderWindow_drawText(window, text, NULL);
}

void draw_stage(obj_t *tab, sfRenderWindow *window)
{
    if (tab[4].move.x == 0)
        draw_text("stage  1", (sfVector2f){500, 930}, 25, window);
    if (tab[4].move.x == 1)
        draw_text("stage  2", (sfVector2f){500, 930}, 25, window);
    if (tab[4].move.x == 2)
        draw_text("stage  3", (sfVector2f){500, 930}, 25, window);
}