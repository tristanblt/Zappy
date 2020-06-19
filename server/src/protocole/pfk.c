/*
** EPITECH PROJECT, 2020
** Zappy
** File description:
** pfk
*/

#include "server.h"

void pfk(server_t *server, client_t *client)
{
    client_t *tmp;
    char nb[12] = {0};

    sprintf(nb, "%i", ((c_data_t *)client->data)->idx);
    SLIST_FOREACH(tmp, &server->clients, next)
    {
        if (tmp->type == GRAPHICAL)
            add_data(&tmp->out, 2, "pfk", nb);
    }
}