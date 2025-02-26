/*
** EPITECH PROJECT, 2020
** Zappy
** File description:
** pbc
*/

#include "server.h"

void pbc(server_t *server, client_t *client, char *message)
{
    client_t *tmp;
    char nb[12] = {0};

    sprintf(nb, "%i", ((c_data_t *)client->data)->idx);
    SLIST_FOREACH(tmp, &server->clients, next)
    {
        if (tmp->type == GRAPHICAL)
            add_data(&tmp->out, 3, "pbc", nb, message);
    }
}