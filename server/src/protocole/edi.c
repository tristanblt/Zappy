/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** edi - death of an hatched egg
*/

#include "server.h"

bool edi(zappy_data_t *z, egg_t *egg)
{
    client_t *tmp;
    SLIST_FOREACH(tmp, &z->server->clients, next)
    {
        if (tmp->type == GRAPHICAL) {
            add_data(&tmp->out, 1, "edi", egg);
        }
    }
    return (SUCCESS);
}