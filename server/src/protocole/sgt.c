/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** sgt - time unit request
*/

#include "server.h"

bool start_sgt(zappy_data_t *z, client_t *client, char *arg)
{
    (void)client;
    (void)arg;
    client_t *tmp;
    ((c_data_t *)client->data)->cool_down = 0 / z->data.f;
    SLIST_FOREACH(tmp, &z->server->clients, next)
    {
        if (tmp->type == GRAPHICAL) {
            add_data(&tmp->out, 2, "sgt", int_to_char(z->data.f));
        }
    }
    return (SUCCESS);
}

bool end_sgt(zappy_data_t *z, client_t *client, char *arg)
{
    (void)z;
    (void)client;
    (void)arg;
    return (SUCCESS);
}
