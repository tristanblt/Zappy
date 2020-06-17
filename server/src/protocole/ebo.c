/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** ebo - player connection for an egg
*/

#include "server.h"

bool ebo(zappy_data_t *z, egg_t *egg)
{
    client_t *tmp;
    SLIST_FOREACH(tmp, &z->server->clients, next)
    {
        if (tmp->type == GRAPHICAL) {
            add_data(&tmp->out, 1, "ebo", egg);
        }
    }
    return (SUCCESS);
}