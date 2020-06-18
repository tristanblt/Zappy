/*
** EPITECH PROJECT, 2020
** Zappy
** File description:
** pie
*/

#include "server.h"

void pie(server_t *server, client_t *client, bool result)
{
    client_t *tmp;
    char nb[12] = {0};

    SLIST_FOREACH(tmp, &server->clients, next)
    {
        if (tmp->type == GRAPHICAL) {
            add_raw_data(&tmp->out, "pie");
            sprintf(nb, "%i", ((c_data_t *)client->data)->pos.x);
            add_raw_data(&tmp->out, " ");
            add_raw_data(&tmp->out, nb);
            sprintf(nb, "%i", ((c_data_t *)client->data)->pos.y);
            add_raw_data(&tmp->out, " ");
            add_raw_data(&tmp->out, nb);
            sprintf(nb, "%i", (int)result);
            add_raw_data(&tmp->out, "\r\n");
        }
    }
}