/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** plv - player's level
*/

#include "server.h"

bool start_plv(zappy_data_t *z, client_t *client, char *arg)
{
    client_t *tmp;

    ((c_data_t *)client->data)->cool_down = 0 / z->data.f;
    SLIST_FOREACH(tmp, &z->server->clients, next)
    {
        if (((c_data_t *)tmp->data)->idx == atoi(arg)) {
            add_data(&client->out, 3, "plv",
            int_to_char(((c_data_t *)tmp->data)->idx),
            int_to_char(((c_data_t *)tmp->data)->level));
        }
    }
    return (SUCCESS);
}

bool end_plv(zappy_data_t *z, client_t *client, char *arg)
{
    (void)*z;
    (void)*client;
    (void)arg;
    return (SUCCESS);
}