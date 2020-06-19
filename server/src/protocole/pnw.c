/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** pnw - connection of a new player
*/

#include "server.h"

bool pnw(zappy_data_t *z, client_t *client)
{
    printf("PNW CALLED\n");
    client_t *tmp;

    SLIST_FOREACH(tmp, &z->server->clients, next)
    {
        if (tmp->type == GRAPHICAL) {
            printf("pnw sent to a graphical\n");
            add_data(&tmp->out, 7, "pnw",
            int_to_char(((c_data_t *)client->data)->idx),
            int_to_char(((c_data_t *)client->data)->pos.x),
            int_to_char(((c_data_t *)client->data)->pos.y),
            int_to_char(((c_data_t *)client->data)->dir),
            int_to_char(((c_data_t *)client->data)->level),
            ((c_data_t *)client->data)->team);
        }
    }
    return (SUCCESS);
}