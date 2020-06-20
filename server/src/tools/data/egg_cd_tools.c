/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** egg_cd_tools
*/

#include "server.h"

float get_lowest_egg_cd(zappy_data_t *z)
{
    egg_t *tmp;
    int cd = 1260.0 / z->data.f;
    int nb = 0;

    SLIST_FOREACH(tmp, &z->data.eggs, next)
    {
        nb++;
        if (tmp->status > HATCHED && tmp->status < cd)
            cd = tmp->status;
        else if (tmp->status < HATCHED &&
            1260.0 / z->data.f - tmp->status < cd)
            cd = 1260.0 / z->data.f - tmp->status;
    }
    return (nb? cd : -1);
}