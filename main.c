/*
** EPITECH PROJECT, 2018
** bootstrap_my_hunter
** File description:
** bootstrap_my_hunter
*/

#include "my_hunter.h"

sfRenderWindow *window_create(int width, int height)
{
    sfRenderWindow *window;
    sfVideoMode window_mode;

    window_mode.width = width;
    window_mode.height = height;
    window_mode.bitsPerPixel = 64;
    window = sfRenderWindow_create(window_mode,
        "window", sfDefaultStyle, NULL);
    return (window);
}

void analyse_events(sfRenderWindow *window)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(window);
    }
}

void draw_call(sfRenderWindow *window, obj_t *tab, int *score)
{
    sfRenderWindow_drawSprite(window, tab[1].spr, NULL);
    draw_duck(tab, window, 3);
    if (tab[4].move.x >= 1)
        draw_duck(tab, window, 12);
    if (tab[4].move.x == 2)
        draw_duck(tab, window, 13);
    click(tab);
    sfRenderWindow_drawSprite(window, tab[2].spr, NULL);
    draw_ammo(tab, window);
    draw_score(tab, score, window);
    point(tab, window);
    draw_cursor(tab, window);
    stage(tab, score, window);
}

int help(int argc, char **argv, sfRenderWindow *window)
{
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        write_help();
        return (84);
    }
    if (argc == 1) {
        sfRenderWindow_setFramerateLimit(window, 42);
        return (0);
    }
    if (argc == 4) {
        if (my_getnbr(argv[1]) < 800 || my_getnbr(argv[1]) > 1920 ||
            my_getnbr(argv[2]) < 600 || my_getnbr(argv[2]) > 1080)
            return (84);
        sfRenderWindow_setSize(window, (sfVector2u){my_getnbr(argv[1]),
            my_getnbr(argv[2])});
        sfRenderWindow_setFramerateLimit(window, my_getnbr(argv[3]));
        return (0);
    }
    return (84);
}

int main(int argc, char **argv)
{
    sfRenderWindow *window = window_create(1152, 960);
    obj_t *tab = struct_tab();
    int score[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    if (help(argc, argv, window) == 84)
        return (84);
    while (sfRenderWindow_isOpen(window)) {
        if (tab[10].index2 == 0)
            intro(window, tab);
        else {
            draw_call(window, tab, score);
        }
        analyse_events(window);
        sfRenderWindow_display(window);
    }
    destroy_struct(tab, window);
    return (0);
}