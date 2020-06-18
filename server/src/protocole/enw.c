/*
** EPITECH PROJECT, 2020
** Zappy
** File description:
** enw
*/

#include "server.h"

void enw(server_t *server, client_t *client, egg_t *egg)
{
    client_t *tmp;
    char clt_idx[12] = {0};
    char egg_idx[12] = {0};
    char x[12] = {0};
    char y[12] = {0};

    sprintf(clt_idx, "%i", ((c_data_t *)client->data)->idx);
    sprintf(egg_idx, "%i", egg->idx);
    sprintf(x, "%i", ((c_data_t *)client->data)->pos.x);
    sprintf(y, "%i", ((c_data_t *)client->data)->pos.y);
    SLIST_FOREACH(tmp, &server->clients, next)
    {
        if (tmp->type == GRAPHICAL)
            add_data(&tmp->out, 5 ,"enw", egg_idx, clt_idx, x, y);
    }
}