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

    printf("egg id = %i\n", egg->idx);
    SLIST_FOREACH(tmp, &z->server->clients, next)
    {
        if (tmp->type == GRAPHICAL) {
            add_data(&tmp->out, 2, "ebo", int_to_char(egg->idx));
        }
    }
    return (SUCCESS);
}