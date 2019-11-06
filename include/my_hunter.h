/*
** EPITECH PROJECT, 2018
** my_hunter.h
** File description:
** my_hunter
*/

#ifndef MY_HUNTER_H
#define MY_HUNTER_H

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

typedef unsigned int uint;

typedef struct obj_s
{
    sfVector2f coord;
    sfVector2f move;
    sfTexture *txt;
    sfSprite *spr;
    sfClock *clock;
    sfTime time;
    sfMusic *music;
    float seconds;
    int index;
    int index2;
} obj_t;

obj_t *struct_tab(void);
void init_duck(obj_t *tab, int id);
void write_help(void);
int my_getnbr(char *str);
void duck_texture_angle(obj_t *tab, unsigned int skin, int id);
unsigned int randr(unsigned int min, unsigned int max);
obj_t struct_fill(float x, float y, const char *file, const char *sound);
void update_texture(obj_t *tab, sfRenderWindow *window);
void draw_cursor(obj_t *tab, sfRenderWindow *window);
obj_t back_scale(const char *file, const char *sound,
    sfVector2f coord, sfVector2f sc);
void move_rect(sfIntRect *rect, sfVector2i xmax_yidi , float speed, obj_t *tab);
obj_t *struct_tab(void);
int nbrlen(int cpy);
int count_fail(int *tab);
void fill_zero(int *tab);
void draw_stage(obj_t *tab, sfRenderWindow *window);
void draw_text(const char *str, sfVector2f coord, int size, sfRenderWindow *window);
void miss(obj_t *tab, int *score);
void draw_duck(obj_t *tab, sfRenderWindow *window, int id);
void duck_direction(obj_t *tab, int id, unsigned int skin);
void click(obj_t *tab);
void draw_ammo(obj_t *tab, sfRenderWindow *window);
void draw_score(obj_t *tab, int *score, sfRenderWindow *window);
void got_one_dog(obj_t *tab, sfRenderWindow *window, int id);
void miss_one(obj_t *tab, sfRenderWindow *window);
void intro(sfRenderWindow *window, obj_t *tab);
void destroy_struct(obj_t *tab, sfRenderWindow *window);
void duckfall_texture(obj_t *tab, unsigned int skin, int id);
void duckshot_texture(obj_t *tab, unsigned int skin, int id);
void duck_texture(obj_t *tab, unsigned int skin, int id);
void point(obj_t *tab, sfRenderWindow *window);
int stage(obj_t *tab, int *score, sfRenderWindow *window);


#endif