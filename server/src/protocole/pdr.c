/*
** EPITECH PROJECT, 2020
** Zappy
** File description:
** pdr
*/

#include "server.h"

void pdr(server_t *server, client_t *client, char *ressource)
{
    client_t *tmp;
    char idx[12] = {0};
    char res[12] = {0};

    sprintf(idx, "%i", ((c_data_t *)client->data)->idx);
    sprintf(res, "%i", get_ressource_number(ressource));
    SLIST_FOREACH(tmp, &server->clients, next)
    {
        if (tmp->type == GRAPHICAL)
            add_data(&tmp->out, 3, "pdr", idx, res);
    }
}