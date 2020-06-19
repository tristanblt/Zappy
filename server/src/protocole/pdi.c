/*
** EPITECH PROJECT, 2020
** Zappy
** File description:
** pdi
*/

#include "server.h"

void pdi(server_t *server, client_t *client)
{
    client_t *tmp;
    char idx[12] = {0};

    sprintf(idx, "%i", ((c_data_t *)client->data)->idx);
    SLIST_FOREACH(tmp, &server->clients, next)
    {
        if (tmp->type == GRAPHICAL)
            add_data(&tmp->out, 2, "pdi", idx);
    }
}