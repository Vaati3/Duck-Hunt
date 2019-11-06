/*
** EPITECH PROJECT, 2018
** struct
** File description:
** structure gestion
*/

#include "my_hunter.h"

obj_t struct_fill(float x, float y, const char *file, const char *sound)
{
    obj_t obj;

    obj.coord.x = x;
    obj.coord.y = y;
    obj.move.x = 0;
    obj.move.y = 0;
    obj.txt = sfTexture_create(1152, 960);
    obj.spr = sfSprite_create();
    obj.music = sfMusic_createFromFile(sound);
    obj.txt = sfTexture_createFromFile(file, NULL);
    sfSprite_setTexture(obj.spr, obj.txt, sfTrue);
    obj.clock = sfClock_create();
    obj.seconds = 0;
    obj.index = 0;
    obj.index2 = 0;
    return (obj);
}

obj_t back_scale(const char *file, const char *music,
    sfVector2f coord, sfVector2f sc)
{
    obj_t obj = struct_fill(coord.x, coord.y, file, music);

    sfSprite_scale(obj.spr , sc);
    return (obj);
}

obj_t *struct_tab2(obj_t *tab)
{
    tab[9] = back_scale("sprites/perfectdog.png", "sounds/Perfect.ogg",
        (sfVector2f){462, 525}, (sfVector2f){3, 3});
    tab[10] = back_scale("sprites/doge.png", "sounds/Duck_Hunt_Intro.ogg",
        (sfVector2f){-175, 635}, (sfVector2f){3, 3});
    tab[11] = back_scale("sprites/duck1.png", "sounds/Duck_Flapping.ogg",
        (sfVector2f){0, 80}, (sfVector2f){2, 2});
    tab[12] = back_scale("sprites/duck2.png", "sounds/Duck_Flapping.ogg",
        (sfVector2f){500, 650}, (sfVector2f){2, 2});
    tab[13] = back_scale("sprites/duck3.png", "sounds/Duck_Flapping.ogg",
        (sfVector2f){0, 80}, (sfVector2f){2, 2});
    init_duck(tab, 3);
    init_duck(tab, 12);
    init_duck(tab, 13);
    return (tab);
}

obj_t *struct_tab(void)
{
    obj_t *tab = malloc(sizeof(obj_t) * 14);

    tab[0] = struct_fill(0, 0, "sprites/cursor.png", "sounds/Gunshot.ogg");
    tab[1] = back_scale("sprites/back.png", "sounds/Dead_Duck_Falls.ogg",
        (sfVector2f){0, 0}, (sfVector2f){4.5, 4});
    tab[2] = back_scale("sprites/grass.png", "sounds/Game_Over.ogg",
        (sfVector2f){0, 0}, (sfVector2f){4.5, 4});
    tab[3] = back_scale("sprites/duck1.png", "sounds/Duck_Flapping.ogg",
        (sfVector2f){400, 650}, (sfVector2f){2, 2});
    tab[4] = back_scale("sprites/ammo.png", "sounds/Dead_Duck_Lands.ogg",
        (sfVector2f){103.5, 827}, (sfVector2f){4.5, 4});
    tab[5] = back_scale("sprites/score.png", "sounds/Quack.ogg",
        (sfVector2f){427, 845}, (sfVector2f){4.5, 4});
    tab[6] = back_scale("sprites/hit.png", "sounds/Bark.ogg",
        (sfVector2f){427, 845}, (sfVector2f){4.5, 4});
    tab[7] = back_scale("sprites/doget.png", "sounds/Got_Duck.ogg",
        (sfVector2f){462, 550}, (sfVector2f){3, 3});
    tab[8] = back_scale("sprites/loldog.png", "sounds/Laugh.ogg",
        (sfVector2f){462, 550}, (sfVector2f){3, 3});
    return (struct_tab2(tab));
}

void destroy_struct(obj_t *tab, sfRenderWindow *window)
{
    int i = 0;

    sfRenderWindow_destroy(window);
    while (i < 11) {
        sfTexture_destroy(tab[i].txt);
        sfSprite_destroy(tab[i].spr);
        sfClock_destroy(tab[i].clock);
        sfMusic_destroy(tab[i].music);
        i++;
    }
    free(tab);
}