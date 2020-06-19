/*
** EPITECH PROJECT, 2020
** Zappy
** File description:
** lpi
*/

#include "server.h"

void add_client_info(flux_t *flux, client_t *tmp)
{
    char nb[12] = {0};

    sprintf(nb, "%i", ((c_data_t *)tmp->data)->idx);
    add_raw_data(flux, " ");
    add_raw_data(flux, nb);
    sprintf(nb, "%i", ((c_data_t *)tmp->data)->pos.x);
    add_raw_data(flux, " ");
    add_raw_data(flux, nb);
    sprintf(nb, "%i", ((c_data_t *)tmp->data)->pos.y);
    add_raw_data(flux, " ");
    add_raw_data(flux, nb);
    sprintf(nb, "%i", ((c_data_t *)tmp->data)->dir);
    add_raw_data(flux, " ");
    add_raw_data(flux, nb);
    add_raw_data(flux, " ");
    add_raw_data(flux, ((c_data_t *)tmp->data)->team);
    add_raw_data(flux, ",");
}

void add_clients_info(flux_t *flux, server_t *server)
{
    client_t *tmp;

    SLIST_FOREACH(tmp, &server->clients, next)
    {
        if (tmp->type == AI) {
            add_client_info(flux, tmp);
        }
    }
}

bool end_lpi(zappy_data_t *z, client_t *client, char *command)
{
    (void)z;
    (void)client;
    (void)command;
    return (SUCCESS);
}

bool start_lpi(zappy_data_t *z, client_t *client, char *arg)
{
    (void)arg;
    add_raw_data(&client->out, "lpi");
    add_clients_info(&client->out, z->server);
    add_raw_data(&client->out, "\r\n");
    return (SUCCESS);
}
