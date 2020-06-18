/*
** EPITECH PROJECT, 2020
** Zappy
** File description:
** pic
*/

#include "server.h"

void add_concenred_ai_idx(flux_t *flux, server_t *server, client_t *client)
{
    client_t *tmp;
    char nb[12] = {0};

    add_raw_data(flux, " ");
    sprintf(nb, "%i", ((c_data_t *)client->data)->idx);
    add_raw_data(flux, nb);
    SLIST_FOREACH(tmp, &server->clients, next)
    {
        if (tmp->type == AI && tmp != client) {
            add_raw_data(flux, " ");
            sprintf(nb, "%i", ((c_data_t *)tmp->data)->idx);
            add_raw_data(flux, nb);
        }
    }
    add_raw_data(flux, "\r\n");
}

void pic(server_t *server, client_t *client)
{
    client_t *tmp;
    char nb[12] = {0};

    SLIST_FOREACH(tmp, &server->clients, next)
    {
        if (tmp->type == GRAPHICAL) {
            add_raw_data(&tmp->out, "pic");
            sprintf(nb, "%i", ((c_data_t *)client->data)->pos.x);
            add_raw_data(&tmp->out, " ");
            add_raw_data(&tmp->out, nb);
            sprintf(nb, "%i", ((c_data_t *)client->data)->pos.y);
            add_raw_data(&tmp->out, " ");
            add_raw_data(&tmp->out, nb);
            sprintf(nb, "%i", ((c_data_t *)client->data)->level + 1);
            add_raw_data(&tmp->out, " ");
            add_raw_data(&tmp->out, nb);
            add_raw_data(&tmp->out, " ");
            add_concenred_ai_idx(&tmp->out, server, client);
        }
    }
}