/*
** EPITECH PROJECT, 2018
** number
** File description:
** number gestion
*/

#include "my_hunter.h"

int nbrlen(int cpy)
{
    int len = 0;

    while (cpy > 0) {
        cpy = cpy / 10;
        len++;
    }
    return (len);
}

unsigned int randr(unsigned int min, unsigned int max)
{
    unsigned int r = max - min;

    srand(time(0));
    r = rand() % (max - min) + min;
    return (r);
}

int my_getnbr(char *str)
{
    int nbr = 0;
    int neg = 1;
    int i = 0;

    if (str[i] == '-') {
        neg = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        nbr = nbr * 10;
        nbr = nbr + (str[i] - '0');
        i++;
    }
    return (nbr * neg);
}

int count_fail(int *tab)
{
    int i = 0;
    int nbr = 0;

    while (i < 10)
    {
        if (tab[i] == -1)
            nbr++;
        i++;
    }
    return (nbr);
}

void fill_zero(int *tab)
{
    int i = 0;

    while (i < 10)
    {
        tab[i] = 0;
        i++;
    }
}