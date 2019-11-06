/*
** EPITECH PROJECT, 2018
** draw
** File description:
** draw
*/

#include "my_hunter.h"

void draw_cursor(obj_t *tab, sfRenderWindow *window)
{
    sfVector2i mouse = sfMouse_getPosition((sfWindow*)window);

    tab[0].coord.x = mouse.x;
    tab[0].coord.y = mouse.y;
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfSprite_setOrigin(tab[0].spr, (sfVector2f){13.5, 12.5});
    sfSprite_setPosition(tab[0].spr, tab[0].coord);
    sfRenderWindow_drawSprite(window, tab[0].spr, NULL);
}

void move_rect(sfIntRect *rect, sfVector2i xmax_yid , float speed, obj_t *tab)
{
    int offset = rect->width;

    tab[xmax_yid.y].time = sfClock_getElapsedTime(tab[xmax_yid.y].clock);
    tab[xmax_yid.y].seconds = tab[xmax_yid.y].time.microseconds / 1000000.0;
    if (tab[xmax_yid.y].seconds > speed)
    {
        if (tab[xmax_yid.y].index < xmax_yid.x - offset * 2)
            tab[xmax_yid.y].index = tab[xmax_yid.y].index + offset;
        else
            tab[xmax_yid.y].index = 0;
        sfClock_restart(tab[xmax_yid.y].clock);
    }
    rect->left = tab[xmax_yid.y].index;
}

void click_hit(obj_t *tab)
{
    if ((tab[0].coord.x > tab[3].coord.x - 38  && tab[0].coord.x <
        tab[3].coord.x + 38) && (tab[0].coord.y > tab[3].coord.y - 42
        && tab[0].coord.y < tab[3].coord.y + 42)) {
        duckshot_texture(tab, tab[3 - 2].move.x, 3);
        tab[0].index = 1;
    }
    if ((tab[0].coord.x > tab[12].coord.x - 38  && tab[0].coord.x <
        tab[12].coord.x + 38) && (tab[0].coord.y > tab[12].coord.y - 42
        && tab[0].coord.y < tab[12].coord.y + 42)) {
        duckshot_texture(tab, tab[12 - 2].move.x, 12);
        tab[0].move.x = 1;
    }
    if ((tab[0].coord.x > tab[13].coord.x - 38  && tab[0].coord.x <
        tab[13].coord.x + 38) && (tab[0].coord.y > tab[13].coord.y - 42
        && tab[0].coord.y < tab[13].coord.y + 42)) {
        duckshot_texture(tab, tab[13 - 2].move.x, 13);
        tab[0].move.y = 1;
    }
    tab[4].index2 = 1;
}

void click(obj_t *tab)
{
    tab[0].time = sfClock_getElapsedTime(tab[0].clock);
    tab[0].seconds = tab[0].time.microseconds / 1000000.0;
    if (sfMouse_isButtonPressed(sfMouseLeft) && tab[0].seconds > 0.5
        && tab[4].index < 3) {
        sfMusic_play(tab[0].music);
        click_hit(tab);
        tab[4].index = tab[4].index + 1;
        sfClock_restart(tab[0].clock);
    }
}

int stage(obj_t *tab, int *score, sfRenderWindow *window)
{
    int fail = count_fail(score);

    if (score[9] == 1 || score[9] == -1)
    {
        if ((tab[4].move.x == 0 && fail > 3) || (tab[4].move.x == 1
            && fail > 2) || tab[4].move.x == 2 && fail > 1) {
                draw_text("Game Over!", (sfVector2f){300, 400}, 75, window);
                tab[4].index = 3;
        } else {
            tab[5].move.x = (fail == 0 ? tab[5].move.x + 1000 : tab[5].move.x);
            if (tab[4].move.x != 2)
                tab[4].move.x = tab[4].move.x + 1;
            fill_zero(score);
            tab[6].coord.x = 0;
            tab[5].index2 = 0;
            tab[6].index2 = 0;
            tab[5].coord.x = 427;
        }
    }
    draw_stage(tab, window);
}